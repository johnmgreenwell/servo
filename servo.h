//--------------------------------------------------------------------------------------------------------------------
// Name        : servo.h
// Purpose     : Servo driver class
// Description : 
//               This class intended for device driver control of 'hobby-style' 'RC' servos.
//
// Language    : C++
// Platform    : Portable
// Framework   : Portable
// Copyright   : MIT License 2024, John Greenwell
// Requires    : External : N/A
//               Custom   : hal.h - Custom implementation-defined Hardware Abstraction Layer
//--------------------------------------------------------------------------------------------------------------------
#ifndef _SERVO_H
#define _SERVO_H

#include "hal.h"

namespace PeripheralIO
{

class Servo 
{
    public:

        /**
         * @brief Constructor for Servo object
         * @param pwm_pin Pin reference number to which HAL will drive PWM
        */
        Servo(uint8_t pwm_pin);

        /**
         * @brief Write an angle to the servo
         * @param angle Angle to which servo will be driven
        */
        void write(uint8_t angle);

        /**
         * @brief Read angle from servo
         * @return Angle to which servo is currently being driven (not guaranteed that servo has reached this angle)
        */
        uint8_t read() const;

        /**
         * @brief Write microseconds PWM pulse to servo
         * @param us Microseconds delay within PWM signal applied to servo
         */
        void writeMicroseconds(uint32_t us);

        /**
         * @brief Read microseconds PWM delay currently written to servo
         */
        uint32_t readMicroseconds() const;
 
private:
    HAL::PWM _pwm;
    uint8_t  _angle;
    uint32_t _us;

};

}

#endif // _SERVO_H

// EOF
