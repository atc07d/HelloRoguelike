class Actor
{
    public:
        int x, y; // position on map
        int ch;   // ascii code
        TCODColor col; // color

        // col passed as const reference to keep compiler
        // from duplicating object before calling function
        Actor(int x, int y, int ch, const TCODColor &col);
        // const keyword after render declaration
        // mean that function does not modifiy the content of Actor object
        // and thus the function can be called on constant objects.
        void render() const;
};
