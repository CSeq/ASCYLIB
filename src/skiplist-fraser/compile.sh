cc -O0 -D_GNU_SOURCE -DLOCKFREE -DDEFAULT -DCORE_NUM=8 -DFREQ_GHZ=3.900 -m64 -Wall -fno-strict-aliasing -std=gnu11 -DGC=0 -DINITIALIZE_FROM_ONE=0 -DNO_SET_CPU -m64 -L../../external/lib -lssmem_x86_64 -pthread -lrt -lm tada.c
cpp -P -D_GNU_SOURCE -DLOCKFREE -DDEFAULT -DCORE_NUM=8 -DFREQ_GHZ=3.900 -m64 -Wall -fno-strict-aliasing -std=gnu11 -DGC=0 -DINITIALIZE_FROM_ONE=0 -DNO_SET_CPU -m64 -L../../external/lib -lssmem_x86_64 -pthread -lrt -lm tada.c -nostdinc