#include <stdio.h>
#include <stdlib.h>

#include "hblk_crypto.h"

/**
 * ec_sign - signs a given set of bytes, using a given EC_KEY private key
 * @key: EC_KEY containing the private key to be used to perform the signature
 * @msg: characters to be signed
 * @msglen: number of characters to be signed
 * @sig: holds the address at which to store the signature
 *
 * Return: pointer to the signature buffer, NULL upon failure
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
		sig_t *sig)
{
	if (!key || !msg)
	{
		return (NULL);
	}

	if (ECDSA_sign(0, msg, msglen, sig->sig, (unsigned int *)&sig->len,
			(EC_KEY *)key) == 0)
	{
		return (NULL);
	}

	return (sig->sig);
}
