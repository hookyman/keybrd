/* test debounce() function.  16/6/1 Passed test for SAMPLE_COUNT 1, 2, and 4.
copied from keybrd/src/Row::debounce()

to run test:
    $ g++ debounce_unit_test.cpp
    $ ./a.out
*/
#include <inttypes.h>
#include <iostream>

#define SAMPLE_COUNT 4      //number of consecutive equal bits needed to change a debounced bit

uint8_t samples[SAMPLE_COUNT];                  //bitwise, one bit per key, most recent readings
uint8_t samplesIndex = 0;                       //samples[] current write index
uint8_t debounced = 0;                          //bitwise, one bit per key

uint8_t debounce(const uint8_t rowState)
{
    uint8_t all_1 = ~0;                         //bitwise
    uint8_t all_0 = 0;                          //bitwise

    //delayMicroseconds(DELAY_MICROSECONDS);    //delay between Row scans to debounce key

    samples[samplesIndex] = rowState;           //insert rowState into samples[] ring buffer

    if (++samplesIndex >= SAMPLE_COUNT)         //if end of ring buffer
    {
        samplesIndex = 0;                       //wrap samplesIndex to beginning of ring buffer
    }

    for (uint8_t j = 0; j < SAMPLE_COUNT; j++)  //traverse the sample[] ring buffer
    {
        all_1 &= samples[j];                    //1 if all samples are 1
        all_0 |= samples[j];                    //0 if all samples are 0
    }

    // update newDebounce if all the samples agree with one another
    // if all samples=1 then newDebounced=1
    //     elseif all samples=0 then newDebounced=0
    //         else newDebounced=debounced i.e. no change
    //return all_1 | (all_0 & debounced);
    debounced = all_1 | (all_0 & debounced);
    return debounced;
}

int main()
{
    //Test input and output only shows first bit of each byte.
    const uint8_t pressed[] = {1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0};
    const uint8_t bouncy[]  = {1,0,0,0,0,1,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0};
    const uint8_t SCAN_COUNT = sizeof(bouncy)/sizeof(*bouncy);
    uint8_t i;
    uint8_t newDebounced;

    std::cout << "button pressed:   ";
    for (i=0; i<SCAN_COUNT; i++)
    {
        std::cout << (int)pressed[i];
    }
    std::cout << std::endl;

    std::cout << "bouncy signal:    ";
    for (i=0; i<SCAN_COUNT; i++)
    {
        std::cout << (int)bouncy[i];
    }
    std::cout << std::endl;

    std::cout << "debounced signal: ";
    for (i=0; i<SCAN_COUNT; i++)
    {
        newDebounced = debounce(bouncy[i]);
        std::cout << (int)newDebounced;
    }
    std::cout << std::endl;
}

void loop() { }