#include "derv.h"

#define __BUILD_GETDERV_O2(type)		\
						\
bool getderv_##type(type data[], int size)	\
{						\
	type first, last, prev;			\
	int i;					\
						\
	first = data[1] - data[0];		\
	last = data[size-1] - data[size-2];	\
						\
	prev = data[0];				\
	for (i = 1; i < size - 2; i++) {	\
		type d;				\
		d = (data[i+1] - prev) / 2;	\
		prev = data[i];			\
		data[i] = d;			\
	}					\
						\
	data[0] = first;			\
	data[size - 1] = last;			\
						\
	return true;				\
}

__BUILD_GETDERV_O2(int16_t);
__BUILD_GETDERV_O2(int32_t);
