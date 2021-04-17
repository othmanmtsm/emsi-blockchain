#include "blockchain.h"

/**
 * blockchain_create - creates a Blockchain structure, and initializes it.
 *
 * Return: A blockchain_t structure, NULL upon failure
 */

blockchain_t *blockchain_create(void)
{
	blockchain_t *blockchain;
	block_t *block;

	blockchain = malloc(sizeof(*blockchain));
	block = malloc(sizeof(*block));
	block->info.index = 0;
	block->info.difficulty = 0;
	block->info.timestamp = 1537578000;
	block->info.nonce = 0;
	memset(block->info.prev_hash, 0, SHA256_DIGEST_LENGTH);
	memcpy(&(block->data.buffer), "Holberton School", 16);
	block->data.len = 16;
	memcpy(&(block->hash), "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf"
				"\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1"
				"\xd3\xd7\xff\x2f\x04\x51\x58\x03",
		SHA256_DIGEST_LENGTH);
	blockchain->chain = llist_create(MT_SUPPORT_FALSE);
	if (!blockchain->chain)
	{
		free(blockchain);
		free(block);
		return (NULL);
	}
	if (llist_add_node(blockchain->chain, block, ADD_NODE_FRONT) == -1)
	{
		free(blockchain);
		free(block);
		return (NULL);
	}
	return (blockchain);
}

