
#include "sensesp_app_builder.h"
#include "tcp_client.h"

#include <SoftwareSerial.h>

using namespace sensesp;

ReactESP app;
SoftwareSerial swSer;

constexpr int NMEATxPin = 13;

void setup() {
  SensESPAppBuilder builder;
  sensesp_app = builder.set_hostname("sensesp-autopilot")->get_app();

#ifndef SERIAL_DEBUG_DISABLED
  SetupSerialDebug(115200);
#endif

  swSer.begin(4800, SERIAL_8N1, -1, NMEATxPin, false, 256);

  TCPClient *client = new TCPClient("leedee.local", 10110, &swSer);

  sensesp_app->start();
}

void loop() { app.tick(); }