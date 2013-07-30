#pragma once

class VirtualMaze {
	public:
		// Constructs a virtual maze from an array of maze nodes
		VirtualMaze(VirtualMazeNode* maze_nodes);

	private:
		VirtualMazeNode* maze_nodes;
}