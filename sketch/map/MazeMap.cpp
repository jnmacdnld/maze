#include "MazeMap.hpp"

MazeMap::MazeMap(uint16_t (&horzWalls)[NUM_WALL_INTS],
                 uint16_t (&vertWalls)[NUM_WALL_INTS],
                 uint8_t goal) {
  size_t sizeOfWallArr = sizeof horzWalls[0] * NUM_WALL_INTS;

  memcpy(this->horzWalls, horzWalls, sizeOfWallArr);
  memcpy(this->vertWalls,  vertWalls, sizeOfWallArr);
  this->goal = goal;
}

bool MazeMap::getIsObstructed(uint8_t node, Direction dir) {

}

uint8_t MazeMap::getGoal() {
  return goal;
}

void MazeMap::initArrFromHorzWalls(uint16_t (&arr)[NUM_WALL_INTS]) {
  size_t sizeOfWallArr = sizeof arr[0] * NUM_WALL_INTS;
  memcpy(arr, horzWalls, sizeOfWallArr);
}

void MazeMap::initArrFromVertWalls(uint16_t (&arr)[NUM_WALL_INTS]) {
  size_t sizeOfWallArr = sizeof arr[0] * NUM_WALL_INTS;
  memcpy(arr, vertWalls, sizeOfWallArr);
}
