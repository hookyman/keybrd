#ifndef PORTREAD_PCA9655E_H
#define PORTREAD_PCA9655E_H
#include <Arduino.h>
#include <inttypes.h>
#include <Wire.h>
#include <PortRead.h>
#include "PortIOE.h"

/* One PCA9655E I/O expander port connected to matrix columns.
PCA9655E does not have internal pull-up resistors (PCA9535E does).

Instantiation
 ------------
READ_PINS parameter is port's bitwise pin configuration
    1=configure as input (for pins connected to column)
    0=configure as output (for LED or not connected to a column)

Example instantiation for column port 0, with pins 2 and 3 connected to columns:
    PortIOE port0(0, 0);
    PortRead_PCA9655E colPort0(port0, 2<<0 | 1<<3 );
Example instantiation for column port 1, with pins 2 and 3 connected to columns:
    PortIOE port1(1, 0);
    PortRead_PCA9655E colPort1(port1, 2<<0 | 1<<3 );

READ_PINS are read from pin 0 on up.

Diode orientation
 ----------------
Rows, columns, and diode orientation are explained in Matrix.h
*/
class PortRead_PCA9655E : public PortRead
{
    private:
        PortIOE& port;
        const uint8_t configurationByteCommand;
        const uint8_t inputByteCommand;
    public:
        //The constructor initialization list is in .cpp
        PortRead_PCA9655E(PortIOE& port, const uint8_t READ_PINS);
        void begin();

        //read port and store result in portState
        virtual uint8_t read();
};
#endif