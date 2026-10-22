#include <stdio.h>

void help();
int main(int argc, char *argv[]) {
  int i;
  for (i = 1; i < argc; i++) {
    if (sizeof(argv[i]) < 2) {
      continue;
    }
    char firstChar = argv[i][0];
    char secondChar = argv[i][1];
    if (firstChar == '-') {
      switch (secondChar) {
      case ('h'):
        help();
      }
    }
  }

  return 0;
}

void help() { printf("printing help\n"); }
