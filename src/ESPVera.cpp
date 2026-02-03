#include "ESPVera.h"

ESPVera::ESPVera() : _server(80) {}

void ESPVera::begin(const char* apName){
    _pref.begin("WiFi_cred", true);
    String SSID = _pref.getString("SSID", "");
    String password = _pref.getString("password", "");
    _pref.end();

    if(SSID.length() > 0){
        WiFi.begin(SSID.c_str(),password.c_str());

        unsigned long start = millis();
        while(WiFi.status() != WL_CONNECTED && millis() - start < 10000){
            delay(500);
            Serial.print(".");
        }

        if(WiFi.status() == WL_CONNECTED){
            Serial.println("Connected to WiFi");
            Serial.print("IP Address: ");
            Serial.println(WiFi.localIP());
        }
        else{
            Serial.println("Failed to connect to WiFi - Starting AP mode");
            _startAP(apName);
        }
    }
    else{
        _startAP(apName);
    }
}

void ESPVera::_startAP(const char* apName){
    WiFi.softAP(apName);
    Serial.println("Access Point started");
    Serial.println(WiFi.softAPIP());

    _server.on("/wifi", HTTP_POST,[this](){
        String getSSID = _server.arg("ssid");
        String getPassword = _server.arg("password");

        if(getSSID.length() > 0){
            _pref.begin("WiFi_cred",false);
            _pref.putString("SSID", getSSID);
            _pref.putString("password", getPassword);
            _pref.end();
            _server.send(200, "text/plain", "Credentials Saved. Rebooting...");
            delay(3000);
            ESP.restart();
        }
        else{
            _server.send(400, "text/plain", "SSID or Password cannot be empty");
        }
    });
    _server.begin();
}

void ESPVera::loop(){
    _server.handleClient();
}