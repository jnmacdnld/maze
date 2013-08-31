#line 2 "maze_sketch.ino"
#include <ArduinoUnit.h>

// #include "error.cpp"

void setup() {
  Serial.begin(115200);
  Serial.println("Started.");
}

void loop() {
  Test::run();
}
