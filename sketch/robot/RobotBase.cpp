#include "RobotBase.hpp"

RobotBase::RobotBase(Direction dir) :
facingDirection(dir),
currentCell( Cell(0, 0) ) {

}

Direction RobotBase::getFacingDirection() {
  return facingDirection;
}

void RobotBase::setFacingDirection(Direction dir) {
  facingDirection = dir;
}

Cell RobotBase::getCurrentCell() {
  return currentCell;
}

void RobotBase::setCurrentCell(Cell &cell) {
  currentCell = cell;
}

void RobotBase::setRow(uint8_t row) {
  currentCell = Cell( row, getCol() );
}

void RobotBase::setCol(uint8_t col) {
  currentCell = Cell( getRow(), col );
}

uint8_t RobotBase::getRow() {
  return getCurrentCell().getRow();
}
uint8_t RobotBase::getCol() {
  return getCurrentCell().getCol();
}
