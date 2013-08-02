#include "MazeTextfileProcessor.hpp"
#include <string.h>
#include <Arduino.h>

// Super hackish way of getting libraries since the current makefile doesn't 
// include them automatically
#include "libraries/arduinounit/ArduinoUnit.h"
#include "libraries/arduinounit/utility/ArduinoUnit.cpp"
#include "libraries/arduinounit/utility/FakeStream.cpp"
#include "libraries/arduinounit/utility/FakeStream.h"
#include "libraries/arduinounit/utility/FreeMemory.cpp"
#include "libraries/arduinounit/utility/FreeMemory.h"

test(mazeTextfileProcessorHorizWallEncodeDecode) {
	char backToHorizontalWallString[MAZE_STRING_LENGTH_NULL_T];
	char horizontalWallString[ ] = "+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +";

	uint16_t wallInt = 
	  MazeTextfileProcessor::horizontalWallStringToInt(horizontalWallString);

	MazeTextfileProcessor::initStringFromHorizontalWallInt(
	                                          backToHorizontalWallString, wallInt);

	assertTrue(strcmp(horizontalWallString, backToHorizontalWallString) == 0);
}

test(mazeTextfileProcessorVertWallEncodeDecode) {
	char verticalWallString[ ] = "| |   | |     | | |             |";
	char backToVerticalWallString[MAZE_STRING_LENGTH_NULL_T];

	uint16_t wallArr[15];
	uint8_t row = 4;

	MazeTextfileProcessor::setIntArrayFromVerticalWallString(wallArr,
	                                                         verticalWallString,
	                                                         row);

	MazeTextfileProcessor::initVerticalWallStringFromIntArray(backToVerticalWallString,
	                                                          wallArr, row);

	assertTrue(strcmp(verticalWallString, backToVerticalWallString) == 0);
}

test(MazeTextfileProcessorVertWallArrEncodeDecode) {
	char wallStrArr[15][MAZE_STRING_LENGTH_NULL_T] =
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
	    "| |   | |     | | |             |"
	  };

	uint16_t wallArr[15];
	char backToStrArr[15][MAZE_STRING_LENGTH_NULL_T];

	MazeTextfileProcessor::initVerticalWallIntArrayFromStringArray(wallArr,
																																 wallStrArr);

	MazeTextfileProcessor::initVerticalWallStringArrFromIntArr(backToStrArr,
																														 wallArr);

	for (uint8_t i = 0; i < 15; i++) {
		assertTrue(strcmp(wallStrArr[i], backToStrArr[i]) == 0);
	}
}
