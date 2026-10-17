#ifndef ESPVera_H
#define ESPVera_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <Preferences.h>

class ESPVera{
    public:
     ESPVera();
     void begin(const char* apName = "ESPVera");
     void loop();

    private:
    WebServer _server;
    Preferences _pref;
    void _startAP(const char* apName);
};
#endif
