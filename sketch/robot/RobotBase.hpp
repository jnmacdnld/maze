#ifndef ROBOTBASE_HPP
#define ROBOTBASE_HPP
 
#include "Cell.hpp"
#include "Direction.hpp"
#include "Robot.hpp"
 
class RobotBase : public Robot {
public:
  RobotBase(Direction dir);

  virtual Direction getFacingDirection();
  virtual void setFacingDirection(Direction dir);

  virtual Cell getCurrentCell();
  virtual void setCurrentCell(Cell &cell);

  virtual void setRow(uint8_t row);
  virtual void setCol(uint8_t col);

  virtual uint8_t getRow();
  virtual uint8_t getCol();

  
private:
  Cell currentCell;
  Direction facingDirection;
};
 
 
#endif /* ROBOTBASE_HPP */
