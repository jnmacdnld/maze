#ifndef SIMULATIONROBOT_HPP
#define SIMULATIONROBOT_HPP

#include "../robot/Robot.hpp"
#include "Simulation.hpp"
#include "../map/MazeMap.hpp"
 
class SimulationRobot : Robot {
public:
  SimulationRobot(Simulation &sim, MazeMap &maze);

  virtual bool isBlocked(Direction dir);

private:
  Simulation* sim;
  MazeMap* maze;
};
 
#endif /* SIMULATIONROBOT_HPP */
