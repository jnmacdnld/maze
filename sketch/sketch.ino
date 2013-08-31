#line 2 "maze_sketch.ino"
#include <ArduinoUnit.h>

// #include "error.cpp"

#include "map/MazeTextParser.cpp"
#include "map/MazeMap.cpp"
#include "map/Cell.cpp"

#include "robot/Robot.cpp"

#include "simulation/SimulationRobot.cpp"

#include "tests/map/MazeTextParserTest.cpp"
#include "tests/map/MazeMapTest.cpp"

void setup() {
  Serial.begin(115200);
  Serial.println("Started.");
}

void loop() {
  Test::run();
}
