#include "tcp_client.h"

#include <functional>

namespace sensesp {

TCPClient::TCPClient(String address, uint16_t port, Stream *tx_stream, String config_path = "")
    : Configurable{config_path}, Startable(10) {
  address_ = address;
  port_ = port;
  tx_stream_ = tx_stream;

  client_ = new AsyncClient();
}

void TCPClient::start() {
  debugD("Start TCP on %s:%i", address_, port_);

  client_->onConnect([&](void *arg, AsyncClient *client) {
    debugD("TCP client connected to :%i", port_);
  }, client_);

  client_->onData([&](void *arg, AsyncClient *client, void *data, size_t len) {
    auto buf = (char *)data;

    tx_stream_.write((char *)data, len);

    debugD("TCP data:%s", buf);
  }, client_);

  if (!client_->connect(address_.c_str(), port_)) {
    debugD("Failed to start TCP on %s:%i", address_, port_);
  }
}

} // namespace sensesp