#ifndef SEARCH_H
#define SEARCH_H

extern int hideDotfiles;

int search(char *str, char **dirs, int numDirs);
int search_for_files_containing(char *str, char *directory);

#endif
