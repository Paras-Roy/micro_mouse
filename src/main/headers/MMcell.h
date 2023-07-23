class Cell
{
    public:
    // ------------------Public Variables---------------------
        int x, y;
        int dist;
        int wallCode; // wallCode is a 4 bit binary number, where each bit represents the presence of a wall in the direction of North, East, South and West respectively.
        bool visited;

    // ------------------Public Functions---------------------

        Cell()
        {
            x = 0;
            y = 0;
            dist = 0;
            wallCode = 0;
            visited = false;
        }

        Cell(int x, int y, int dist, int wallCode)
        {
            this->x = x;
            this->y = y;
            this->dist = dist;
            this->wallCode = wallCode;
            visited = false;
        }

        void setWallCode(int wallCode)
        {
            this->wallCode = wallCode;
        }

        void setDist(int dist)
        {
            this->dist = dist;
        }
};