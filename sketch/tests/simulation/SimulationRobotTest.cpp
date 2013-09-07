#include "SimulationRobot.hpp"

#include "mazeText.hpp"

#include <ArduinoUnit.h>

class MoveTest {
public:
  MoveTest(uint8_t rowBefore,
           uint8_t colBefore,
           Direction moveDir,
           uint8_t rowAfter,
           uint8_t colAfter) :
  cellBefore( Cell(rowBefore, colBefore) ),
  cellAfter( Cell(rowAfter, colAfter) ),
  moveDir(moveDir) {

  }

public:
  Direction moveDir;
  Cell cellBefore;
  Cell cellAfter;
};

test(simRobotMove) {
  MoveTest tests[] = {
    MoveTest(1, 1, NORTH, 0, 1),
    MoveTest(1, 1, EAST,  1, 2),
    MoveTest(1, 1, SOUTH, 2, 1),
    MoveTest(1, 1, WEST,  1, 0),

    MoveTest(0, 0, WEST, 0, 0),
    MoveTest(0, 0, NORTH, 0, 0),
    MoveTest(15, 15, SOUTH, 15, 15),
    MoveTest(15, 15, EAST,  15, 15)
  };

  Simulation sim;
  SimulationRobot bot (SOUTH, sim, maze);

  int numTests = sizeof(tests) / sizeof(tests[0]);
  for (int i = 0; i < numTests; i++) {
    bot.setCurrentCell(tests[i].cellBefore);

    assertTrue( bot.getCurrentCell().equals(tests[i].cellBefore) );

    bot.move(tests[i].moveDir);

   /* bot.getCurrentCell().print();
    tests[i].cellAfter.print();*/

    assertTrue(bot.getFacingDirection() == tests[i].moveDir);
    assertTrue( bot.getCurrentCell().equals(tests[i].cellAfter) );
  }
}
