#ifndef ROBOTBASE_HPP
#define ROBOTBASE_HPP
 
#include "Cell.hpp"
#include "Direction.hpp"
#include "Robot.hpp"
 
class RobotBase : Robot {
public:
  RobotBase(Direction dir);

  Direction getFacingDirection();
  void setFacingDirection(Direction dir);

  Cell getCurrentCell();
  void setCurrentCell(Cell &cell);

  
private:
  Cell currentCell;
  Direction facingDirection;
};
 
 
#endif /* ROBOTBASE_HPP */
