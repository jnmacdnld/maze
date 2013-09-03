#include "SimulationRobot.hpp"
#include "MazeMap.hpp"
#include "Robot.hpp"

SimulationRobot::SimulationRobot(Simulation &sim, MazeMap &maze) : 
sim(&sim),
maze(&maze),
Robot(EAST) {

}

bool SimulationRobot::getIsBlocked(Direction dir) {
  return (*maze).getIsBlocked( getCurrentCell(), dir );
}
