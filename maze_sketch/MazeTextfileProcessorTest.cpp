#pragma once

#include "MazeTextfileProcessor.h"
#include <string.h>
#include <Arduino.h>
#include <ArduinoUnit.h>

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