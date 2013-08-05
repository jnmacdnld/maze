#line 2 "maze_sketch.ino"
#include <ArduinoUnit.h>

#include "tests/map/MazeTextParserTest.cpp"
#include "map/MazeTextParser.cpp"

void setup() {
  Serial.begin(9600);
  Serial.println("Started.");
}

void loop() {
  Test::run();
}
