#include "Cell.hpp"

#include <Arduino.h>
#include <ArduinoUnit.h>

test(cellEquals) {
  Cell cellOne (0, 0);
  Cell cellTwo (0, 0);

  assertTrue(cellOne.equals(cellTwo));
}
