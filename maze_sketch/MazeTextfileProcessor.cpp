#include "MazeTextfileProcessor.hpp"

// Encode and decode horizontal walls
uint16_t MazeTextfileProcessor::horizontalWallStringToInt(
                                       char string[MAZE_STR_LEN]) {
  // checkIsValidHorizontalWallString(string);

  uint16_t wallInt;
  uint8_t wallIntIndex = 0;
  uint8_t stringIndex = 1;

  while ( stringIndex < MAZE_LN_LEN && wallIntIndex < 16 ) {
    char wallChar = string[stringIndex];
    bool isWall = wallChar == '-';
    
    bitWrite(wallInt, wallIntIndex, isWall);

    wallIntIndex++;
    stringIndex += 2;
  }

  return wallInt;
}

void MazeTextfileProcessor::initStringFromHorizontalWallInt(
                                  char (&wallString)[MAZE_STR_LEN],
                                  uint16_t wallInt) {
  strcpy(wallString, "+ + + + + + + + + + + + + + + + +");
  
  uint8_t wallIntIndex = 0;
  uint8_t stringIndex = 1;

  while ( stringIndex < MAZE_LN_LEN && wallIntIndex < 16 ) {
    bool isWall = bitRead(wallInt, wallIntIndex);
    
    if (isWall) {
      wallString[stringIndex] = '-';
    }

    wallIntIndex++;
    stringIndex += 2;
  }
}

// Encode and decode vertical walls
void MazeTextfileProcessor::setIntArrayFromVerticalWallString(
                                      uint16_t (&arr)[15], 
                                      char (&string)[MAZE_STR_LEN],
                                      uint8_t row) {
  uint8_t col = 0;
  uint8_t stringIndex = 2;

  while ( stringIndex < MAZE_LN_LEN && col < 15 ) {
    char wallChar = string[stringIndex];
    bool isWall = wallChar == '|';
    
    bitWrite(arr[col], row, isWall);

    col++;
    stringIndex += 2;
  }
}

void MazeTextfileProcessor::initVerticalWallStringFromIntArray(
                                      char (&string)[MAZE_STR_LEN],
                                      uint16_t (&arr)[15],
                                      uint8_t row) {
  uint8_t col = 0;
  uint8_t stringIndex = 2;
  strcpy(string, "|                               |");

  while ( stringIndex < MAZE_LN_LEN && col < 15 ) {
    bool isWall = bitRead(arr[col], row);
    
    if (isWall) {
      string[stringIndex] =  '|';
    }

    col++;
    stringIndex += 2;
  }
}

// Encode and decode vertical wall arrays
void MazeTextfileProcessor::initVerticalWallIntArrayFromStringArray(
                                uint16_t (&intArr)[15],
                                char (&strArr)[16][MAZE_STR_LEN]) {
  for (uint8_t i = 0; i < 16; i++) {
    setIntArrayFromVerticalWallString(intArr, strArr[i], i);
  }
}

void MazeTextfileProcessor::initVerticalWallStringArrFromIntArr(
                                  char (&strArr)[16][MAZE_STR_LEN],
                                  uint16_t (&intArr)[15]) {
  for (uint8_t i = 0; i < 16; i++) {
    initVerticalWallStringFromIntArray(strArr[i], intArr, i);
  }
}

// Encode and decode horizontal wall arrays
void MazeTextfileProcessor::initHorizontalWallIntArrayFromStringArray(
                                uint16_t (&intArr)[15],
                                char (&strArr)[15][MAZE_STR_LEN]) {
  for (uint8_t i = 0; i < 15; i++) {
    uint16_t wallInt = horizontalWallStringToInt(strArr[i]);
    intArr[i] = wallInt;
  }
}

void MazeTextfileProcessor::initHorizontalWallStringArrayFromIntArray(
                                  char (&strArr)[15][MAZE_STR_LEN],
                                  uint16_t (&intArr)[15]) {
  for (uint8_t i = 0; i < 15; i++) {
    char wallString[MAZE_STR_LEN];
    initStringFromHorizontalWallInt(wallString, intArr[i]);
    strcpy(strArr[i], wallString);
  }
}

// Coordinates
uint8_t MazeTextfileProcessor::coordinatesToInt(uint8_t row, uint8_t col) {
  return (row * 16) + col;
}

uint8_t MazeTextfileProcessor::getRowFromInt(uint8_t integer) {
  return integer / 16;
}

uint8_t MazeTextfileProcessor::getColFromInt(uint8_t integer) {
  return integer % 16;
}
