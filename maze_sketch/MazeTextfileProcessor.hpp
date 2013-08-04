#ifndef MAZETEXTFILEPROCESSOR_H
#define MAZETEXTFILEPROCESSOR_H
 
#include "Arduino.h"
#include <string.h>

#define MAZE_LN_LEN 33                 // Length of a line of maze text

#define MAZE_STR_LEN (MAZE_LN_LEN + 1) // Length of a string of (null 
                                       // terminated) maze text

#define GOAL_CHAR 'G'                  // Char that marks the goal in maze text

class MazeTextfileProcessor {
  public:
    // Encode and decode horizontal walls
    static uint16_t horizontalWallStringToInt(
                                        char string[MAZE_STR_LEN]);

    static void initStringFromHorizontalWallInt(
                                  char (&wallString)[MAZE_STR_LEN],
                                  uint16_t wallInt);

    // Encode and decode vertical walls
    static void setIntArrayFromVerticalWallString(
                                      uint16_t (&arr)[15], 
                                      char (&string)[MAZE_STR_LEN],
                                      uint8_t row);

    static void initVerticalWallStringFromIntArray(
                                      char (&string)[MAZE_STR_LEN],
                                      uint16_t (&arr)[15],
                                      uint8_t row);

    // Encode and decode vertical wall arrays
    static void initVerticalWallIntArrayFromStringArray(
                                 uint16_t (&intArr)[15],
                                 char (&strArr)[16][MAZE_STR_LEN]);

    static void initVerticalWallStringArrFromIntArr(
                                  char (&strArr)[16][MAZE_STR_LEN],
                                  uint16_t (&intArr)[15]);

    // Encode and decode horizontal wall arrays
    static void initHorizontalWallIntArrayFromStringArray(
                                 uint16_t (&intArr)[15],
                                 char (&strArr)[15][MAZE_STR_LEN]);

    static void initHorizontalWallStringArrayFromIntArray(
                                  char (&strArr)[15][MAZE_STR_LEN],
                                  uint16_t (&intArr)[15]);

    // Coordinates
    static uint8_t coordinatesToInt(uint8_t row, uint8_t col);
    static uint8_t getRowFromInt(uint8_t integer);
    static uint8_t getColFromInt(uint8_t integer);

    // Find goal
    static uint8_t getGoal(char (&vertWallStrArr)[16][MAZE_STR_LEN]);

  private:
    /*
    static void checkIsValidHorizontalWallString(String string) {
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
};
 
#endif /* MAZETEXTFILEPROCESSOR_H */
