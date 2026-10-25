#ifndef SEARCH_H
#define SEARCH_H

int search(char *str, char **dirs, int numDirs, int dotfilesHidden);
int search_for_files_containing(char *str, char *directory);

#endif
