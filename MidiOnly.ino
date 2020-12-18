#include <Control_Surface.h>

// Instantiate a MIDI Debug interface at 115200 baud.
USBDebugMIDI_Interface midi = 115200;

using namespace MIDI_Notes;

CD74HC4051 mux0 = {7, {4, 3, 2}};
CD74HC4051 mux1 = {6, {4, 3, 2}};
CD74HC4051 mux2 = {5, {4, 3, 2}};

Transposer<-12, +12> transposer;

NoteButtons<24> notebuttons = {
  transposer, 
  {
    mux0.pin)(0), mux0.pin)(1), mux0.pin)(2), mux0.pin)(3),
    mux0.pin)(4), mux0.pin)(5), mux0.pin)(6), mux0.pin)(7),
    mux1.pin)(0), mux1.pin)(1), mux1.pin)(2), mux1.pin)(3),
    mux1.pin)(4), mux1.pin)(5), mux1.pin)(6), mux1.pin)(7), 
    mux2.pin)(0), mux2.pin)(1), mux2.pin)(2), mux2.pin)(3),
    mux2.pin)(4), mux2.pin)(5), mux2.pin)(6), mux2.pin)(7)
  },
  {60, CHANNEL_1},              // base address
  {1, 0},                       // address increment
};

void setup() {
  mux0.begin();                  // Initialize multiplexers
  mux1.begin();
  mux2.begin();
  mux0.pinMode(0, INPUT_PULLUP);
  mux1.pinMode(0, INPUT_PULLUP);
  mux2.pinMode(0, INPUT_PULLUP);
  
  Control_Surface.begin();
}
 
void loop() {
  Control_Surface.loop();  // Update the Control Surface
}
