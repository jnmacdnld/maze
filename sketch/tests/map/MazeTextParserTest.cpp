#include "../../map/MazeTextParser.hpp"
#include <string.h>
#include <Arduino.h>
#include <ArduinoUnit.h>

#define CLASS MazeTextParser

char mazeText[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN] = {
  "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
  "|  G  | |     | | |       |     |",
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
  "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
};

test(horzWallEncode) {
  char backToHorzWallStr[MAZE_STR_LEN];
  char horizontalWallStr[ ] = "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +";

  uint16_t wallInt = 
    CLASS::horzWallStrToInt(horizontalWallStr);

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

void testWallArrEncode(
                      void (&toInt)(
                            uint16_t (&intArr)[15],
                            char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN]
                                   ),
                      void (&fromInt)(
                            char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN],
                            uint16_t (&intArr)[15]
                                     ),
                      uint8_t offset
                      ) {
  uint16_t wallIntArr[NUM_WALL_INTS] = {0};
  
  char backToMazeText[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN] = {0};
  toInt(wallIntArr, mazeText);
  fromInt(backToMazeText, wallIntArr);
  
  for (uint8_t i = offset; i < NUM_MAZE_TEXT_STRS; i += 2) {
    assertTrue(strcmp(mazeText[i], backToMazeText[i]) == 0);
  } 
}

/*test(vertWallArrEncode) {
  testWallArrEncode(CLASS::initVertWallIntArrFromMazeText,
                    CLASS::setMazeTextFromVertWallIntArr,
                    1);
}*/

test(horzWallArrEncode) {
  testWallArrEncode(CLASS::initHorzWallIntArrFromMazeText,
                    CLASS::setMazeTextFromHorzWallIntArr,
                    0);
}

// Coordinates
void testEncodeCoord(uint8_t row, uint8_t col) {
  cell_t cell = CLASS::coordinatesToCell(row, col);
  
  uint8_t decodedRow = CLASS::getRowFromCell(cell);
  uint8_t decodedCol = CLASS::getColFromCell(cell);
  
  assertEqual(row, decodedRow);
  assertEqual(col, decodedCol);
}

test(coordsEncode) {
  testEncodeCoord(4, 5);
  testEncodeCoord(0, 0);
}

// Goal

test(findGoalInMazeText) {
  cell_t goal = CLASS::getGoalFromMazeText(mazeText);

  uint8_t goalRow = CLASS::getRowFromCell(goal);
  uint8_t goalCol = CLASS::getColFromCell(goal);

  char goalChar = mazeText[(goalRow * 2) + 1][(goalCol * 2) + 1];

  assertNotEqual(goal, 0); // Assert goal was found
  assertEqual(goalChar, GOAL_CHAR);
}

test(toMazeMap) {
  MazeMap map = CLASS::mazeTextToMazeMap(mazeText);
  char backToMazeText[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN] = {0};

  CLASS::initMazeTextFromMazeMap(backToMazeText, map);

  for (uint8_t i = 0; i < NUM_MAZE_TEXT_STRS; i++) {
    /*Serial.println(mazeText[i]);
    Serial.println(backToMazeText[i]);
    Serial.println();*/
    assertTrue(strcmp(mazeText[i], backToMazeText[i]) == 0);
  }
}
