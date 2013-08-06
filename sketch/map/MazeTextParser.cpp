#include "MazeTextParser.hpp"

#define _ MazeTextParser

// Encode and decode horizontal walls
uint16_t _::horzWallStrToInt(char string[MAZE_STR_LEN]) {
  // checkIsValidHorzWallStr(string);

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

void _::initStrFromHorzWallInt(char (&wallStr)[MAZE_STR_LEN],
                               uint16_t wallInt) {
  strcpy(wallStr, "+ + + + + + + + + + + + + + + + +");
  
  uint8_t wallIntIndex = 0;
  uint8_t stringIndex = 1;

  while ( stringIndex < MAZE_LN_LEN && wallIntIndex < 16 ) {
    bool isWall = bitRead(wallInt, wallIntIndex);
    
    if (isWall) {
      wallStr[stringIndex] = '-';
    }

    wallIntIndex++;
    stringIndex += 2;
  }
}

// Encode and decode vertical walls
void _::setIntArrFromVertWallStr(uint16_t (&arr)[15],
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

void _::initVertWallStrFromIntArr(char (&string)[MAZE_STR_LEN],
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
void _::initVertWallIntArrFromMazeText(
                           uint16_t (&intArr)[15],
                           char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN]) {
  uint8_t row = 0;
  for (uint8_t i = 1; i < NUM_MAZE_TEXT_STRS; i += 2) {
    setIntArrFromVertWallStr(intArr, mazeText[i], row);
    row++;
  }
}

void _::setMazeTextFromVertWallIntArr(
                             char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN],
                             uint16_t (&intArr)[NUM_WALL_INTS]) {
  uint8_t row = 0;
  for (uint8_t i = 1; i < NUM_MAZE_TEXT_STRS; i += 2) {
    initVertWallStrFromIntArr(mazeText[i], intArr, row);
    row++;
  }
}

// Encode and decode horizontal wall arrays

void _::initHorzWallIntArrFromMazeText(
                           uint16_t (&intArr)[NUM_WALL_INTS],
                           char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN]) {
  uint8_t intArrI = 0;
  uint8_t mazeTextI = 2;

  while (mazeTextI < NUM_MAZE_TEXT_STRS && intArrI < NUM_WALL_INTS ) {
    uint16_t wallInt = horzWallStrToInt(mazeText[mazeTextI]);
    intArr[intArrI] = wallInt;

    intArrI++;
    mazeTextI += 2;
  }
}

/*void _::initHorzWallStrArrFromIntArr(char (&strArr)[15][MAZE_STR_LEN],
                                         uint16_t (&intArr)[15]) {
  for (uint8_t i = 0; i < 15; i++) {
    char wallStr[MAZE_STR_LEN];
    initStrFromHorzWallInt(wallStr, intArr[i]);
    strcpy(strArr[i], wallStr);
  }
}*/

void _::setMazeTextFromHorzWallIntArr(
                             char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN],
                             uint16_t (&intArr)[NUM_WALL_INTS]) {
  char horzWall[MAZE_STR_LEN] = "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";

  strcpy(mazeText[0],                      horzWall);
  strcpy(mazeText[NUM_MAZE_TEXT_STRS - 1], horzWall);

  uint8_t intArrI = 0;
  uint8_t mazeTextI = 2;

   while (mazeTextI < NUM_MAZE_TEXT_STRS && intArrI < NUM_WALL_INTS ) {
    char wallStr[MAZE_STR_LEN] = {0};
    initStrFromHorzWallInt(wallStr, intArr[intArrI]);
    strcpy(mazeText[mazeTextI], wallStr);

    intArrI++;
    mazeTextI += 2;
  }
}

// Coordinates
cell_t _::coordinatesToCell(uint8_t row, uint8_t col) {
  return (cell_t) ( (row * 16) + col );
}

uint8_t _::getRowFromCell(cell_t cell) {
  return cell / 16;
}

uint8_t _::getColFromCell(cell_t cell) {
  return cell % 16;
}

// Goal
cell_t _::getGoalFromMazeText(
                           char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN]) {
  for (uint8_t i = 1; i < NUM_MAZE_TEXT_STRS; i += 2) {
    for (uint8_t k = 1; k < MAZE_STR_LEN - 1; k += 2) {
      if (mazeText[i][k] == GOAL_CHAR) {
        uint8_t col = k / 2;
        uint8_t row = i / 2;
        return coordinatesToCell(row, col);
      }
    }
  }

  return 0; // Goal not found
}

// MazeMap
MazeMap _::mazeTextToMazeMap(
                            char (&mazeText)[NUM_MAZE_TEXT_LNS][MAZE_STR_LEN]) {
  uint16_t vertWalls[NUM_WALL_INTS];
  uint16_t horzWalls[NUM_WALL_INTS];

  initVertWallIntArrFromMazeText(vertWalls, mazeText);
  initHorzWallIntArrFromMazeText(horzWalls, mazeText);

  uint8_t  goal = getGoalFromMazeText(mazeText);

  MazeMap mazeMap (horzWalls, vertWalls, goal);

  return mazeMap;
}

void _::initMazeTextFromMazeMap(char (&mazeText)[NUM_MAZE_TEXT_LNS][MAZE_STR_LEN],
                             MazeMap& map) {
  uint16_t horzWalls[NUM_WALL_INTS] = {0};
  uint16_t vertWalls[NUM_WALL_INTS] = {0};

  map.initArrFromHorzWalls(horzWalls);
  map.initArrFromVertWalls(vertWalls);

  uint8_t goal = map.getGoal();

  setMazeTextFromHorzWallIntArr(mazeText, horzWalls);
  setMazeTextFromVertWallIntArr(mazeText, vertWalls);
  setMazeTextFromGoal          (mazeText, goal);
}

void _::setMazeTextFromGoal(char (&mazeText)[NUM_MAZE_TEXT_LNS][MAZE_STR_LEN],
                            uint8_t goal) {
  uint8_t goalRow = getRowFromCell(goal);
  uint8_t goalCol = getColFromCell(goal);

  mazeText[(goalRow * 2) + 1][(goalCol * 2) + 1] = GOAL_CHAR;
}

/*static bool _::isValidHorzWallStr(Str string){
  // Check correct string length
  assert(string.size() == MAZE_LN_LEN);

  // Check plusses are at even indexes
  for (int i = 0; i < MAZE_LN_LEN; i += 2) {
    assert(string.at(i) == '+');
  }

  //Check hyphens or spaces are at odd indexes
  for (int i = 1; i < MAZE_LN_LEN; i += 2) {
    char wallChar = string.at(i);
    assert(wallChar == '-' || wallChar == ' ');
  }
}
*/
