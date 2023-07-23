//Main file for micromouse project made by Paras Roy

// Include files
#include <cppQueue.h>


#include "headers/MMpins.h"
#include "headers/MMsetup.h"
#include "headers/MMultrasonic.h"
#include "headers/MMmotors.h"
#include "headers/MMmovement.h"
#include "headers/MMcell.h"
#include "headers/MMmaze.h"
#include "headers/MMbot.h"
#include "headers/MMstate.h"


void setup() {
    Serial.begin(9600);
    Serial.println("Starting Sequence");
    delay(100);
}

void loop() {
  maze.updateWall(0,0,2);
  maze.updateWall(1,0,2);
  maze.updateWall(2,0,2);
  maze.updateWall(3,1,1);
  maze.updateWall(3,2,1);
  maze.updateWall(2,3,8);
  maze.updateWall(1,3,8);
  maze.floodFill();
  bot.run();
  maze.printMaze();
  while(1);
}