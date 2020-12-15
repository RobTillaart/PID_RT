//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-15
// PURPOSE: unit tests for the PID_RT library
//          https://github.com/RobTillaart/PID_RT
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)

#include <ArduinoUnitTests.h>

#include "PID_RT.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_constructor)
{
  PID_RT PID();

  assertFalse(PID.isRunning());
  PID.start();
  assertTrue(PID.isRunning());
  PID.stop();
  assertFalse(PID.isRunning());

  assertEqual(0, PID.getSetPoint());
  PID.setPoint(152.45);
  assertEqual(152.45, PID.getSetPoint());

  assertFalse(PID.getReverse());
  PID.setReverse(true);
  assertTrue(PID.getReverse());
  PID.setReverse(false);
  assertFalse(PID.getReverse());

  assertEqual(100, PID.getInterval());
  PID.setInterval(125);
  assertEqual(125, PID.getInterval());
  
  assertEqual(0, PID.getOutputMin());
  assertEqual(100, PID.getOutputMax());
  PID.setOutputRange(125, 250);
  assertEqual(125, PID.getOutputMin());
  assertEqual(250, PID.getOutputMax());

  assertEqual(0, PID.getKp());
  assertEqual(0, PID.getKi());
  assertEqual(0, PID.getKd());
  PID.setK(3, 2, 1);
  assertEqual(3, PID.getKp());
  assertEqual(2, PID.getKi());
  assertEqual(1, PID.getKd());

  assertTrue(PID.isPropOnInput());
  assertFalse(PID.isPropOnError());
  
  PID.setPropOnError();
  assertFalse(PID.isPropOnInput());
  assertTrue(PID.isPropOnError());
  
  PID.setPropOnInput();
  assertTrue(PID.isPropOnInput());
  assertFalse(PID.isPropOnError());
}


unittest(test_)
{
  PID_RT PID();

  assertEqual(1, 1);
}

unittest_main()

// --------
