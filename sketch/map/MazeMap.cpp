#include "MazeMap.hpp"

MazeMap::MazeMap(uint16_t (&horizWalls)[15], uint16_t (&vertWalls)[15],
                 uint8_t goal) {
  memcpy(this.horizWalls, horizWalls);
  memcpy(this.vertWalls,  vertWalls);
  this.goal = goal;
}

bool MazeMap::getIsObstructed(uint8_t node, Direction dir) {

}

uint8_t MazeMap::getGoal() {
  
}
