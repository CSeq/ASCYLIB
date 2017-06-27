/*
 *   File: test_simple.c
 *   Author: Vasileios Trigonakis <vasileios.trigonakis@epfl.ch>
 *   Description:
 *   test_simple.c is part of ASCYLIB
 *
 * Copyright (c) 2014 Vasileios Trigonakis <vasileios.trigonakis@epfl.ch>,
 * 	     	      Tudor David <tudor.david@epfl.ch>
 *	      	      Distributed Programming Lab (LPD), EPFL
 *
 * ASCYLIB is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <assert.h>
#include <getopt.h>
#include <limits.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sched.h>
#include <inttypes.h>
#include <sys/time.h>
#include <unistd.h>
#include <malloc.h>
#include "utils.h"
#include "atomic_ops.h"
#include "intset.h"

/* ################################################################### *
 * Definition of macros: per data structure
 * ################################################################### */

#define DS_CONTAINS(s,k,t)  sl_contains(s, k)
#define DS_ADD(s,k,t)       sl_add(s, k, k)
#define DS_REMOVE(s,k,t)    sl_remove(s, k)
#define DS_SIZE(s)          sl_set_size(s)
#define DS_NEW()            sl_set_new()

#define DS_TYPE             sl_intset_t
#define DS_NODE             sl_node_t

__thread unsigned long * seeds;

int
main(int argc, char **argv)
{
  ssalloc_init();
  seeds = seed_rand();
  levelmax = 10;
  size_pad_32 = 128;

  DS_TYPE* set = DS_NEW();
  assert(set != NULL);

  DS_ADD(set, 1, NULL);
  DS_ADD(set, 2, NULL);

  DS_REMOVE(set, 2, NULL);

  printf("%u\n", DS_SIZE(set));

  return 0;
}
