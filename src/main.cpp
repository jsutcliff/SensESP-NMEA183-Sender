
#include "sensesp_app_builder.h"
#include "tcp_client.h"

using namespace sensesp;

ReactESP app;

void setup() {
  SensESPAppBuilder builder;
  sensesp_app = builder.set_hostname("sensesp-autopilot")->get_app();

#ifndef SERIAL_DEBUG_DISABLED
  SetupSerialDebug(115200);
#endif

  delay(1000);

  TCPClient *client = new TCPClient("leedee.local", 10110);

  sensesp_app->start();
}

void loop() { app.tick(); }