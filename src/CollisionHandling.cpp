#include "CollisionHandling.h"
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include <memory>
#include "Player.h"
#include "Pool.h"
#include "SizeChangerAdd.h"
#include "SizeChangerLess.h"
#include "SizeChangerDivide.h"
#include "SizeChangerDouble.h"
#include "Magnet.h"
#include "Heart.h"
#include "Fence.h"
#include "Coin.h"
#include "Bomb.h"
#include "Boat.h"
#include "Spaceship.h"
#include "SuperPower.h"
#include "Level.h"
#include "MoveToSpecificPos.h"
#include "CrossingPoolState.h"
#include "IsFinish.h"
#include "FinishLine.h"
//-----------------------------------------------------
namespace 
{
    //----------------------colide with pool--------------------
    void poolCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);

        // cheak if the player has super power
        if (!player.isHasSuperPower())
        {
            Pool& pool = dynamic_cast<Pool&>(object); 

            // if the player is tall enough - he can cross the pool without drowning!
            if (player.isTallEnough(60))
            {
                // change player state to crossing pool state (and send swim pic)
                player.changeState(std::make_unique< CrossingPoolState>(IN_POOL, pool.getPic()));
                //play water sound
                ResourceManeger::getResourceManeger().playCollisionSound(POOLSOUND);
            }

            // if the player has a boat - he can cross the pool with it!
            else if (player.isHasBoat())
            {
                // take the boat 
                player.setBoatMode(false);
                // change player state to crossing pool state (and send boad pic)
                player.changeState(std::make_unique< CrossingPoolState>(SIT_ON_BOAT, pool.getPic()));
                //play water sound
                ResourceManeger::getResourceManeger().playCollisionSound(POOLSOUND);
            }
            else
            {
                // the pool can disappear
                pool.changeIsFinish(std::make_unique<IsFinishShowAnimation>(pool.getAnimation()));
                // the player drowning...
                player.lessLive();
            }
        }
    }
    //----------------------colide with size changer--------------------------
    void sizeChangerCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);
        SizeChanger& sizeChanger= dynamic_cast<SizeChanger&>(object); 

        //player colide sound
        ResourceManeger::getResourceManeger().playCollisionSound(CHANGESIZESOUND);

        // calcullate the new size of player and change him
        sizeChanger.calculateNewSize(player);

        // the sizeChanger can disappear
        sizeChanger.changeIsFinish(std::make_unique<IsFinishShowAnimation>(sizeChanger.getAnimation()));

    }
    //-----------------------colide with less size------------------------------------
    void sizeChangerLessCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);
        // cheak if the player has super power
        if(!player.isHasSuperPower())
             sizeChangerCollision(player, object);
    }
    //------------------ colide with magnet------------------------
    void magnetCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);
        Magnet& magnet = dynamic_cast<Magnet&>(object);
        // play sound
        ResourceManeger::getResourceManeger().playCollisionSound(TAKEOBJECT);

        // give the player magnet
        player.setMagnetMode();

        // the magnet can disappear
        magnet.changeIsFinish(std::make_unique<IsFinishShowAnimation>(magnet.getAnimation()));
    }
    //------------------- colide with heart----------------------
    void heartCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);
        Heart& heart = dynamic_cast<Heart&>(object);

        // play sound
        ResourceManeger::getResourceManeger().playCollisionSound(HEARTSOUND);
       
        //add life
        player.addLive();

        //set origion
        heart.getPic().setOrigin(sf::Vector2f{ float(heart.getPic().getTextureRect().width / 2),float(heart.getPic().getTextureRect().height) });
        // change move behavior to move to the information display
        heart.changeMoveBehavior(std::make_unique< MoveToSpecificPos>(sf::Vector2f{ 300,0 }, heart.getPic()));
        // change the cause of finish 
        heart.changeIsFinish(std::make_unique<IsGetToLocation>(heart.getPic(), 50, [](float a, float b) { return a <= b; }));
    }
    //---------------------colide with fence------------------------
    void fenceCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);

        //check if the player has superpower
        if (!player.isHasSuperPower())
        {
            Fence& fence = dynamic_cast<Fence&>(object);

            //play sound
            ResourceManeger::getResourceManeger().playCollisionSound(CHANGESIZESOUND);
            //less hieght to the player
            player.changeSize(-10);
            // change the cause of finish 
            fence.changeIsFinish(std::make_unique<IsFinishShowAnimation>(fence.getAnimation()));
        }
    }
    //---------------------colide with coin----------------------
    void coinCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);
        Coin& coin = dynamic_cast<Coin&>(object); 
        // play sound
        ResourceManeger::getResourceManeger().playCollisionSound(COINSOUND);
        
        // add coin to counter of collected coins
        player.addCoin();
        // set origion
        coin.getPic().setOrigin(sf::Vector2f{ float(coin.getPic().getTextureRect().width / 2),float(coin.getPic().getTextureRect().height) });
        // change move behavior to move to information board
        coin.changeMoveBehavior(std::make_unique< MoveToSpecificPos>(sf::Vector2f{ 50,0 },coin.getPic()));
        // change the cause of finish 
        coin.changeIsFinish(std::make_unique<IsGetToLocation>(coin.getPic(), 50, [](float a, float b) { return a <= b; }));
    }
    //--------------------colide with bomb--------------------
    void bombCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);
        if (!player.isHasSuperPower())
        {
            Bomb& bomb = dynamic_cast<Bomb&>(object);
            // play sound
            ResourceManeger::getResourceManeger().playCollisionSound(BOMBSOUND);
   
            // animation of explosion
            bomb.getAnimation().changeAnimation(sf::Vector2i(4, 1));
            // less live
            player.lessLive();
            // change the cause of finish
            bomb.changeIsFinish(std::make_unique<IsFinishShowAnimation>(bomb.getAnimation()));
        }
    }
    //-----------------------colide with boat-------------------------------
    void boatCollision(Object& play, Object& object)
    {

        Player& player = dynamic_cast<Player&>(play);
        Boat& boat = dynamic_cast<Boat&>(object);
        //play sound
        ResourceManeger::getResourceManeger().playCollisionSound(BOATSOUND);
        // add boat to the player
        player.setBoatMode(true);
        //set origion
        boat.getPic().setOrigin({ float(boat.getPic().getTextureRect().left) ,float(boat.getPic().getTextureRect().top) });
        //change move behavior to move to info board
        boat.changeMoveBehavior(std::make_unique< MoveToSpecificPos>(sf::Vector2f{ 500,0 }, boat.getPic()));
        // change the cause of finish
        boat.changeIsFinish(std::make_unique<IsGetToLocation>(boat.getPic(), 50, [](float a, float b) { return a <= b; }));

    }
    //------------------colide with shoot ball------------------------------------
    void SpaceshipShootCollision(Object& play, Object& object)
    {
        Spaceship& spaceship = dynamic_cast<Spaceship&>(object);
        Player& player = dynamic_cast<Player&>(play);

        //play sound
        ResourceManeger::getResourceManeger().playCollisionSound(BOMBSOUND);
        
        //check if the player has super power- if not less live
        if (!player.isHasSuperPower())
            player.lessLive();
       
        //change anima to explosion
        spaceship.getShoot().getAnimation().changeAnimation(sf::Vector2i(4, 1));
        //change finish cause
        spaceship.getShoot().changeIsFinish(std::make_unique<IsFinishShowAnimation>(spaceship.getAnimation()));
    }
    //-------------colide with super power ball-----------------------------------------
    void SuperPowerCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);
        SuperPower& super = dynamic_cast<SuperPower&>(object);
        // play sound
        ResourceManeger::getResourceManeger().playCollisionSound(TAKEOBJECT);
        
        // give the player super power
        player.setSuperPowerMode();
        //change finish cause
        super.changeIsFinish(std::make_unique<IsFinishShowAnimation>(super.getAnimation()));
    }
    //----------------------colide with finish line-----------------------------------------------
    void FinishLineCollision(Object& play, Object& object)
    {
        Player& player = dynamic_cast<Player&>(play);
        player.GetToFinishLine();
        //סאונד ניצחון 
       // ResourceManeger::getResourceManeger().playCollisionSound(LESSLIVESOUND);

    }
   // ======================================================================================
    using CollisionFunctionPtr = void (*)(Object& obj1, Object& obj2);
    using Key = std::pair<std::type_index, std::type_index>;
    using CollisionMap = std::map<Key, CollisionFunctionPtr>;
   
    //======================================================================================
    //a mup of 2 objects type and colide function that handle ciliision of them
    CollisionMap initializeCollisionMap()
    {
        CollisionMap collisionMap;
        collisionMap[Key(typeid(Player),typeid(Pool))] = &poolCollision;
        collisionMap[Key(typeid(Player), typeid(SuperPower))] = &SuperPowerCollision;
        collisionMap[Key(typeid(Player), typeid(SizeChangerAdd))] = &sizeChangerCollision;
        collisionMap[Key(typeid(Player), typeid(SizeChangerLess))] = &sizeChangerLessCollision;
        collisionMap[Key(typeid(Player), typeid(SizeChangerDivide))] = &sizeChangerLessCollision;
        collisionMap[Key(typeid(Player), typeid(SizeChangerDouble))] = &sizeChangerCollision;
        collisionMap[Key(typeid(Player), typeid(Magnet))] = &magnetCollision;
        collisionMap[Key(typeid(Player), typeid(Heart))] = &heartCollision;
        collisionMap[Key(typeid(Player), typeid(Fence))] = &fenceCollision;
        collisionMap[Key(typeid(Player), typeid(Coin))] = &coinCollision;
        collisionMap[Key(typeid(Player), typeid(Bomb))] = &bombCollision;
        collisionMap[Key(typeid(Player), typeid(Boat))] = &boatCollision;
        collisionMap[Key(typeid(Player), typeid(Spaceship))] = &SpaceshipShootCollision;
        collisionMap[Key(typeid(Player), typeid(FinishLine))] = &FinishLineCollision;
        return collisionMap;
    }
    //------------------------------------------------
    CollisionFunctionPtr lookup(const std::type_index& object1,const std::type_index& object2)
    {
        // fill mup
        static CollisionMap collisionMap = initializeCollisionMap();
        // look for the corects pair of types
        auto mapEntry = collisionMap.find(std::make_pair(object1,object2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        // return the colide function
        return mapEntry->second;
    }
}
//============================end namespace====================
void processCollision(Object& obj1, Object& obj2)
{
    auto collision = lookup( typeid(obj1),typeid(obj2));

    // colide function not exiset
    if (!collision)
         throw ("Colision function not exists");
    //process the collision
    collision(obj1, obj2);
}
