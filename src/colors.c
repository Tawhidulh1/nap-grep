#include <stdio.h>
#include <string.h>

#define RESET "\033[0m"

/*
 * Prints str but indecies [start, end] are highlighted
 */
int printWithHighlight(char *str, int start, int end, char *color) {
  int i;
  for (i = 0; i < strlen(str); i++) {
    if (i >= start && i <= end) {
      printf("%s%c" RESET, color, str[i]);
      continue;
    }
    printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}
