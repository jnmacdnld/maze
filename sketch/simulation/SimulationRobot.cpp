#include "SimulationRobot.hpp"
#include "../map/MazeMap.hpp"
#include "../robot/Robot.hpp"

SimulationRobot::SimulationRobot(Simulation &sim, MazeMap &maze) : 
sim(&sim),
maze(&maze),
Robot(EAST) {

}

bool SimulationRobot::isBlocked(Direction dir) {
  return (*maze).isBlocked( getCurrentCell(), dir );
}
