#include "../../map/MazeTextProcessor.hpp"
#include <string.h>
#include <Arduino.h>
#include <ArduinoUnit.h>

#define MTP MazeTextProcessor // Abbreviation for more concise code

test(horizWallEncode) {
  char backToHorizontalWallString[MAZE_STR_LEN];
  char horizontalWallString[ ] = "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +";

  uint16_t wallInt = 
    MTP::horizontalWallStringToInt(horizontalWallString);

  MTP::initStringFromHorizontalWallInt(backToHorizontalWallString, wallInt);

  assertTrue(strcmp(horizontalWallString, backToHorizontalWallString) == 0);
}

test(vertWallEncode) {
  char verticalWallString[ ] = "| |   | |     | | |             |";
  char backToVerticalWallString[MAZE_STR_LEN];

  uint16_t wallArr[15];
  uint8_t row = 4;

  MTP::setIntArrayFromVerticalWallString(wallArr, verticalWallString, row);
  MTP::initVerticalWallStringFromIntArray(backToVerticalWallString, wallArr,
                                          row);

  assertTrue(strcmp(verticalWallString, backToVerticalWallString) == 0);
}

test(vertWallArrEncode) {
  char wallStrArr[16][MAZE_STR_LEN] =
    {
      "| |   | |     | | |             |",
      "| |   |       | | |             |",
      "| |   | |     | | |             |",
      "| |   | |     |   |         |   |",
      "| |   | |     | | |             |",

      "| |   | |     | | |             |",
      "| |     |     | | |           | |",
      "| |   | |     |   |   |       | |",
      "| |   | |     | | |             |",
      "| |   | |     | | |             |",

      "| |   |       | | |             |",
      "| |   | |     |   |             |",
      "| |   | |     | | |             |",
      "|     |       | | |             |",
      "| |   | |     | | |             |",

      "| |   | |     | | |             |"
    };

  uint16_t wallArr[15];
  char backToStrArr[16][MAZE_STR_LEN];

  MTP::initVerticalWallIntArrayFromStringArray(wallArr, wallStrArr);
  MTP::initVerticalWallStringArrFromIntArr(backToStrArr, wallArr);

  for (uint8_t i = 0; i < 15; i++) {
    assertTrue(strcmp(wallStrArr[i], backToStrArr[i]) == 0);
  }
}

test(horzWallArrEncode) {
  char wallStrArr[15][MAZE_STR_LEN] =
    {
      "+ +-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
      "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
      "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
      "+-+-+ +-+-+-+-+-+-+-+ + +-+ +-+ +",
      "+-+-+-+ +-+-+-+-+-+-+ + +-+ +-+ +",

      "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
      "+-+-+ + +-+ +-+-+-+-+ + +-+ +-+ +",
      "+-+-+ + +-+-+-+-+-+-+ +-+-+ +-+ +",
      "+-+-+ + +-+-+ +-+-+-+ + +-+ +-+ +",
      "+-+-+ + +-+-+-+-+-+-+-+ +-+ +-+ +",

      "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
      "+ +-+ + +-+-+ +-+-+-+ + +-+ +-+ +",
      "+-+-+-+ +-+-+-+-+-+-+ + +-+ +-+ +",
      "+-+-+ + + +-+-+-+-+ + + +-+ +-+ +",
      "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +"
    };

  uint16_t wallArr[15];
  char backToStrArr[15][MAZE_STR_LEN];

  MTP::initHorizontalWallIntArrayFromStringArray(wallArr, wallStrArr);
  MTP::initHorizontalWallStringArrayFromIntArray(backToStrArr, wallArr);

  for (uint8_t i = 0; i < 15; i++) {
    assertTrue(strcmp(wallStrArr[i], backToStrArr[i]) == 0);
  }
}

// Coordinates
void testEncodeCoord(uint8_t row, uint8_t col) {
  uint8_t encodedInt = MTP::coordinatesToInt(row, col);

  uint8_t decodedRow = MTP::getRowFromInt(encodedInt);
  uint8_t decodedCol = MTP::getColFromInt(encodedInt); 

  assertEqual(row, decodedRow);
  assertEqual(col, decodedCol);
}

test(coordsEncode) {
  testEncodeCoord(4, 5);
  testEncodeCoord(0, 0);
}

// Goal

test(findGoal) {
  char verticalWalls[16][MAZE_STR_LEN] = 
    {
      "| |   | |     | | |             |",
      "| |   |       | | |             |",
      "| |   | |     | | |             |",
      "| |   | |     |   |         |   |",
      "| |   | |     | | |             |",

      "| |   | |     | | |             |",
      "| |     |     | | |           | |",
      "| |   | |     |   |   |       | |",
      "| |   | |     | | |             |",
      "| |   | |     | | |             |",

      "| |   |       |G| |             |",
      "| |   | |     |   |             |",
      "| |   | |     | | |             |",
      "|     |       | | |             |",
      "| |   | |     | | |             |",

      "| |   | |     | | |             |"
    };

  uint8_t goal = MTP::getGoal(verticalWalls);

  uint8_t goalRow = MTP::getRowFromInt(goal);
  uint8_t goalCol = MTP::getColFromInt(goal);

  char goalChar = verticalWalls[goalRow][(goalCol * 2) + 1];

  assertNotEqual(goal, 0);

  assertEqual(goalChar, GOAL_CHAR);
}
