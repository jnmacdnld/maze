#ifndef MAZEMAP_HPP
#define MAZEMAP_HPP

#include "Direction.hpp"
 
class MazeMap {
  public:
    MazeMap(uint16_t (&horzWalls)[15],
            uint16_t (&vertWalls)[15],
            uint8_t goal);

    bool getIsObstructed(uint8_t node, Direction dir);

    uint8_t getGoal();
    uint16_t* getHorzWallsPtr();
    uint16_t* getVertWallsPtr();

  private:
    uint16_t horzWalls[15];
    uint16_t vertWalls[15];
    uint8_t goal;
};

#endif /* MAZEMAP_HPP */
