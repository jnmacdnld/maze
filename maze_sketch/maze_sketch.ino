#line 2 "maze_sketch.ino"
#include <ArduinoUnit.h>

void setup() {
  Serial.begin(9600);  
  /*char wallStrArr[15][MAZE_STRING_LENGTH_NULL_T] =
    {
      "| |   | |     | | |             |",
      "| |   | |     | | |             |"
    };*/
  

}

void loop() {
  Test::run();
}