# Servo Driver

Portable, multi-instance servo driver.

## Overview

This HAL-mediated custom servo driver permits ease of use that is designed to be platform-independent.

## Usage

The implementation relies on an external user-defined hardware abstraction layer (HAL) called `hal.h` which defines the necessary calls in the `HAL` namespace. Namely, a PWM object which sets a PWM waveform on a particular pin at a particular frequency in Hz and duty cycle integer.

The HAL PWM object takes an identifying pin integer at initialization and has a PWM method taking the following format:
* void set(uint32_t freq, float duty)

### Example

```cpp
#include "servo.h"

...

// Instantiate Servo object
PeripheralIO::Servo servo(PIN_A2);

...

int main()
{
    uint8_t angle;

...

    // Apply desired servo angle
    servo.write(angle);

...

}

...
```

## License

MIT © 2024 John Greenwell