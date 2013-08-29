#include "Cell.hpp"
/*
cell_t _::coordinatesToCell(uint8_t row, uint8_t col) {
  return (cell_t) ( (row * 16) + col );
}

uint8_t _::getRowFromCell(cell_t cell) {
  return cell / 16;
}

uint8_t _::getColFromCell(cell_t cell) {
  return cell % 16;
}
*/

Cell::Cell(uint8_t row, uint8_t col) {
  cellNumber = (row * 16) + col;
}

uint8_t Cell::getRow() {
  return cellNumber / 16;
}

uint8_t Cell::getCol() {
  return cellNumber % 16;
}

