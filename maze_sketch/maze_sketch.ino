#include "MazeTextfileProcessor.cpp"

void setup() {
  Serial.begin(9600);

  Serial.println("Begin");

  char backToWallString[ ] = "+ + + + + + + + + + + + + + + + +";
  char wallString[ ] = "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +";

  Serial.println("Call horizontalWallStringToInt");
  uint16_t wallInt = 
    MazeTextfileProcessor::horizontalWallStringToInt(wallString);

  Serial.println("Call setStringFromHorizontalWallInt");
  MazeTextfileProcessor::setStringFromHorizontalWallInt(
                                                    backToWallString, wallInt);

  Serial.print("There...     ");
  Serial.print(wallString);
  Serial.println();

  Serial.print("And back.    ");
  Serial.print(backToWallString);
  Serial.println();

/*  String wallString = "| |   | |     | | |             |";
  uint16_t wallArr[15];
  uint8_t row = 4;
  MazeTextfileProcessor::setIntArrayFromVerticalWallString(wallArr,
                                                           wallString,
                                                           row);
  String backToWallString = 
    MazeTextfileProcessor::intArrayToVerticalWallString(wallArr, row);

  Serial.println("there...     " + wallString);
  Serial.println("and back.    " + backToWallString);*/
}

void loop() {

}