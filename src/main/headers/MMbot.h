enum State {
    UP_1,
    DOWN_1,
    UP_2,
    DOWN_2,
    UP_3,
    DOWN_3,
};

enum Orientation {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};


class Bot
{
    public:
        int row;
        int col;
        Orientation orient;
        State state;
    
        Bot()
        {
            row = 0;
            col = 0;
            orient = SOUTH;
            state = UP_1;
        }

        void run()
        {
            switch(state)
            {
                case UP_1:
                    moveUp1();
                    moveUp1();
                    moveUp1();
                    moveUp1();
                    moveUp1();
                    moveUp1();
                    moveUp1();
                    moveUp1();
                    moveUp1();
                    moveUp1();
                    moveUp1();
                    break;
                case DOWN_1:
                    //something
                    break;
                case UP_2:
                    //something
                    break;
                case DOWN_2:
                    //something
                    break;
                case UP_3:
                    //something
                    break;
                case DOWN_3:
                    //something
                    break;
                default:
                    break;
            }
        }

        void moveUp1()
        {
            //bot.updateWall();
            
            int wallCode = maze.getWallCode(row, col);
            int dist = maze.getDistance(row, col);
            int next_row, next_col;

            if((wallCode & 1) == 0 && maze.getDistance(row-1, col) == dist-1)
            {
                next_row = row-1;
                next_col = col;
            }
            else if((wallCode & 2) == 0 && maze.getDistance(row, col+1) == dist-1)
            {
                next_row = row;
                next_col = col+1;
            }
            else if((wallCode & 4) == 0 && maze.getDistance(row+1, col) == dist-1)
            {
                next_row = row+1;
                next_col = col;
            }
            else if((wallCode & 8) == 0 && maze.getDistance(row, col-1) == dist-1)
            {
                next_row = row;
                next_col = col-1;
            }

            Movement nextMove = getMoveHelper(next_row, next_col);
            switch(nextMove)
            {
                case FORWARD:
                    moveForward(1);
                    break;
                case BACKWARD:
                    moveBackward(1);
                    break;
                case LEFT:
                    moveLeft();
                    break;
                case RIGHT:
                    moveRight();
                    break;
                default:
                    break;
            }

            Serial.print("Current Distance: ");
            Serial.println(maze.getDistance(row, col));
        }

        Movement getMoveHelper(int next_row, int next_col)
        {
            if(row==next_row)
            {
                if(col<next_col)
                {
                    if(orient==EAST)
                    {
                        return FORWARD;
                    }
                    else if(orient==NORTH)
                    {
                        return RIGHT;
                    }
                    else if(orient==WEST)
                    {
                        return BACKWARD;
                    }
                    else if(orient==SOUTH)
                    {
                        return LEFT;
                    }
                }
                else if(col>next_col)
                {
                    if(orient==EAST)
                    {
                        return BACKWARD;
                    }
                    else if(orient==NORTH)
                    {
                        return LEFT;
                    }
                    else if(orient==WEST)
                    {
                        return FORWARD;
                    }
                    else if(orient==SOUTH)
                    {
                        return RIGHT;
                    }
                }
            }
            else if(col==next_col)
            {
                if(row<next_row)
                {
                    if(orient==EAST)
                    {
                        return RIGHT;
                    }
                    else if(orient==NORTH)
                    {
                        return BACKWARD;
                    }
                    else if(orient==WEST)
                    {
                        return LEFT;
                    }
                    else if(orient==SOUTH)
                    {
                        return FORWARD;
                    }

                }
                else if(row>next_row)
                {
                    if(orient==EAST)
                    {
                        return LEFT;
                    }
                    else if(orient==NORTH)
                    {
                        return FORWARD;
                    }
                    else if(orient==WEST)
                    {
                        return RIGHT;
                    }
                    else if(orient==SOUTH)
                    {
                        return BACKWARD;
                    }
                }
            }
        }
        
        void moveForward(int steps)
    {
        if(orient==NORTH)
        {
            row-=steps;
        }
        else if(orient==EAST)
        {
            col+=steps;
        }
        else if(orient==SOUTH)
        {
            row+=steps;
        }
        else if(orient==WEST)
        {
            col-=steps;
        }

        //motor function to move forward steps times
        Serial.println("Moving forward");
    }

        void moveBackward(int steps)
    {
        if(orient==NORTH)
        {
            row+=steps;
        }
        else if(orient==EAST)
        {
            col-=steps;
        }
        else if(orient==SOUTH)
        {
            row-=steps;
        }
        else if(orient==WEST)
        {
            col+=steps;
        }

        //motor function to move backward steps times
        Serial.println("Moving backward");
    }

        void moveLeft()
    {
        if(orient==NORTH)
        {
            orient = WEST;
            col--;
        }
        else if(orient==EAST)
        {
            orient = NORTH;
            row--;
        }
        else if(orient==SOUTH)
        {
            orient = EAST;
            col++;
        }
        else if(orient==WEST)
        {
            orient = SOUTH;
            row++;
        }

        Serial.println("Moving left");
    }

        void moveRight()
    {
        if(orient==NORTH)
        {
            orient = EAST;
            col++;
        }
        else if(orient==EAST)
        {
            orient = SOUTH;
            row++;
        }
        else if(orient==SOUTH)
        {
            orient = WEST;
            col--;
        }
        else if(orient==WEST)
        {
            orient = NORTH;
            row--;
        }

        Serial.println("Moving right");
    }
} bot;