#include "blockchain.h"

/**
 * block_mine - mine a block in order to insert it into a blockchain
 *
 * @block: pointer to the block to be mined
 */
void block_mine(block_t *block)
{
	if (!block)
		return;
	block->info.nonce = 0;
	while (hash_matches_difficulty(block_hash(block, block->hash),
				       block->info.difficulty) != 1)
		block->info.nonce++;
}

