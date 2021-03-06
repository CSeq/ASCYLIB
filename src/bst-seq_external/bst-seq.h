/*
 *   File: bst-seq.h
 *   Author: Vasileios Trigonakis <vasileios.trigonakis@epfl.ch>
 *   Description:
 *   bst-seq.h is part of ASCYLIB
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


#ifndef _H_BST_SEQ_
#define _H_BST_SEQ_

#include <assert.h>
#include <getopt.h>
#include <limits.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>

//#include "atomic_ops.h"
#include "atomic_ops_if.h"
#include "lock_if.h"

#include "common.h"
#include "utils.h"
#include "measurements.h"
#include "ssalloc.h"
#include "ssmem.h"

#define DEFAULT_ALTERNATE		0
#define DEFAULT_EFFECTIVE		1

static volatile int stop;
extern __thread ssmem_allocator_t* alloc;

typedef struct node
{
  skey_t key;
  union
  {
    sval_t val;
    uint64_t leaf;
  };
  volatile struct node *left;
  volatile struct node *right;
} node_t;

typedef struct rnode
{
  skey_t key;
  volatile struct node *left;
  volatile struct node *right;
  char padding[32-2*sizeof(uintptr_t)-sizeof(key_t)];
} rnode_t;

typedef ALIGNED(CACHE_LINE_SIZE) struct intset
{
  node_t* head;
} intset_t;

node_t* new_node(skey_t key, sval_t val, node_t* l, node_t* r, int initializing);
intset_t* set_new();
void set_delete(intset_t* set);
int set_size(intset_t* set);
void node_delete(node_t* node);

#endif	/* _H_BST_SEQ_ */
