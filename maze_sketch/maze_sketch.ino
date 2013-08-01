#line 2 "maze_sketch.ino"
#include <ArduinoUnit.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Started.");
}

void loop() {
  Test::run();
}