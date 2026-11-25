#ifndef ARGS_LENGTH_H
#define ARGS_LENGTH_H

#include <stdlib.h>
#include <stdio.h>

#define args_length(argc, filename)         \
  do                                        \
  {                                         \
    if ((argc) != 2)                        \
    {                                       \
      printf("usage %s <param>\n", filename); \
      exit(EXIT_FAILURE);                   \
    }                                       \
  } while (EXIT_SUCCESS)                    \

#endif