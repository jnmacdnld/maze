#pragma once

class MazeSimulation {
	public:
		// Constructs a new maze, initializes the mazeSnapshots array, makes a 
		// new robot, and runs the robot through the maze, thus populating the list 
		// of MazeSnapshots
		MazeSimulation(VirtualMaze& maze);

		~MazeSimulation()
		
	private:
		VirtualMaze* maze;
		MazeSimulationSnapshot* snapshots;

		MazeSimulationRobot* robot;
}