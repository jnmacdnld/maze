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

bool MazeMap::isBlocked(Cell cell, Direction dir) {
  uint8_t row = cell.getRow();
  uint8_t col = cell.getCol();

  if (col == 0 && dir == WEST || 
      row == 0 && dir == NORTH ||
      col == 15 && dir == EAST ||
      row == 15 && dir == SOUTH) {
    return true;
  }

  switch (dir) {
    case NORTH:
      return bitRead(horzWalls[row - 1], col);
    case SOUTH:
      return bitRead(horzWalls[row], col);
    case EAST:
      return bitRead(vertWalls[col], row);
    case WEST:
      return bitRead(vertWalls[col - 1], row);
  }

  // Should never be executed
  Serial.println("Invalid Direction passed to MazeMap::isBlocked");
  return false; 
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
