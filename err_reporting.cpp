#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void report_error_die(char * err_string) {
  perror(err_string);
  exit(-1);
}
