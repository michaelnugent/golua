#include <stdio.h>
#include "lua-host.h"

int main(int argc, char **argv) {
  printf("calling: %s\n", argv[1]);
  call_lua(argv[1]);
}


