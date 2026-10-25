#include "search.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void help();
int main(int argc, char *argv[]) {
  int opt;
  // different from optind. the index of each longopt in the loop
  int longind;
  int dotfilesHidden = 1;
  const struct option longopts[] = {
      {"help", no_argument, NULL, 'h'},
      {"hidden", no_argument, &dotfilesHidden, 0}};
  while ((opt = getopt_long(argc, argv, "h", longopts, &longind)) != -1) {
    switch (opt) {
    case ('h'):
      help();
      break;
    }
  }
  int numDirs = argc - optind - 1;
  char **dirs = &argv[optind + 1];

  char *val = NULL;
  val = argv[optind];
  if (val != NULL) {
    search(val, dirs, numDirs, dotfilesHidden);
  }

  return 0;
}

void help() {
  printf("Usage: nap-grep [-h]\n");
  printf("Options:\n");
  printf("-h");
  exit(0);
}
