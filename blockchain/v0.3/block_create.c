#include "blockchain.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * block_create - Creates a block structure and initializes it
 * @prev: pointer to the previous Block in the Blockchain
 * @data: memory area to duplicate in the Block’s data
 * @data_len: number of bytes to duplicate in data
 *
 * Return: a pointer to the allocated Block, NULL upon failure
 */
block_t *block_create(block_t const *prev, int8_t const *data,
			uint32_t data_len)
{
	block_t *block = NULL;

	if (!prev || !data)
	{
		return (NULL);
	}
	block = calloc(1, sizeof(*block));
	if (!block)
	{
		return (NULL);
	}
	block->info.index = prev->info.index + 1;
	block->info.difficulty = 0;
	block->info.timestamp = time(NULL);
	block->info.nonce = 0;
	memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
	block->data.len = MIN(data_len, BLOCK_DATA_MAX_LEN);
	memcpy(block->data.buffer, data, block->data.len);
	return (block);
}

