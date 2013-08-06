#ifndef MAZEMAP_HPP
#define MAZEMAP_HPP

typedef uint8_t cell_t;

enum dir_t {
  NORTH,
  EAST,
  SOUTH,
  WEST
};
 
class MazeMap {
  public:
    MazeMap(uint16_t (&horzWalls)[15],
            uint16_t (&vertWalls)[15],
            uint8_t goal);

    bool getIsObstructed(cell_t cell, dir_t dir);

    uint8_t getGoal();

    void initArrFromHorzWalls(uint16_t (&arr)[15]);
    void initArrFromVertWalls(uint16_t (&arr)[15]);

  private:
    uint16_t horzWalls[15];
    uint16_t vertWalls[15];
    uint8_t goal;
};

#endif /* MAZEMAP_HPP */
