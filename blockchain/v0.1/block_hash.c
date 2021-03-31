#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "blockchain.h"

uint8_t *block_hash(block_t const *block,
			uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	char s[SHA256_DIGEST_LENGTH];
}
