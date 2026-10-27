This is C++ code for an Arduino or ESP32 to be used as a strobe light to check the speed of vinyl record players.

I wrote this because one day I noticed my record player was playing slightly too fast.  A pdf download of a strobe mat,
one LED, a 120ohm  resistor and an ESP32 Super Mini H2 and I had my record player back at the correct speed.

This code uses timerAlarms as interrupts. It is possible to write similar code using just the loop function of the
arduino/esp32 but I found this unreliable - particularly with small ESP32 devices; the strobe light was not
consistent. timerAlarms and interrupts ensure a smooth consistent strobe effect and has the added advantage that it is
relatively straight forward to adjust the code for 60Hz running; I'm a Brit and only think in terms of 50Hz.

Normalblaster
