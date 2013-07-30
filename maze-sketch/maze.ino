#include "MazeTextfileProcessor.cpp"

void setup() {
  Serial.begin(9600);
  /*
  String wallString = "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +";
  uint16_t wallInt = 
    MazeTextfileProcessor::horizontalWallStringToInt(wallString);
  String backToWallString = 
    MazeTextfileProcessor::intToHorizontalWallString(wallInt);

  Serial.println("there...     " + wallString);
  Serial.println("and back.    " + backToWallString);
  */

  String wallString = "| |   | |     | | |             |";
  uint16_t wallArr[15];
  uint8_t row = 4;
  MazeTextfileProcessor::setIntArrayFromVerticalWallString(wallArr,
                                                           wallString,
                                                           row);
  String backToWallString = 
    MazeTextfileProcessor::intArrayToVerticalWallString(wallArr, row);

  Serial.println("there...     " + wallString);
  Serial.println("and back.    " + backToWallString);
}

void loop() {
 
}
