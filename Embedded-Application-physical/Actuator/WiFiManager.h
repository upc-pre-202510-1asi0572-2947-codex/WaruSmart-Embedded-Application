#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <WiFi.h>

/**
 * @class WiFiManager
 * @brief Class to manage Wi-Fi connection and retrieve device IP address.
 *
 * This class provides methods to connect to a Wi-Fi network and retrieve the
 * assigned IP address of the device.
 */
class WiFiManager {
public:
    /**
     * @brief Connects the device to the Wi-Fi network using predefined SSID and password.
     */
    void connect();

    /**
     * @brief Returns the local IP address assigned to the device.
     *
     * @return The IP address as a String.
     */
    String getIP();
};

#endif
