#include "include/libtcod.hpp"
#include "Actor.hpp"
#include "Map.hpp"
#include "Engine.hpp" // depends on three previous headers for
                      // TCODList, Actor, and Map
// constructor
//
Engine::Engine()
{
    TCODConsole::initRoot(80, 50, "libtcod C++ tut", false);
    player = new Actor(40, 25, '@', TCODColor::white);
    actors.push(player);
    actors.push(new Actor(60, 13, '@', TCODColor::yellow));
    map = new Map(80, 45);
}

// desctructor
Engine::~Engine()
{
    actors.clearAndDelete();
    delete map;

}

// handles player walking code
void Engine::update() {
   TCOD_key_t key;
   TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
   switch(key.vk) {
       case TCODK_UP :
           if ( ! map->isWall(player->x,player->y-1)) {
               player->y--;
           }
       break;
       case TCODK_DOWN :
           if ( ! map->isWall(player->x,player->y+1)) {
               player->y++;
           }
       break;
       case TCODK_LEFT :
           if ( ! map->isWall(player->x-1,player->y)) {
               player->x--;
           }
       break;
       case TCODK_RIGHT :
           if ( ! map->isWall(player->x+1,player->y)) {
               player->x++;
           }
       break;
       default:break;
   }
}

// clears console then redraws the map
void Engine::render()
{
    TCODConsole::root->clear();
    map->render();
    // draw actors
    // TCODList begin functio returns a pointer to first elem
    // and our elements are already Actor pointers
    // so, we get a pointer to a pointer to an Actor or Actor**
    for (Actor **iterator = actors.begin();
            iterator != actors.end(); iterator++)
    {
        // indirection operator to retrieve object behind pointer
        (*iterator)->render();
        // -> dereference operator used to access a member on the
        // pointed object or actual Actor
    }
}
