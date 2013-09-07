#include "Cell.hpp"
#include "error.hpp"
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
  if (row > 15 || row < 0 || col > 15 || col < 0) {
    error("Invalid cell coordinates passed to Cell constructor. ");
  }

  setCellNumberFromCoords(row, col);
}

uint8_t Cell::getRow() {
  return cellNumber / 16;
}

uint8_t Cell::getCol() {
  return cellNumber % 16;
}

void Cell::setCol(uint8_t col) {
  setCellNumberFromCoords( getRow(), col );
}

void Cell::setRow(uint8_t row) {
  setCellNumberFromCoords( row, getCol() );
}

bool Cell::equals(Cell &cell) {
  return getCol() == cell.getCol() && getRow() == cell.getRow();
}

void Cell::setCellNumberFromCoords(uint8_t row, uint8_t col) {
  cellNumber = (row * 16) + col;
}

void Cell::print() {
  Serial.print("(");
  Serial.print( getRow() );
  Serial.print(", ");
  Serial.print( getCol() );
  Serial.print(")");
}
