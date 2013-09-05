#include "SimulationRobot.hpp"
#include "MazeMap.hpp"
#include "RobotBase.hpp"

SimulationRobot::SimulationRobot(Simulation &sim, MazeMap &maze) : 
sim(&sim),
maze(&maze),
RobotBase(EAST) {

}

bool SimulationRobot::getIsBlocked(Direction dir) {
  return (*maze).getIsBlocked( getCurrentCell(), dir );
}
