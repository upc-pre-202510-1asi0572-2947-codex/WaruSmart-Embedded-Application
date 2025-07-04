#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_H

class WiFiConnection {
public:
    WiFiConnection(const char* ssid, const char* password);
    void connect();

private:
    const char* ssid;
    const char* password;
};

#endif
