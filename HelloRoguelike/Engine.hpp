class Engine
{
    public:
    // list of all Actors on the map
    TCODList<Actor *> actors;
    Actor *player;
    Actor *mapEngine;

    Engine();
    ~Engine();
    void update();
    void render();
};

// tells compiler that somewhere in a .cpp file
// there is a global variable named engine
// dont forget to actually declare the variable
extern Engine engine;
