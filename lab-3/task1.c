#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  const char * filename = argv[1];
  FILE *fp = fopen(filename, "a");
  if (fp == NULL) {
    printf("Cannot open file %s\n", filename);
    exit(1);
  }
  char str[4096];
  while (fgets(str, sizeof str, stdin)) {
    fputs(str, fp);
    fflush(fp);
  }
  fflush(fp);
  fclose(fp);
  return 0;
}
