#ifndef MAZETEXTFILEPROCESSOR_H
#define MAZETEXTFILEPROCESSOR_H
 
#include "Arduino.h"
#include <string.h>

#define MAZE_STRING_LENGTH 33
#define MAZE_STRING_LENGTH_NULL_T (MAZE_STRING_LENGTH + 1)

class MazeTextfileProcessor {
  public:
    static uint16_t horizontalWallStringToInt(
                                      char string[MAZE_STRING_LENGTH_NULL_T]);

    static void initStringFromHorizontalWallInt(
                                char (&wallString)[MAZE_STRING_LENGTH_NULL_T],
                                uint16_t wallInt);

    static void setIntArrayFromVerticalWallString(
                                    uint16_t (&arr)[15], 
                                    char (&string)[MAZE_STRING_LENGTH_NULL_T],
                                    uint8_t row);

    static void initVerticalWallStringFromIntArray(
                                      char (&string)[MAZE_STRING_LENGTH_NULL_T],
                                      uint16_t (&arr)[15],
                                      uint8_t row);

    /*static void initVerticalWallIntArrayFromStringArray(
                                uint8_t (&intArr)[15],
                                char (&strArr)[15][MAZE_STRING_LENGTH_NULL_T]) {
      for (uint8_t i = 0; i < 15; i++) {
        setIntArrayFromVerticalWallString(intArr, strArr[i], i);
      }
    }

    static void initVerticalWallStringArrFromIntArr(
                                  char (&strArr)[15][MAZE_STRING_LENGTH_NULL_T],
                                  uint8_t (&intArr)[15]) {
      for (uint8_t i = 0; i < 15; i++) {
        initVerticalWallStringFromIntArray(strArr[i], intArr, i);
      }
    }*/

  private:
    /*
    static void checkIsValidHorizontalWallString(String string) {
      // Check correct string length
      assert(string.size() == MAZE_STRING_LENGTH);

      // Check plusses are at even indexes
      for (int i = 0; i < MAZE_STRING_LENGTH; i += 2) {
        assert(string.at(i) == '+');
      }

      //Check hyphens or spaces are at odd indexes
      for (int i = 1; i < MAZE_STRING_LENGTH; i += 2) {
        char wallChar = string.at(i);
        assert(wallChar == '-' || wallChar == ' ');
      }
      
    }
    */
};
 
#endif /* end of include guard: MAZETEXTFILEPROCESSOR_H */