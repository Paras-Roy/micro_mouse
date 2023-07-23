class Maze
{
    public:
    // ------------------Public Variables---------------------
        Cell cells[CELL_SIZE][CELL_SIZE];


    // ------------------Public Functions---------------------

        Maze()
        {
            //inititalize all cells
            for(int i = 0; i < CELL_SIZE; i++)
            {
                for(int j = 0; j < CELL_SIZE; j++)
                {
                    cells[i][j] = Cell(i, j, CELL_SIZE*CELL_SIZE, 0);
                }
            }

            //set wallcode for cells on the edges
            for(int i = 0; i < CELL_SIZE; i++)
            {
                cells[i][0].setWallCode(cells[i][0].wallCode | 8);
                cells[i][CELL_SIZE-1].setWallCode(cells[i][CELL_SIZE-1].wallCode | 2);
                cells[0][i].setWallCode(cells[0][i].wallCode | 1);
                cells[CELL_SIZE-1][i].setWallCode(cells[CELL_SIZE-1][i].wallCode | 4);
            }
        }

        void updateWall(int x, int y, int wallCode)
        {
            //add new walls to current cell
            cells[x][y].setWallCode(cells[x][y].wallCode | wallCode);

            if((wallCode & 1) == 1)
            {
                if(x-1>=0)
                {
                    //add wall to adjacent cell
                    cells[x-1][y].setWallCode(cells[x-1][y].wallCode | 4);
                }
            }

            if((wallCode & 2) == 2)
            {
                if(y+1<=CELL_SIZE-1)
                {
                    //add wall to adjacent cell
                    cells[x][y+1].setWallCode(cells[x][y+1].wallCode | 8);
                }
            }

            if((wallCode & 4) == 4)
            {
                if(x+1<=CELL_SIZE-1)
                {
                    //add wall to adjacent cell
                    cells[x+1][y].setWallCode(cells[x+1][y].wallCode | 1);
                }
            }

            if((wallCode & 8) == 8)
            {
                if(y-1>=0)
                {
                    //add wall to adjacent cell
                    cells[x][y-1].setWallCode(cells[x][y-1].wallCode | 2);
                }
            }
        }

        int getWallCode(int x, int y)
        {
            return cells[x][y].wallCode;
        }

        int getDistance(int x, int y)
        {
            return cells[x][y].dist;
        }

        void printMaze()
        {
            for(int i = 0; i < CELL_SIZE; i++)
            {
                Serial.print(F("+"));
                for(int j = 0; j < CELL_SIZE; j++)
                {
                    if((cells[i][j].wallCode & 1) == 1)
                    {
                        // std::cout << "---";
                        Serial.print(F("---"));
                    }
                    else
                    {
                        // std::cout << "   ";
                        Serial.print(F("   "));
                    }
                    // std::cout << "+";
                    Serial.print(F("+"));
                }
                // std::cout << std::endl;
                Serial.println();
                for(int j = 0; j < CELL_SIZE; j++)
                {
                    if((cells[i][j].wallCode & 8) == 8)
                    {
                        // std::cout << "|";
                        Serial.print(F("|"));
                    }
                    else
                    {
                        // std::cout << " ";
                        Serial.print(F(" "));
                    }
                    // std::cout << " ";
                    // std::cout << cells[i][j].dist;
                    Serial.print(F(" "));
                    Serial.print(cells[i][j].dist);
                    if(cells[i][j].dist < 10)
                    {
                        // std::cout << " ";
                        Serial.print(F(" "));
                    }
                }
                // std::cout << "|" << std::endl;
                Serial.println(F("|"));
                Serial.println();
            }
            // std::cout << "+";
            Serial.print(F("+"));
            for(int j = 0; j < CELL_SIZE; j++)
            {
                // std::cout << "---+";
                Serial.print(F("---+"));
            }
            // std::cout << std::endl;
            Serial.println();
        }
        
        void floodFill()
        {
            bool visited[CELL_SIZE][CELL_SIZE] = {false};
            cppQueue q(sizeof(Cell), CELL_SIZE*CELL_SIZE, FIFO);

            // floodFillHelper(1, 1, visited, q, 0);
            floodFillHelper((CELL_SIZE/2)-1, (CELL_SIZE/2)-1, visited, q, 0);
            for(int i = 0; i < CELL_SIZE; i++)
            {
                for(int j = 0; j < CELL_SIZE; j++)
                {
                    visited[i][j] = false;
                }
            }
            // floodFillHelper(1, 2, visited, q, 0);
            floodFillHelper((CELL_SIZE/2)-1, (CELL_SIZE/2), visited, q, 0);
            for(int i = 0; i < CELL_SIZE; i++)
            {
                for(int j = 0; j < CELL_SIZE; j++)
                {
                    visited[i][j] = false;
                }
            }
            // floodFillHelper(2, 1, visited, q, 0);
            floodFillHelper((CELL_SIZE/2), (CELL_SIZE/2)-1, visited, q, 0);
            for(int i = 0; i < CELL_SIZE; i++)
            {
                for(int j = 0; j < CELL_SIZE; j++)
                {
                    visited[i][j] = false;
                }
            }
            // floodFillHelper(2, 2, visited, q, 0);
            floodFillHelper((CELL_SIZE/2), (CELL_SIZE/2), visited, q, 0);
        }

        void floodFillHelper(int x, int y, bool visited[CELL_SIZE][CELL_SIZE], cppQueue q, int distance)
        {
            visited[x][y] = true;
            cells[x][y].setDist(distance);
            Cell cell = cells[x][y];
            q.push(&cell);

            while(!q.isEmpty())
            {
                Cell current;
                q.pop(&current);

                if((current.wallCode & 1) == 0)
                {
                    if(current.x-1 >= 0)
                    {
                        if(!visited[current.x-1][current.y])
                        {
                            visited[current.x-1][current.y] = true;
                            cells[current.x-1][current.y].setDist(min(current.dist+1, cells[current.x-1][current.y].dist));
                            q.push(&cells[current.x-1][current.y]);
                        }
                    }
                }
                
                if((current.wallCode & 2) == 0)
                {
                    if(current.y+1 <= CELL_SIZE-1)
                    {
                        if(!visited[current.x][current.y+1])
                        {
                            visited[current.x][current.y+1] = true;
                            cells[current.x][current.y+1].setDist(min(current.dist+1, cells[current.x][current.y+1].dist));
                            q.push(&cells[current.x][current.y+1]);
                        }
                    }
                }

                if((current.wallCode & 4) == 0)
                {
                    if(current.x+1 <= CELL_SIZE-1)
                    {
                        if(!visited[current.x+1][current.y])
                        {
                            visited[current.x+1][current.y] = true;
                            cells[current.x+1][current.y].setDist(min(current.dist+1, cells[current.x+1][current.y].dist));
                            q.push(&cells[current.x+1][current.y]);
                        }
                    }
                }

                if((current.wallCode & 8) == 0)
                {
                    if(current.y-1 >= 0)
                    {
                        if(!visited[current.x][current.y-1])
                        {
                            visited[current.x][current.y-1] = true;
                            cells[current.x][current.y-1].setDist(min(current.dist+1, cells[current.x][current.y-1].dist));
                            q.push(&cells[current.x][current.y-1]);
                        }
                    }
                }


            }

        }
        
        // void printMazeWallCode()
        // {
        //     for(int i = 0; i < CELL_SIZE; i++)
        //     {
        //         for(int j = 0; j < CELL_SIZE; j++)
        //         {
        //             std::cout << cells[i][j].wallCode << " ";
        //         }
        //         std::cout << std::endl;
        //     }
        // }
} maze;
