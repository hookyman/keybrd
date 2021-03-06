/* keybrd_3c_sublayerNull.ino

This sketch:
    is firmware for layout with two layers plus one sublayer.
    runs on the first three columns of a breadboard keyboard

| Layout | **0** | **1** | **2** |
|:------:|:-----:|:-----:|:-----:|
|  **0** | a - 1 | b =   | c Num |
|  **1** | Alpha |  Sym  | Enter |

*/
// ################## GLOBAL ###################
// ================= INCLUDES ==================
//Keys
#include <Code_Sc.h>
#include <Code_Null.h>
#include <LayerState.h>
#include <Code_LayerLock.h>
#include <Code_LayerHold.h>
#include <Key_LayeredKeys.h>

//Matrix
#include <Row.h>
#include <Scanner_uC.h>
#include <ScanDelay.h>

// ============ SPEED CONFIGURATION ============
ScanDelay scanDelay(9000);

// ================== SCANNER ==================
uint8_t readPins[] = {14, 15, 16};
uint8_t readPinCount = sizeof(readPins)/sizeof(*readPins);

Scanner_uC scanner(LOW, readPins, readPinCount);

// =================== CODES ===================
enum layerIds { ALPHA, SYM, NUM };

LayerState groupState;

/*
groupState is assigned to layers ALPHA, SYM, and NUM.
*/
Code_LayerLock l_alpha(ALPHA, groupState);
Code_LayerLock l_sym(SYM, groupState);
Code_LayerHold l_num(NUM, groupState);

/*
groupState is assigned to Key_LayeredKeys.
When a Key_LayeredKeys object is pressed, groupState returns the active layerId.
Thus groupState manages a layer group delineated by all layers in Key_LayeredKeys objects.
*/
LayerStateInterface& Key_LayeredKeys::refLayerState = groupState;

// ----------------- SCANCODES -----------------
Code_Sc s_a(KEY_A);
Code_Sc s_b(KEY_B);
Code_Sc s_c(KEY_C);

Code_Sc s_minus(KEY_MINUS);
Code_Sc s_equal(KEY_EQUAL);
Code_Sc s_enter(KEY_ENTER);

Code_Sc s_1(KEY_1);
Code_Null code_null;

/* =================== KEYS ====================
The layout's Num layer only covers the first key: s_1
*/
Key* const ptrsKeys_00[] = { &s_a, &s_minus, &s_1 };
Key_LayeredKeys k_00(ptrsKeys_00);

/*
s_equal is duplicated in layer 2.
*/
Key* const ptrsKeys_01[] = { &s_b, &s_equal, &s_equal };
Key_LayeredKeys k_01(ptrsKeys_01);

/*
code_null occupies layer 2.  Class Code_Null doesn't do anything.
It is useful for blank codes.  Remember to fill all layers of a Key_Layered object with codes.
If the code_null were omitted from the array, dereferencing ptrsKeys_02[2] could cause a crash.
*/
Key* const ptrsKeys_02[] = { &s_c, &l_num, &code_null };
Key_LayeredKeys k_02(ptrsKeys_02);

// =================== ROWS ====================
Key* const ptrsKeys_0[] = { &k_00, &k_01, &k_02 };
uint8_t keyCount_0 = sizeof(ptrsKeys_0)/sizeof(*ptrsKeys_0);
Row row_0(scanner, 0, ptrsKeys_0, keyCount_0);

Key* const ptrsKeys_1[] = { &l_alpha, &l_sym, &s_enter };
uint8_t keyCount_1 = sizeof(ptrsKeys_1)/sizeof(*ptrsKeys_1);
Row row_1(scanner, 1, ptrsKeys_1, keyCount_1);

// ################### MAIN ####################
void setup()
{
}

void loop()
{
    row_0.process();
    row_1.process();
    scanDelay.delay();
}
