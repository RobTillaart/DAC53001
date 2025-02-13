//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2025-02-12
// PURPOSE: unit tests for the I2C DAC53001
//          https://github.com/RobTillaart/DAC53001
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


#include "Arduino.h"
#include "DAC53001.h"

// writing to a virtual device does not work
// as millis() function is not implemented in 
// the Arduino-CI environment


unittest_setup()
{
  fprintf(stderr, "DAC53001_LIB_VERSION: %s\n", (char *) DAC53001_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(test_constructor)
{
  DAC53001 dac(0x30);

  assertEqual(48, dac.getAddress());
  assertEqual( 0, dac.lastRead());
  assertEqual(1023, dac.getMaxValue());
  assertEqual( 1, dac.getChannels());
}


unittest_main()


//  -- END OF FILE --
