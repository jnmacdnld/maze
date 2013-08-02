#include "MazeTextfileProcessor.hpp"

uint16_t MazeTextfileProcessor::horizontalWallStringToInt(
                                  char string[MAZE_STRING_LENGTH_NULL_T]) {
  // checkIsValidHorizontalWallString(string);

  uint16_t wallInt;
  uint8_t wallIntIndex = 0;
  uint8_t stringIndex = 1;

  while ( stringIndex < MAZE_STRING_LENGTH && wallIntIndex < 16 ) {
    char wallChar = string[stringIndex];
    bool isWall = wallChar == '-';
    
    bitWrite(wallInt, wallIntIndex, isWall);

    wallIntIndex++;
    stringIndex += 2;
  }

  return wallInt;
}

void MazeTextfileProcessor::initStringFromHorizontalWallInt(
                            char (&wallString)[MAZE_STRING_LENGTH_NULL_T],
                            uint16_t wallInt) {
  strcpy(wallString, "+ + + + + + + + + + + + + + + + +");
  
  uint8_t wallIntIndex = 0;
  uint8_t stringIndex = 1;

  while ( stringIndex < MAZE_STRING_LENGTH && wallIntIndex < 16 ) {
    bool isWall = bitRead(wallInt, wallIntIndex);
    
    if (isWall) {
      wallString[stringIndex] = '-';
    }

    wallIntIndex++;
    stringIndex += 2;
  }
}

void MazeTextfileProcessor::setIntArrayFromVerticalWallString(
                                uint16_t (&arr)[15], 
                                char (&string)[MAZE_STRING_LENGTH_NULL_T],
                                uint8_t row) {
  uint8_t col = 0;
  uint8_t stringIndex = 2;

  while ( stringIndex < MAZE_STRING_LENGTH && col < 15 ) {
    char wallChar = string[stringIndex];
    bool isWall = wallChar == '|';
    
    bitWrite(arr[col], row, isWall);

    col++;
    stringIndex += 2;
  }
}

void MazeTextfileProcessor::initVerticalWallStringFromIntArray(
                                  char (&string)[MAZE_STRING_LENGTH_NULL_T],
                                  uint16_t (&arr)[15],
                                  uint8_t row) {
  uint8_t col = 0;
  uint8_t stringIndex = 2;
  strcpy(string, "|                               |");

  while ( stringIndex < MAZE_STRING_LENGTH && col < 15 ) {
    bool isWall = bitRead(arr[col], row);
    
    if (isWall) {
      string[stringIndex] =  '|';
    }

    col++;
    stringIndex += 2;
  }
}

void MazeTextfileProcessor::initVerticalWallIntArrayFromStringArray(
                            uint16_t (&intArr)[15],
                            char (&strArr)[15][MAZE_STRING_LENGTH_NULL_T]) {
  for (uint8_t i = 0; i < 15; i++) {
    setIntArrayFromVerticalWallString(intArr, strArr[i], i);
  }
}

void MazeTextfileProcessor::initVerticalWallStringArrFromIntArr(
                                  char (&strArr)[15][MAZE_STRING_LENGTH_NULL_T],
                                  uint16_t (&intArr)[15]) {
  for (uint8_t i = 0; i < 15; i++) {
    initVerticalWallStringFromIntArray(strArr[i], intArr, i);
  }
}
