#include <ESPVera.h>
// CROS fixed
ESPVera ESPVera;

void setup(){
    Serial.begin(115200);
    ESPVera.begin("MyESPAP");
}

void loop(){
    ESPVera.loop();
}