#include <err_reporting.h>

#include <arpa/inet.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void establish_crs_socket(uint16_t port_no) {
  int crs_socket, accepted_socket;
  struct sockaddr_in server_addr;
  char *buffer = (char *)malloc(sizeof(char) * 100);
  int bytes_recieved;
  int addr_len;

  if ((crs_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    report_error_die("Socket creation error");

  memset(&server_addr, 0, sizeof(server_addr));  
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port_no);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  addr_len = sizeof(server_addr);

  if (bind(crs_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    report_error_die("Could not bind!");

  if (listen(crs_socket, 15) == -1)
    report_error_die("Listen failed");

  // Let the server accept as many requests it can using accept() sys call
  while (1) {
    if ((accepted_socket = accept(crs_socket, (struct sockaddr *) &server_addr,
                                  (socklen_t *) &addr_len)) == -1)
      report_error_die("Error in accepting new connection");
 
   if ((bytes_recieved = recv(accepted_socket, buffer, sizeof(buffer), 0)) == -1)
      report_error_die("Error in recieving data");

    close(accepted_socket);
  }

  close(crs_socket);
  return; 
}
