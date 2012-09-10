#ifndef __DER_H
#define __DER_H

#include <stdbool.h>
#include <stdint.h>

#define __BUILD_GETDERV(type)			\
						\
bool getderv_##type(type data[], int size)

__BUILD_GETDERV(int16_t);
__BUILD_GETDERV(int32_t);

#undef __BUILD_GETDERV

#endif
