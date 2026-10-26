#include "search.h"
#include "colors.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define RED "\033[31m"
#define GREEN "\033[32m"

#define RESET "\033[0m"

int hideDotfiles = 1;

int search(char *str, char **dirs, int numDirs) {
  if (numDirs == 0) {
    search_for_files_containing(str, ".");
    return 0;
  }
  int i;
  for (i = 0; i < numDirs; i++) {
    char *dir = dirs[i];
    search_for_files_containing(str, dir);
  }
  return 0;
}

int search_for_files_containing(char *str, char *directory) {
  DIR *workingDir = opendir(directory);

  if (workingDir == NULL) {
    return 1;
  }

  struct dirent *dirp = readdir(workingDir);

  while (dirp != NULL) {
    if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
      dirp = readdir(workingDir);
      continue;
    }
    if (hideDotfiles && dirp->d_name[0] == '.') {
      dirp = readdir(workingDir);
      continue;
    }

    if (dirp->d_type == DT_LNK) {
      dirp = readdir(workingDir);
      continue;
    }

    char path[4096];
    snprintf(path, sizeof(path), "%s/%s", directory, dirp->d_name);
    if (dirp->d_type == DT_DIR) {
      search_for_files_containing(str, path);
      dirp = readdir(workingDir);
      continue;
    }
    if (dirp->d_type == DT_UNKNOWN || dirp->d_type == DT_DIR) {
      struct stat stat;
      lstat(path, &stat);
      if (S_ISDIR(stat.st_mode)) {
        search_for_files_containing(str, path);
        dirp = readdir(workingDir);
        continue;
      }
    }

    FILE *fp;
    fp = fopen(path, "r");
    if (fp == NULL) {
      return 1;
    }

    char line[1024];
    int printedPath = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
      char *pChar = strstr(line, str);
      if (pChar != NULL) {
        char *pLine = line;
        if (!printedPath) {
          printf(GREEN "%s:" RESET "\n", path);
          printedPath = 1;
        }
        printWithHighlight(line, pChar - pLine,
                           (pChar - pLine) + strlen(str) - 1, RED);
      }
    }
    fclose(fp);
    dirp = readdir(workingDir);
  }
  closedir(workingDir);
  return 0;
}
