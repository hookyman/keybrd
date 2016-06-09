#ifndef ROW_H
#define ROW_H

#include <RowBase.h>
#include <RowScanner_PinsArray.h>
#include <Debouncer_4Samples.h>

/*
Configuration
-------------

Instantiation
-------------
 todo - see Row_DH
*/
class Row : public RowBase
{
    private:
        RowScanner_PinsArray scanner;
        Debouncer_4Samples debouncer;
    public:
        //Row constructor was like Row_DH constructor
        Row(const uint8_t strobePin, const uint8_t readPins[], const uint8_t READ_PIN_COUNT,
                Key *const ptrsKeys[])
            : RowBase(ptrsKeys), scanner(strobePin, readPins, READ_PIN_COUNT) { }
        virtual void process();
};
#endif
