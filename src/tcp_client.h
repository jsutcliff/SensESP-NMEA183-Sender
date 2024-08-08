#ifndef _tcp_client_H_
#define _tcp_client_H_

#include "sensesp/system/configurable.h"
#include "sensesp/system/observable.h"
#include "sensesp/system/startable.h"
#include "sensesp/system/valueproducer.h"

#include <AsyncTCP.h>

namespace sensesp {

class TCPClient : public Configurable, public Startable, public ValueProducer<String> {
public:
  TCPClient(String address, uint16_t port, String config_path = "");
  virtual void start() override final;

private:
  String address_;
  uint16_t port_;
  AsyncClient *client_;
};

} // namespace sensesp

#endif