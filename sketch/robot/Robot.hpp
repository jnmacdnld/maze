#ifndef ROBOT_HPP
#define ROBOT_HPP
 
class Robot {
public:
  virtual ~Robot() {}
  Robot(Direction facingDirection);

  virtual void move(Direction dir) = 0;
  virtual bool isBlocked(Direction dir) = 0;

  virtual Direction getFacingDirection() = 0;
  virtual Cell getCurrentCell() = 0;
  
private:
  Cell currentCell;
  Direction facingDirection;    
};
 
#endif /* ROBOT_HPP */
