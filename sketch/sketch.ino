#line 2 "maze_sketch.ino"
#include <ArduinoUnit.h>

#include "tests/map/MazeTextParserTest.cpp"
#include "map/MazeTextParser.cpp"

#include "map/MazeMap.cpp"

#include "map/Cell.cpp"

void setup() {
  Serial.begin(115200);
  Serial.println("Started.");
}

void loop() {
  Test::run();
}
