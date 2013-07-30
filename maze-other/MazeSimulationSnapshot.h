class MazeSimulationSnapshot {
	public:
		MazeSimulationSnapshot(VirtualMaze& maze, MazeSimulationRobot& robot);
		~MazeSimulationSnapshot();

		string toString();

	private:
		VirtualMaze* maze;
		MazeSimulationRobot* robot;
}