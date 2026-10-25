#include "search.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

int hideDotfiles = 1;

int search(char *str, char **dirs, int numDirs, int dotfilesHidden) {
  hideDotfiles = dotfilesHidden;
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

    char path[4096];
    snprintf(path, sizeof(path), "%s/%s", directory, dirp->d_name);
    // Update this later:
    if (dirp->d_type == DT_DIR) {
      search_for_files_containing(str, path);
      dirp = readdir(workingDir);
      continue;
    }

    FILE *fp;
    fp = fopen(path, "r");
    if (fp == NULL) {
      return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
      char *pChar = strstr(line, str);
      if (pChar != NULL) {
        printf("%s: %s\n", path, line);
      }
    }
    fclose(fp);
    dirp = readdir(workingDir);
  }
  closedir(workingDir);
  return 0;
}
