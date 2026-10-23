#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void help();
int main(int argc, char *argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "h")) != -1) {
    switch (opt) {
    case ('h'):
      help();
      break;
    }
  }
  char *val = NULL;
  val = argv[optind];
  if (val != NULL) {
  }

  /*
  int i;
  for (i = optind; i < argc; i++) {}
  */

  return 0;
}

void help() {
  printf("Usage: nap-grep [-h]\n");
  printf("Options:\n");
  printf("-h");
  exit(0);
}
