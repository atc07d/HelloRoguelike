#include "include/libtcod.hpp"
#include "Actor.hpp"

// constructor using initialization list to define value of class members
Actor::Actor(int x, int y, int ch, const TCODColor &col) :
    x(x), y(y), ch(ch), col(col)
{

}
// uses console methods to set ascii code
// and foreground color on root console
// leaving background color unmodified
void Actor::render() const
{
    TCODConsole::root->setChar(x, y, ch);
    TCODConsole::root->setCharForeground(x, y, col);
}
