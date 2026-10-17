# ESPVera

**ESPVera** is a lightweight and easy-to-use Wi‑Fi manager for the ESP32. It automatically connects using stored credentials and falls back to a **configurable Access Point (AP) mode** when no credentials are available or the connection fails.

---

## 🚀 Features

- ✅ **Automatic connection** using stored credentials in NVS (Non‑Volatile Storage)
- ✅ **AP fallback mode** when Wi‑Fi is unavailable or credentials are missing
- ✅ **Persistent storage** using the Arduino `Preferences` library
- ✅ **Built-in web API** (`/wifi`) for updating SSID/password via HTTP POST
- ✅ **Minimal integration**: just a few lines of code to get started

---

## 🧠 How it works

1. **Initialization**: The library checks for stored Wi‑Fi credentials.
2. **Connection attempt**: It tries to connect to the saved SSID for a configurable timeout (default: 10s).
3. **Fallback**: If connection fails, it starts an AP (default SSID: `ESPVera` or custom name).
4. **Configure**: While in AP mode, you can POST new credentials to `/wifi`. The library saves them and reboots.

---

## 💻 Quick Start

### 1) Include and initialize

```cpp
#include <ESPVera.h>

ESPVera myVera;

void setup() {
  Serial.begin(115200);

  // Start ESPVera with a custom AP name
  myVera.begin("MyESP32-Setup");
}

void loop() {
  // Keep the web server alive in AP mode
  myVera.loop();
}
```

### 2) Update credentials via web API

When the device is in AP mode, send an HTTP POST request to:

```
http://192.168.4.1/wifi
```

#### POST parameters (form-encoded)
- `ssid` — Your Wi‑Fi network name
- `password` — Your Wi‑Fi password

Example (curl):

```sh
curl -X POST http://192.168.4.1/wifi \
  -F "ssid=MyNetwork" \
  -F "password=MySecretPassword"
```

---

## 🗂️ Library Structure

- `src/ESPVera.h` — Public API, class definitions, and required includes
- `src/ESPVera.cpp` — Wi‑Fi management, NVS storage, and embedded web server logic
- `library.properties` — Arduino Library Manager metadata

---

## 📦 Installation

### Option A: Install via Arduino IDE (ZIP)
1. Download the repository as a ZIP.
2. In Arduino IDE: **Sketch → Include Library → Add .ZIP Library...**
3. Select the downloaded ZIP.

### Option B: Install manually
1. Copy the contents of this repository into your Arduino `libraries/` folder.
2. Restart the Arduino IDE.

---

## 📝 Notes

- The default AP SSID is `ESPVera`, but you can pass a custom name to `begin()`.
- Stored credentials are handled by the `Preferences` library, so they survive reboots.

---

## 📄 License

This project is maintained by **Laksindu Janith**.
