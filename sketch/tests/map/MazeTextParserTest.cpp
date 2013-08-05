#include "../../map/MazeTextParser.hpp"
#include <string.h>
#include <Arduino.h>
#include <ArduinoUnit.h>

#define CLASS MazeTextParser

char mazeText[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN] = {
  "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
  "|     | |     | | |       |     |",
  "+-+-+ + +-+-+-+-+-+-+-+ +-+ +-+ +",
  "| |     |     |   |         |   |",
  "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
  "| |   | |     | | |             |",
  "+-+-+ + +-+-+-+-+-+-+-+ +-+ +-+ +",
  "| |     |     |   |         |   |",
  "+-+-+ + +-+-+-+-+-+-+-+ +-+ +-+ +",
  "| |   | |     | | |             |",

  "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
  "| |   | |     | | |             |",
  "+-+-+ + +-+ +-+-+-+-+ + +-+ +-+ +",
  "| |     |     | | |             |",
  "+-+-+ + +-+-+ +-+-+-+ + +-+ +-+ +",
  "| |   | |     |   |     |       |",
  "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
  "| |     |     |   |         |   |",
  "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
  "| |   | |     | | |             |",

  "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
  "| |   | |     | | |     |       |",
  "+-+-+ + +-+-+-+-+-+-+-+ +-+ +-+ +",
  "| |   | |       | |         |   |",
  "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
  "| |     |     |   |         |   |",
  "+-+-+ + +-+-+-+-+-+-+-+ +-+ +-+ +",
  "| |   | |   |   | |     |       |",
  "+-+-+ + + +-+-+-+-+-+ + +-+ +-+ +",
  "| |     |     |   |         |   |",

  "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +",
  "| |   | | |   | | | |   |       |",
  "+-+ + +-+ +-+-+-+-+-+-+-+-+-+-+-+"
};

test(horizWallEncode) {
  char backToHorzWallStr[MAZE_STR_LEN];
  char horizontalWallStr[ ] = "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +";

  uint16_t wallInt = 
    CLASS::horizontalWallStrToInt(horizontalWallStr);

  CLASS::initStrFromHorzWallInt(backToHorzWallStr, wallInt);

  assertTrue(strcmp(horizontalWallStr, backToHorzWallStr) == 0);
}

test(vertWallEncode) {
  char verticalWallStr[ ] = "| |   | |     | | |             |";
  char backToVertWallStr[MAZE_STR_LEN];

  uint16_t wallArr[15];
  uint8_t row = 4;

  CLASS::setIntArrFromVertWallStr(wallArr, verticalWallStr, row);
  CLASS::initVertWallStrFromIntArr(backToVertWallStr, wallArr,
                                          row);

  assertTrue(strcmp(verticalWallStr, backToVertWallStr) == 0);
}

void testVertWallArrEncode(void (&toInt)(
                            uint16_t (&intArr)[15],
                            char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN]),
                       void (&fromInt)(
                            char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN],
                            uint16_t (&intArr)[15])) { 
  uint16_t vertWallIntArr[NUM_WALL_INTS_IN_ARR] = {0}; 
  
  char backToMazeText[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN] = {0}; 
  toInt(vertWallIntArr, mazeText);
  fromInt(backToMazeText, vertWallIntArr);
  
  for (uint8_t i = 1; i < NUM_MAZE_TEXT_STRS; i += 2) {
    assertTrue(strcmp(mazeText[i], backToMazeText[i]) == 0); 
  } 
}

test(vertWallArrEncode) {
  testVertWallArrEncode(CLASS::initVertWallIntArrFromMazeText,
                        CLASS::setMazeTextFromVertWallIntArr);
}

/*test(horzWallArrEncode) {
  testWallArrEncode(CLASS::initHorzWallIntArrFromMazeText,
                    CLASS::setMazeTextFromHorzWallIntArr);
}*/

// Coordinates
#define testEncodeCoord(row, col) { \
  uint8_t encodedInt = CLASS::coordinatesToInt(row, col); \
  \
  uint8_t decodedRow = CLASS::getRowFromInt(encodedInt); \
  uint8_t decodedCol = CLASS::getColFromInt(encodedInt); \
  \
  assertEqual(row, decodedRow); \
  assertEqual(col, decodedCol); \
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

  uint8_t goal = CLASS::getGoal(verticalWalls);

  uint8_t goalRow = CLASS::getRowFromInt(goal);
  uint8_t goalCol = CLASS::getColFromInt(goal);

  char goalChar = verticalWalls[goalRow][(goalCol * 2) + 1];

  assertNotEqual(goal, 0);

  assertEqual(goalChar, GOAL_CHAR);
}
