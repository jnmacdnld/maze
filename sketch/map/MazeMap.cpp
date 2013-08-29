#include "MazeMap.hpp"
#include <Arduino.h>
#include "Cell.hpp"

MazeMap::MazeMap(uint16_t (&horzWalls)[NUM_WALL_INTS],
                 uint16_t (&vertWalls)[NUM_WALL_INTS],
                 Cell &_goal) : goal(_goal) {
  size_t sizeOfWallArr = sizeof horzWalls[0] * NUM_WALL_INTS;

  memcpy(this->horzWalls, horzWalls, sizeOfWallArr);
  memcpy(this->vertWalls,  vertWalls, sizeOfWallArr);
}

bool MazeMap::getIsObstructed(Cell cell, Direction dir) {
  /*uint8_t row = cell

  if (dir == NORTH) {
    return bitRead(horzWalls[]);
  }*/
}

Cell MazeMap::getGoal() {
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
