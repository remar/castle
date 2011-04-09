#include "debug.h"

#include <stdio.h>
#include <string.h>

#include <rage.h>
extern Rage rage;

void display_error(const char *file, int line)
{
  consoleDemoInit();

  char *pos = strrchr(file, '/');

  if(pos == NULL)
    pos = (char *)file;
  else
    pos++; // Skip '/'

  printf("[%s:%d]\n", pos, line);
  printf("Error: %s\n", rage.getErrorString());
  while(1);
}
