#include "search.h"
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
  int numDirs = argc - optind - 1;
  char **dirs = &argv[optind + 1];

  char *val = NULL;
  val = argv[optind];
  if (val != NULL) {
    if (numDirs == 0) {
      search_for_files_containing(val, ".");
    } else {
      search(val, dirs, numDirs);
    }
    // search_for_files_containing(val, ".");
  }

  return 0;
}

void help() {
  printf("Usage: nap-grep [-h]\n");
  printf("Options:\n");
  printf("-h");
  exit(0);
}
