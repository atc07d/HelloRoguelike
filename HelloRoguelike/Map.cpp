#include "include/libtcod.hpp"
#include "Map.hpp"

Map::Map(int width, int height) : width(width), height(height)
{
    tiles = new Tile[width * height]; // size of array is w * h
    setWall(30, 22);
    setWall(50, 22);
}

Map::~Map()
{
    delete [] tiles;
}

bool Map::isWall(int x, int y) const
{
    return !tiles[x + y * width].canWalk;
}

void Map::setWall(int x, int y)
{
    tiles[x + y * width].canWalk = false;
}

void Map::render() const
{
    // static keyword means
    // variable wont be created every time we call the render function
    // only created during first call
    // const keyword optimizes code by telling compiler
    // we wont modify content of objects once created
    static const TCODColor darkWall(0, 0, 100);
    static const TCODColor darkGround(50, 50, 150);

    // scans whole map and fills console background color with right color
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            TCODConsole::root->setCharBackground(x, y,
                isWall(x, y) ? darkWall : darkGround);
        }
    }
}


