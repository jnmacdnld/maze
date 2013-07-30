#pragma once

#include "Direction.cpp"

class MazeRobot {
	public:
		MazeRobot(MazeAlgorithm& algorithm);
		~MazeRobot();
		virtual void moveToAdjacentCell(Direction dir) = 0;
		virtual bool getIsObstructed(Direction dir) = 0;
		virtual void solveMaze() = 0;

		MazeAlgorithm getAlgorithm();
		void setAlgorithm(MazeAlgorithm& algorithm);

	private:
		MazeAlgorithm* algorithm;
}