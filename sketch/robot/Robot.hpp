class Robot {
public:
  void move(Direction dir) = 0;
  bool isObstructed(Direction dir) = 0;

  Direction getFacingDirection() = 0;
  cell_t getCurrentCell() = 0;
  
private:
  cell_t currentCell;
  Direction facingDirection;    
};
