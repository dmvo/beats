#include "derv.h"

#define __BUILD_GETDERV_O2(type)		\
						\
void getderv_##type(type data[], int size)	\
{						\
	type first, last, prev;			\
	int i;					\
						\
	first = data[1] - data[0];		\
	last = data[size-1] - data[size-2];	\
						\
	prev = data[0];				\
	for (i = 1; i < size - 1; i++) {	\
		type d;				\
		d = (data[i+1] - prev) / 2;	\
		prev = data[i];			\
		data[i] = d;			\
	}					\
						\
	data[0] = first;			\
	data[size - 1] = last;			\
}

#define __BUILD_GETDERV_O4(type)			\
							\
void getderv_##type(type data[], int size)		\
{							\
	type first, second;				\
	type last, lastlast;				\
	type prev, prevprev;				\
	int i;						\
							\
	first = data[1] - data[0];			\
	second = (data[2] - data[0]) / 2;		\
	last = data[size-1] - data[size-2];		\
	lastlast = (data[size-1] - data[size-3]) / 2;	\
							\
	prevprev = data[0]; prev = data[1];		\
	for (i = 2; i < size - 2; i++) {		\
		type d;					\
		d = ((data[i+1] - prev) / 3) * 2;	\
		d = d + (prevprev - data[i+2]) / 12;	\
		prevprev = prev;			\
		prev = data[i];				\
		data[i] = d;				\
	}						\
							\
	data[0] = first;				\
	data[1] = second;				\
	data[size-2] = lastlast;			\
	data[size-1] = last;				\
}

#ifdef __DERV_ERROR_O4
__BUILD_GETDERV_O4(int16_t);
__BUILD_GETDERV_O4(int32_t);
#else
__BUILD_GETDERV_O2(int16_t);
__BUILD_GETDERV_O2(int32_t);
#endif

#undef __BUILD_GETDERV_O2
#undef __BUILD_GETDERV_O4
