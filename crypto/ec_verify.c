#include <stdio.h>
#include <stdlib.h>

#include "hblk_crypto.h"

/**
 * ec_verify - verifies the signature of a given set of bytes
 * @key: EC_KEY structure containing the public key to verify the signature
 * @msg: characters to verify the signature of
 * @msglen: number of characters to verify the signature of
 * @sig: the signature to be checked
 *
 * Return: 1 if the signature is valid. 0 otherwise
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
		sig_t const *sig)
{
	if (!key || !msg || !sig)
	{
		return (0);
	}

	if (ECDSA_verify(0, msg, msglen, sig->sig, (int)sig->len, (EC_KEY *)key) == 1)
	{
		return (1);
	}

	return (0);
}
