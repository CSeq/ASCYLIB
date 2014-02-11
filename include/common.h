#ifndef _COMMON_H_
#define _COMMON_H_

#define XSTR(s)                         STR(s)
#define STR(s)                          #s

typedef intptr_t skey_t;
typedef intptr_t sval_t;

#define DEFAULT_DURATION                1000
#define DEFAULT_INITIAL                 1024
#define DEFAULT_NB_THREADS              1
#define DEFAULT_RANGE                   (2 * DEFAULT_INITIAL)
#define DEFAULT_UPDATE                  20

#endif	/*  _COMMON_H_ */