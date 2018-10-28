#include <client/query_socket.h>

#include <iostream>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
  // TODO: Implement download server

  if (argc != 8) {
    cout << "Usage : ./client client_alias client_ip client_port server_ip server_port downloading_port client_root" << endl;
  }

  char *crs_ip = argv[4];
  uint16_t crs_port_no = atoi(argv[5]);

  int sock_fd = connect_query_socket(crs_ip, crs_port_no);
  return 0;
}
