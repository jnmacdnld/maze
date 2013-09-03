#ifndef CELL_HPP
#define CELL_HPP
 
#include <Arduino.h>

class Cell {
public:
  Cell(uint8_t row, uint8_t col);

  uint8_t getRow();
  uint8_t getCol();

  bool equals(Cell &cell);

private:
  uint8_t cellNumber; // The number of the cell; the cells are numbered like so:
                      // 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
                      // 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
                      // ...
};
 
#endif /* CELL_HPP */
