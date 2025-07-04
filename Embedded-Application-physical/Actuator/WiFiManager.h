#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <WiFi.h>

class WiFiManager {
public:
    void connect();
    String getIP();
};

#endif
