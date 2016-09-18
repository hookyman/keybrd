#include "Key_LayeredCodeScBase.h"

void Key_LayeredCodeScBase::pressCode()
{
    if (layer)
    {
        Keyboard.press(scancode1);
    }
    else
    {
        refCode0.press();
    }
}

void Key_LayeredCodeScBase::release()
{
    if (layer)
    {
        Keyboard.release(scancode1);
    }
    else
    {
        refCode0.release();
    }
}