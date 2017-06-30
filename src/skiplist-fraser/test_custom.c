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

#include <stdio.h>
#include <assert.h>
#include <pthread.h>
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

#define N_THREADS 1000

__thread unsigned long * seeds;

DS_TYPE * set;

void *
test(void * arg){
  ssalloc_init();
  seeds = seed_rand();

  DS_ADD(set, (skey_t) arg, NULL);

  return 0;
}


int
main(int argc, char **argv)
{
  levelmax = 10;
  size_pad_32 = 128;

  ssalloc_init();
  seeds = seed_rand();

  set = DS_NEW();
  assert(set != NULL);

  pthread_t ths[N_THREADS];
  int i;
  for (i = 0; i < N_THREADS; ++i)
  {
    pthread_create(&ths[i], 0, test, (void *) i);
  }

  for (i = 0; i < N_THREADS; ++i)
  {
    pthread_join(ths[i], 0);
  }

  printf("%u\n", DS_SIZE(set));

  return 0;
}
