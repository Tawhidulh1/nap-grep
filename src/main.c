#include "search.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void help();
int main(int argc, char *argv[]) {
  char *ngLogo = "\033[34m\n"
                 " ▀▄▄▄▄▄▄▄▀     ▀▄▄▄▄▄▄▄▀ \n"
                 "██▓██▀██▓██   ██▓██▀██▓██\n"
                 "█▓▒▓     ▓▒▓█ █▓▒▓     ▓▒▓█\n"
                 "█▒░▒▓   ▓▒░▒█ █▒░▒▓   ▓▒░▒█\n"
                 "█░ ░▓   ▓░ ░█ █░ ░▓   ▓░ ░█\n"
                 "██ ░░   ░░ ██  █ ░▒ ▄ ▒░ ██\n"
                 "▄▄▀▄▄   ▄▄▀▄▄   ▀▄▄▄■▄■░█░█\n"
                 "                  ▄▄  █▒█▒█\n"
                 "                ▄▄▀▀▄▄▄▓▄▀█\n"
                 "                 ▀  ▀▀▀▀▀▀ \033[0m\n";

  int opt;
  int longind;

  int amountSleep = 0;

  const struct option longopts[] = {{"help", no_argument, NULL, 'h'},
                                    {"sleep", no_argument, &amountSleep, 1},
                                    {"hidden", no_argument, &hideDotfiles, 0}};
  while ((opt = getopt_long(argc, argv, "h", longopts, &longind)) != -1) {
    switch (opt) {
    case ('h'):
      help();
      break;
    }
  }
  fputs(ngLogo, stdout);
  sleep(amountSleep);
  int numDirs = argc - optind - 1;
  char **dirs = &argv[optind + 1];

  char *val = NULL;
  val = argv[optind];
  if (val != NULL) {
    search(val, dirs, numDirs);
  }

  return 0;
}

void help() {
  char *help =
      "nap-grep\n"
      "Tawhidul Hasan <Tawhidulh1@gmail.com>\n"
      "\n"
      "nap-grep(ng) is a tool that recursively searches directories (defaulted "
      "to the current directory)\n and looks for a pattern.\n"
      "\n"
      "Project git page: https://github.com/tawhidulh1/nap-grep\n"
      "\n"
      "USAGE: \n"
      "	ng PATTERN [DIRS] [OPTIONS] [FLAGS]\n"
      "\n"
      "POSITIONAL ARGUMENTS:\n"
      "	<PATTERN>	An expression that can be expressed as a String that "
      "is used for searching\n"
      "	<DIRS>		A(n)(optional) directory to search in\n"
      "\n"
      "EXTRA:\n"
      "	-h or --help	Brings up help message\n"
      "	--sleep	Makes the program sleep during start to show logo, does not "
      "work during help flag/option\n";
  printf("%s\n", help);
  exit(0);
}
