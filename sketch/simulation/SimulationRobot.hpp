#ifndef SIMULATIONROBOT_HPP
#define SIMULATIONROBOT_HPP

#include "Robot.hpp"
#include "Simulation.hpp"
#include "MazeMap.hpp"
 
class SimulationRobot : Robot {
public:
  SimulationRobot(Simulation &sim, MazeMap &maze);

  virtual bool getIsBlocked(Direction dir);

private:
  Simulation* sim;
  MazeMap* maze;
};
 
#endif /* SIMULATIONROBOT_HPP */
