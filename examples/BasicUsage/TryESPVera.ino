#include <ESPVera.h>

ESPVera ESPVera;

void setup(){
    Serial.begin(115200);
    ESPVera.begin("MyESPAP");
}

void loop(){
    ESPVera.loop();
}