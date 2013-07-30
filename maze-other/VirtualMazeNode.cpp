#include "VirtualMazeNode.h"

VirtualMazeNode::VirtualMazeNode(bool northIsObstructed, bool eastIsObstructed,
																 bool southIsObstructed, bool westIsObstructed,
																 bool isStart, bool isFinish) {
	this.northIsObstructed = northIsObstructed;
	this.eastIsObstructed  = eastIsObstructed;
	this.southIsObstructed = southIsObstructed;
	this.westIsObstructed  = westIsObstructed;

	this.isStart  = isStart;
	this.isFinish = isFinish;
}

bool VirtualMazeNode::getIsObstructed(Direction dir) {
	switch (dir)
	{
	  case NORTH:
	    return northIsObstructed;
	    break;
	  case SOUTH:
	    return southIsObstructed;
	    break;
	  case EAST:
	  	return eastIsObstructed;
	  	break;
	  case WEST:
	  	return westIsObstructed;
	  	break;
	  default:
	    return false; // FIXME: should throw an exception
	  	break;
	}

	return false;
}

bool VirtualMazeNode::getIsStart() {
	return isStart;
}

bool VirtualMazeNode::getIsFinish() {
	return isFinish;
}

static VirtualMazeNode VirtualMazeNode::textfileToNodes(string path) {
	// FIXME: Implement
}
