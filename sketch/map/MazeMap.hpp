#ifndef MAZEMAP_HPP
#define MAZEMAP_HPP

#include "Cell.hpp"

enum Direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};
 
class MazeMap {
public:
  MazeMap(uint16_t (&horzWalls)[15],
          uint16_t (&vertWalls)[15],
          Cell &goal);

  bool isBlocked(Cell cell, Direction dir);

  Cell getGoal();

  void initArrFromHorzWalls(uint16_t (&arr)[15]);
  void initArrFromVertWalls(uint16_t (&arr)[15]);

private:
  uint16_t horzWalls[15];
  uint16_t vertWalls[15];
  Cell goal;
};

#endif /* MAZEMAP_HPP */
