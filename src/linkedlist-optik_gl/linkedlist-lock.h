/*
 *   File: linkedlist-lock.h
 *   Author: Vincent Gramoli <vincent.gramoli@sydney.edu.au>,
 *  	     Vasileios Trigonakis <vasileios.trigonakis@epfl.ch>
 *   Description:
 *   linkedlist-lock.h is part of ASCYLIB
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

#ifndef _H_LINKEDLIST_LOCK_
#define _H_LINKEDLIST_LOCK_

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
#include "optik.h"

#include "common.h"
#include "utils.h"
#include "measurements.h"
#include "ssalloc.h"
#include "ssmem.h"

#define DEFAULT_LOCKTYPE	  	2
#define DEFAULT_ALTERNATE		0
#define DEFAULT_EFFECTIVE		1

static volatile int stop;
extern __thread ssmem_allocator_t* alloc;

typedef volatile struct node_l
{
  skey_t key;			/* 8 */
  sval_t val;			/* 16 */
  volatile struct node_l *next;	/* 24 */
  uint8_t padding32[8];		/* 32 */
#if defined(DO_PAD)
  uint8_t padding[CACHE_LINE_SIZE - sizeof(skey_t) -
		  sizeof(sval_t) - sizeof(struct node*) - 8];
#endif
} node_l_t;

STATIC_ASSERT(sizeof(node_l_t) == 32, "sizeof(node_l_t) == 32");

typedef ALIGNED(CACHE_LINE_SIZE) struct intset_l
{
  node_l_t* head;
  uint8_t padding[CACHE_LINE_SIZE - sizeof(node_l_t*)];
  optik_t lock;
  uint8_t padding2[CACHE_LINE_SIZE - sizeof(optik_t)];
} intset_l_t;

node_l_t* new_node_l(skey_t key, sval_t val, node_l_t* next, int initializing);
intset_l_t* set_new_l();
void set_delete_l(intset_l_t* set);
int set_size_l(intset_l_t* set);
void node_delete_l(node_l_t* node);

#endif	/* _H_LINKEDLIST_LOCK_ */
