#include "MazeRobot.h"

MazeRobot::MazeRobot(MazeAlgorithm& algorithm) {
	setAlgorithm(algorithm);
}

MazeRobot::getAlgorithm() {
	return algorithm;
}

MazeRobot::setAlgorithm(MazeAlgorithm& algorithm) {
	this.algorithm = algorithm;
}

