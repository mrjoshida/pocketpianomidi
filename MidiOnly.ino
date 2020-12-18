#include <Control_Surface.h> // Include the Control Surface library

CD74HC4051 mux0 = {7, {4, 3, 2}};
CD74HC4051 mux1 = {6, {4, 3, 2}};
CD74HC4051 mux2 = {5, {4, 3, 2}};

void setup() {
  Control_Surface.begin();  // Initialize the Control Surface
}
 
void loop() {
  Control_Surface.loop();  // Update the Control Surface
}
