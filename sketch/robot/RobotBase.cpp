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

