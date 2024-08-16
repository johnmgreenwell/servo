//--------------------------------------------------------------------------------------------------------------------
// Name        : servo.cpp
// Purpose     : Servo driver class
// Description : This class intended for device driver control of 'hobby-style' 'RC' servos.
// Language    : C++
// Platform    : Portable
// Framework   : Portable
// Copyright   : MIT License 2024, John Greenwell
//--------------------------------------------------------------------------------------------------------------------

#include "servo.h"

namespace PeripheralIO 
{

const uint32_t SERVO_FREQUENCY_HZ  = 50u;
const uint8_t  SERVO_MAX_ANGLE    = 180u;
const uint32_t SERVO_MAX_US       = 2000u;
const uint32_t SERVO_MIN_US       = 1000u;
const uint32_t SERVO_BASE_US      = SERVO_MAX_US - SERVO_MIN_US;
const float    SERVO_BASE_PERCENT = 5.0f;

Servo::Servo(uint8_t pwm_pin)
: _pwm(pwm_pin)
, _angle(SERVO_MAX_ANGLE / 2)
, _us(SERVO_MIN_US + ((SERVO_MAX_US - SERVO_MIN_US) / 2))
{ }

void Servo::write(uint8_t angle)
{
    float duty;

    if (angle > SERVO_MAX_ANGLE)
    {
        angle = SERVO_MAX_ANGLE;
    }

    duty = SERVO_BASE_PERCENT + (((float)angle/(float)SERVO_MAX_ANGLE) * SERVO_BASE_PERCENT);
    _pwm.set(SERVO_FREQUENCY_HZ, duty);
    _angle = angle;
}

uint8_t Servo::read() const
{
    return _angle;
}

void Servo::writeMicroseconds(uint32_t us)
{
    float duty;

    if (us < SERVO_MIN_US)
    {
        us = SERVO_MIN_US;
    }
    else if (us > SERVO_MAX_US)
    {
        us = SERVO_MAX_US;
    }

    duty = SERVO_BASE_PERCENT + ((((float)(us - SERVO_MIN_US)/(float)(SERVO_BASE_US))) * SERVO_BASE_PERCENT);
    _pwm.set(SERVO_FREQUENCY_HZ, duty);
    _us = us;
}

uint32_t Servo::readMicroseconds() const
{
    return _us;
}

}

// EOF
