#ifndef SIMULATIONROBOT_HPP
#define SIMULATIONROBOT_HPP

#include "RobotBase.hpp"
#include "Simulation.hpp"
#include "MazeMap.hpp"
 
class SimulationRobot : RobotBase {
public:
  SimulationRobot(Simulation &sim, MazeMap &maze);

  virtual bool getIsBlocked(Direction dir);

private:
  Simulation* sim;
  MazeMap* maze;
};
 
#endif /* SIMULATIONROBOT_HPP */
