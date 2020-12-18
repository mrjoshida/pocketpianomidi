#include <Control_Surface.h>

#define PP_LED 8   // LED on pocket piano

// Instantiate a MIDI Debug interface at 115200 baud.
USBDebugMIDI_Interface midi = 115200;

using namespace MIDI_Notes;

CD74HC4051 mux0 = {7, {4, 3, 2}};
CD74HC4051 mux1 = {6, {4, 3, 2}};
CD74HC4051 mux2 = {5, {4, 3, 2}};

NoteButtons<24> noteButtons = {
  copyAs<Button>(cat(mux0.pins(),cat( mux1.pins(), mux2.pins()))),
  {60, CHANNEL_1},              // base address
  {1, 0},                       // address increment
};

CCPotentiometer volumePots[] = {
    { A0, {MIDI_CC::Channel_Volume, CHANNEL_1} },
    { A1, {MIDI_CC::Channel_Volume, CHANNEL_2} },
    { A2, {MIDI_CC::Channel_Volume, CHANNEL_3} }
};

void setup() {
  Control_Surface.begin();
}
 
void loop() {
  Control_Surface.loop();  // Update the Control Surface
}
