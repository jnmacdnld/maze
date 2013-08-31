#include "error.hpp"
#include "Arduino.h"

void error(const char* message) {
  Serial.println(message);
}

