#include "Cell.hpp"

#include <Arduino.h>
#include <ArduinoUnit.h>

test(cellEquals) {
  Cell cellOne (0, 0);
  Cell cellTwo (0, 0);

  assertTrue( cellOne.equals(cellTwo) );
}

test(cellSetRowCol) {
  Cell cell (2, 4);

  cell.setRow(5);
  assertTrue(cell.getRow() == 5);

  cell.setCol(12);
  assertTrue(cell.getCol() == 12);
}

test(cell) {
  Cell cell (3, 4);

  assertTrue(cell.getRow() == 3);
  assertTrue(cell.getCol() == 4);
}
