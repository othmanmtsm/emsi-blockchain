#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hblk_crypto.h"

/**
 * sha256 - compute the hash of a sequence of bytes
 * @s: the sequence of bytes to be hashed
 * @len: the number of bytes to hash
 * @digest: The resulting hash
 *
 * Return: pointer to digest, NULL on error
 */

uint8_t *sha256(int8_t const *s, size_t len,
		uint8_t digest[SHA256_DIGEST_LENGTH])
{
	if (!digest)
	{
		return (NULL);
	}
	return ((uint8_t *)SHA256((unsigned char *)s, len, digest));
}

