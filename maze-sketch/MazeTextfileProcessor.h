#include "Arduino.h"

#define MAZE_STRING_LENGTH 33

class MazeTextfileProcessor {
  public:
    static uint16_t horizontalWallStringToInt(String string) {
      //checkIsValidHorizontalWallString(string);

      uint16_t wallInt;
      uint8_t wallIntIndex = 0;
      uint8_t stringIndex = 1;

      while ( stringIndex < MAZE_STRING_LENGTH && wallIntIndex < 16 ) {
        char wallChar = string.charAt(stringIndex);
        bool isWall = wallChar == '-';
        
        bitWrite(wallInt, wallIntIndex, isWall);

        wallIntIndex++;
        stringIndex += 2;
      }

      return wallInt;
    }

    static String intToHorizontalWallString(uint16_t wallInt) {
      String wallString = "+ + + + + + + + + + + + + + + + +";
      uint8_t wallIntIndex = 0;
      uint8_t stringIndex = 1;

      while ( stringIndex < MAZE_STRING_LENGTH && wallIntIndex < 16 ) {
        bool isWall = bitRead(wallInt, wallIntIndex);
        
        if (isWall) {
          wallString.setCharAt(stringIndex, '-');
        }

        wallIntIndex++;
        stringIndex += 2;
      }

      return wallString;
    }

    static void setIntArrayFromVerticalWallString(uint16_t (&arr)[15], 
                                                  String string,
                                                  uint8_t row) {
      uint8_t col = 0;
      uint8_t stringIndex = 2;

      while ( stringIndex < MAZE_STRING_LENGTH && col < 15 ) {
        char wallChar = string.charAt(stringIndex);
        bool isWall = wallChar == '|';
        
        bitWrite(arr[col], row, isWall);

        col++;
        stringIndex += 2;
      }
    }

    static String intArrayToVerticalWallString(uint16_t (&arr)[15],
                                               uint8_t row) {
      uint8_t col = 0;
      uint8_t stringIndex = 2;
      String string = "|                               |";

      while ( stringIndex < MAZE_STRING_LENGTH && col < 15 ) {
        bool isWall = bitRead(arr[col], row);
        
        if (isWall) {
          string.setCharAt(stringIndex, '|');
        }

        col++;
        stringIndex += 2;
      }

      return string;
    }

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