#ifndef SIMULATIONROBOT_HPP
#define SIMULATIONROBOT_HPP

#include "RobotBase.hpp"
#include "Simulation.hpp"
#include "MazeMap.hpp"
 
class SimulationRobot : public RobotBase {
public:
  SimulationRobot(Direction dir, Simulation &sim, MazeMap &maze);

  void move(Direction dir);

  bool getIsBlocked(Direction dir);

private:
  Simulation* sim;
  MazeMap* maze;
};
 
#endif /* SIMULATIONROBOT_HPP */
