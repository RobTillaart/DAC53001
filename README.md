
[![Arduino CI](https://github.com/RobTillaart/DAC53001/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/DAC53001/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/DAC53001/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/DAC53001/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/DAC53001/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/DAC53001.svg)](https://github.com/RobTillaart/DAC53001/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/DAC53001/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/DAC53001.svg?maxAge=3600)](https://github.com/RobTillaart/DAC53001/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/DAC53001.svg)](https://registry.platformio.org/libraries/robtillaart/DAC53001)


# DAC53001

Arduino library for I2C DAC53001 10 bit DAC.


### Description

**Experimental** + **Work in progress**

Function names / API still can change.


**Warning:** This library is not tested with hardware yet. 
So use with care, feedback welcome.

The DAC63001, DAC63002, DAC53001, and DAC53002 are a pin-compatible DACs.
They are low power, support voltage- and current-output, see table below.




TODO elaborate





|  device    |  bits  |  maxValue  |  channels  |  notes  |
|:----------:|:------:|:----------:|:----------:|:--------|
|  DAC53001  |   10   |    1023    |      1     |  base class
|  DAC53002  |   10   |    1023    |      2     |
|  DAC63001  |   12   |    4095    |      1     |
|  DAC63002  |   12   |    4095    |      2     |


### Please report your experiences.

If you have a DAC53001 device, please let me know your experiences
with the sensor and this (or other) library.


### Related

- https://github.com/RobTillaart/DAC8550
- https://github.com/RobTillaart/DAC8551
- https://github.com/RobTillaart/DAC8552
- https://github.com/RobTillaart/DAC8554
- https://github.com/RobTillaart/MCP_DAC
- https://github.com/RobTillaart/AD5680  (18 bit DAC)

There are more DAC libraries.



## I2C

Supports up to 1 MHz. To be verified.


### I2C multiplexing

Sometimes you need to control more devices than possible with the default
address range the device provides.
This is possible with an I2C multiplexer e.g. TCA9548 which creates up
to eight channels (think of it as I2C subnets) which can use the complete
address range of the device.

Drawback of using a multiplexer is that it takes more administration in
your code e.g. which device is on which channel.
This will slow down the access, which must be taken into account when
deciding which devices are on which channel.
Also note that switching between channels will slow down other devices
too if they are behind the multiplexer.

- https://github.com/RobTillaart/TCA9548



## Interface

```cpp
#include "DAC53001.h"
```

### Constructor

- **DAC53001(uint8_t address, TwoWire \* wire = &Wire)** set address and I2C bus.
- **DAC53002(uint8_t address, TwoWire \* wire = &Wire)** set address and I2C bus.
- **DAC63001(uint8_t address, TwoWire \* wire = &Wire)** set address and I2C bus.
- **DAC63002(uint8_t address, TwoWire \* wire = &Wire)** set address and I2C bus.
- **bool begin()** checks if address can be found on the I2C bus.
- **bool isConnected()** checks if address can be found on the I2C bus.
- **uint8_t getAddress()** returns address set.
- **uint16_t getMaxValue()** returns 1023 (10 bit) or 4095 (12 bit)
- **uint8_t getChannels()** returns 1 or 2


### Voltage reference

See datasheet page 58.

- **void setReference(DACX300X_reference mode, uint8_t channel = 0)**

|  Mode  |  Reference  |  Gain  |  notes  |
|:------:|:------------|:------:|:--------|
|  0x00  |  External   |   1x   |
|  0x01  |  VDD        |   1x   |
|  0x02  |  Internal1  |  1.5x  |
|  0x03  |  Internal2  |   2x   |
|  0x04  |  Internal3  |   3x   |
|  0x05  |  Internal4  |   4x   |


### Output mode

See datasheet page 62.

- **void setOutputMode(uint8_t mode, uint8_t channel = 0);
- **uint8_t getOutputMode(uint8_t channel = 0);

|  Mode  |  Vout                        |   Iout         |  notes  |
|:------:|:-----------------------------|:---------------|:--------|
|  0x00  |  NOT ALLOWED                 |   NOT ALLOWED  |  as both would be on.
|  0x01  |  power up                    |   power down   |
|  0x02  |  PowerDown + 10 kΩ to AGND   |   power up     |
|  0x03  |  PowerDown + 10 kΩ to AGND   |   power down   |
|  0x04  |  PowerDown + 100 kΩ to AGND  |   power up     |
|  0x05  |  PowerDown + 100 kΩ to AGND  |   power down   |
|  0x06  |  PowerDown + Hi-Z to AGND    |   power up     |
|  0x07  |  PowerDown + Hi-Z to AGND    |   power down   |  default 


### setDAC

See datasheet page 62.

- **uint16_t setDAC(uint16_t value, uint8_t channel = 0)** 


### General status

See datasheet page 65.

- **uint16_t getStatus()** returns bit mask.

To elaborate meaning bits in table.


### Error handling

- **uint16_t lastError()** returns last error and resets to OK.

To add table of error codes.



## Future

#### Must

- improve documentation
- test with hardware

#### Should

- replace magic numbers by defines (const int);

#### Could

- add examples
- add more error handling
  - channel > # channels
  - incorrect mode

#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,

