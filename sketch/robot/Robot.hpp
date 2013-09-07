#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Cell.hpp"
#include "Direction.hpp"
 
class Robot {
public:
  virtual void move(Direction dir) = 0;
  virtual bool getIsBlocked(Direction dir) = 0;

  virtual Direction getFacingDirection() = 0;
  virtual void setFacingDirection(Direction dir) = 0;

  virtual Cell getCurrentCell() = 0;
  virtual void setCurrentCell(Cell &cell) = 0;
};
 
#endif /* ROBOT_HPP */
