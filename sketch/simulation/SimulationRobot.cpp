#include "SimulationRobot.hpp"
#include "MazeMap.hpp"
#include "Robot.hpp"

SimulationRobot::SimulationRobot(Simulation &sim, MazeMap &maze) : 
sim(&sim),
maze(&maze),
Robot(EAST) {

}

bool SimulationRobot::isBlocked(Direction dir) {
  return (*maze).isBlocked( getCurrentCell(), dir );
}
