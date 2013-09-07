#include "SimulationRobot.hpp"
#include "Simulation.hpp"
#include "Direction.hpp"
#include "MazeMap.hpp"
#include "RobotBase.hpp"

#include "error.hpp"

SimulationRobot::SimulationRobot(Direction dir, 
                                 Simulation &sim, 
                                 MazeMap &maze) : 
sim(&sim),
maze(&maze),
RobotBase(dir) {

}

bool SimulationRobot::getIsBlocked(Direction dir) {
  return (*maze).getIsBlocked( getCurrentCell(), dir );
}

void SimulationRobot::move(Direction dir) {
  uint8_t row = getRow();
  uint8_t col = getCol();

  switch (dir) {
    case NORTH:
      if (row != 0) { setRow(row - 1); }
      break;
    case EAST:
      if (col != 15) { setCol(col + 1); }
      break;
    case SOUTH:
      if (row != 15) { setRow(row + 1); }
      break;
    case WEST:
      if (col != 0) { setCol(col - 1); }
      break;
  }

  setFacingDirection(dir);
}
