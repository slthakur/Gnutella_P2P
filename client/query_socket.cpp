#include <err_reporting.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

int connect_query_socket(char *crs_ip, uint16_t crs_port) {
  struct sockaddr_in crs_addr;
  int query_socket;

  if ((query_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    report_error_die("Query socket creation failed");

  memset(&crs_addr, 0, sizeof(crs_addr));
  crs_addr.sin_family = AF_INET;
  crs_addr.sin_addr.s_addr = inet_addr(crs_ip);
  crs_addr.sin_port = htons(crs_port);

  if (connect(query_socket, (struct sockaddr *)&crs_addr, sizeof(crs_addr)) == -1)
    report_error_die("Failed to connect");

  return query_socket;
}
