#include <stdlib.h>

#include "blockchain.h"

void block_destroy(block_t *block)
{
	if(!block)
		return;

	free(block);
}
