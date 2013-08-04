#line 2 "maze_sketch.ino"
#include <ArduinoUnit.h>

#include "tests/map/MazeTextProcessorTest.cpp"
#include "map/MazeTextProcessor.cpp"

void setup() {
  Serial.begin(9600);
  Serial.println("Started.");
}

void loop() {
  Test::run();
}
