#ifndef CLARGS_H
#define CLARGS_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

// This library returns a lot of values which are pointers to the strings in
// 'argv.' It's recommended to not free 'argv' until you have also finished
// with the list returned by 'simplify_args'

// TODO add ways to free memory assigned through alloc functions

typedef struct flag {
	char shortname;
	char *longname;
	bool takesarg;
} Flag;

typedef struct arg {
	char flag;
	char *str;
} Arg;

typedef vec(Arg) SArgV;
SArgV mksargs(int argc, char *argv[], Flag flist[], int flist_length);

#endif
