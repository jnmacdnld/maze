#include "MazeTextfileProcessor.cpp"

void setup() {
  Serial.begin(9600);

  Serial.println("Begin");

  /*char backToWallString[MAZE_STRING_LENGTH_NULL_T];
  char wallString[ ] = "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +";

  Serial.println("Call horizontalWallStringToInt");
  uint16_t wallInt = 
    MazeTextfileProcessor::horizontalWallStringToInt(wallString);

  Serial.println("Call initStringFromHorizontalWallInt");
  MazeTextfileProcessor::initStringFromHorizontalWallInt(
                                                    backToWallString, wallInt);

  Serial.print("There...     ");
  Serial.print(wallString);
  Serial.println();

  Serial.print("And back.    ");
  Serial.print(backToWallString);
  Serial.println();*/

  char wallString[ ] = "| |   | |     | | |             |";
  char backToWallString[MAZE_STRING_LENGTH_NULL_T];

  uint16_t wallArr[15];
  uint8_t row = 4;

  MazeTextfileProcessor::setIntArrayFromVerticalWallString(wallArr,
                                                           wallString,
                                                           row);

  MazeTextfileProcessor::initVerticalWallStringFromIntArray(backToWallString,
                                                            wallArr, row);

  Serial.print("There...     ");
  Serial.print(wallString);
  Serial.println();

  Serial.print("And back.    ");
  Serial.print(backToWallString);
  Serial.println();
}

void loop() {

}