class SimulationRobot : Robot {
public:
  SimulationRobot(Simulation &sim, MazeMap &maze);

private:
  Simulation sim;
  MazeMap maze;
};
