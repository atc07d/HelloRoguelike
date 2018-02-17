// Only diff between struchts and classes in C++ is
// structs have default public members
// classes have default private members
// both can have a mix
// indistinguishable in performance
// generally use struchs for data only classes


struct Tile
{
    bool canWalk; // can we walk through this tile?
    Tile() : canWalk(true) {}
};

class Map
{
    public:
    int width, height;

    Map(int width, int height);
    ~Map();  //destructor. use destructors if class has
             // dynamic mem, open files, or db handles
             // declared because of *tiles below
    bool isWall(int x, int y) const;
    void render() const;
    protected:
        Tile *tiles; // dynamically allocate map size aka array of tiles
                     // tiles contains address of first element of array
        void setWall(int x, int y);
};
