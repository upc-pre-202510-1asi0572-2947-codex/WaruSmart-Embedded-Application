#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_H

/**
 * @class WiFiConnection
 * @brief Class to manage WiFi connection.
 *
 * This class provides functionality to connect to a WiFi network using the
 * provided SSID and password.
 */
class WiFiConnection {
public:
    /**
     * @brief Constructor to initialize WiFi connection parameters.
     *
     * @param ssid The SSID of the WiFi network.
     * @param password The password of the WiFi network.
     */
    WiFiConnection(const char* ssid, const char* password);

    /**
     * @brief Connects to the WiFi network using the provided credentials.
     *
     * This method starts the connection process and blocks execution until
     * a successful connection is made.
     */
    void connect();

private:
    const char* ssid;     /**< WiFi network SSID */
    const char* password; /**< WiFi network password */
};

#endif
