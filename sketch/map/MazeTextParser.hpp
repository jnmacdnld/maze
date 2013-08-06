#ifndef MAZE_TEXT_PARSER_HPP
#define MAZE_TEXT_PARSER_HPP
 
#include "Arduino.h"
#include <string.h>

/*GENERAL MAZE TEXT CONSTANTS*/
// Length of a line of maze text
#define MAZE_LN_LEN 33

// Length of a string of (null terminated) maze text
#define MAZE_STR_LEN (MAZE_LN_LEN + 1)  

// Char that marks the goal in maze text
#define GOAL_CHAR 'G'  

/*MAZE TEXT OF FULL MAZE CONSTANTS*/
// Number of lines of maze text in a 16 x 16 maze
#define NUM_MAZE_TEXT_LNS 33            

// Number of strings of maze text in a 16 x 16 maze
#define NUM_MAZE_TEXT_STRS 33         

/*VERTICAL WALL CONSTANTS*/
// Number of lines of vertical wall maze text in a 16 x 16 maze
#define NUM_VERT_WALL_LNS 16

// Number of vertical wall strings in an array of vertical wall strings
#define NUM_VERT_WALL_STRS 16           

/*HORIZONTAL WALL CONSTANTS*/
// Number of lines of horizontal wall maze text in a 16 x 16 maze
#define NUM_HORZ_WALL_LNS  15           

// Number of strings of horizontal wall maze text in a 16 x 16 maze
#define NUM_HORZ_WALL_STRS 15

/*WALL ARRAY CONSTANTS*/
// Number of integers in a array of wall integers
#define NUM_WALL_INTS 15         

class MazeTextParser {
  public:
    // Encode and decode horizontal walls
    static uint16_t horzWallStrToInt(char string[MAZE_STR_LEN]);

    static void initStrFromHorzWallInt(
                                  char (&wallStr)[MAZE_STR_LEN],
                                  uint16_t wallInt);

    // Encode and decode vertical walls
    static void setIntArrFromVertWallStr(
                                      uint16_t (&arr)[15], 
                                      char (&string)[MAZE_STR_LEN],
                                      uint8_t row);

    static void initVertWallStrFromIntArr(
                                      char (&string)[MAZE_STR_LEN],
                                      uint16_t (&arr)[15],
                                      uint8_t row);

    // Encode and decode vertical wall arrays
    static void initVertWallIntArrFromMazeText(
                            uint16_t (&intArr)[15],
                            char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN]);

    static void setMazeTextFromVertWallIntArr(
                             char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN],
                             uint16_t (&intArr)[15]);

    // Encode and decode horizontal wall arrays
    static void initHorzWallIntArrFromMazeText(
                          uint16_t (&intArr)[NUM_WALL_INTS],
                          char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN]);

    static void setMazeTextFromHorzWallIntArr(
                             char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN],
                             uint16_t (&intArr)[NUM_WALL_INTS]);

    // Coordinates
    static uint8_t coordinatesToInt(uint8_t row, uint8_t col);
    static uint8_t getRowFromInt(uint8_t integer);
    static uint8_t getColFromInt(uint8_t integer);

    // Find goal
    static uint8_t getGoalFromMazeText(
                            char (&mazeText)[NUM_MAZE_TEXT_STRS][MAZE_STR_LEN]);

    // MazeMap
    // static MazeMap mazeTextToMazeMap();

    // Maze text validation
    // static bool isValidHorzWallStr(Str string);
    
};
 
#endif /* MAZE_TEXT_PARSER_HPP */
