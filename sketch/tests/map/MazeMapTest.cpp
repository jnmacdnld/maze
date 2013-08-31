#include "../../map/MazeMap.hpp"
#include "../../map/Cell.hpp"

#include "Arduino.h"
#include "ArduinoUnit.h"

MazeMap maze = MazeTextParser::mazeTextToMazeMap(mazeText);

/*"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
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
  "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"*/

class TestCell {
public: 
  TestCell(uint8_t row, uint8_t col, bool wallNorth, bool wallEast,
           bool wallSouth, bool wallWest) : cell( Cell(row, col) ) {
    isWall[NORTH] = wallNorth;
    isWall[EAST]  = wallEast;
    isWall[SOUTH] = wallSouth;
    isWall[WEST]  = wallWest;
  }

  Cell getCell() {
    return cell;
  }

  bool isWall[4];

private:
  Cell cell;
};

test(mazeMapIsBlocked) {
  TestCell cells[] = {
    TestCell(0,  0,  true,  false, true,  true),
    TestCell(0,  15, true,  true,  false, false),
    TestCell(15, 15, false, true,  true,  false),
    TestCell(15, 0,  true, true, true, true),

    TestCell(5,  5,  true, false, false, false),

    TestCell(0,  1,  true,  false, true,  false),
    TestCell(1,  15, false, true,  false, false),
    TestCell(15, 1,  true,  false, true,  true),
    TestCell(1,  0,  true, true, true, true)
  };

  int numCells = sizeof(cells) / sizeof(cells[0]);

  for (int i = 0; i < numCells; i++) {
    TestCell testCell = cells[i];
    Cell cell = testCell.getCell();

    for (int i = 0; i <= WEST; i++) {
      assertTrue( maze.isBlocked(cell, (Direction) i) == testCell.isWall[i] );
      /*Serial.print( maze.isBlocked(cell, (Direction) i) );
      Serial.print(" ");
      Serial.print( testCell.isWall[i] );
      Serial.println();*/
    }
  }
}
