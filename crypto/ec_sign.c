#include <stdio.h>
#include <stdlib.h>

#include "hblk_crypto.h"

uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t *sig)
{
	if(!key || !msg)
	{
		return NULL;
	}

	if(ECDSA_sign(0, msg, msglen, sig->sig, (unsigned int*)&sig->len, (EC_KEY*)key) == 0)
	{
		return NULL;
	}

	return sig->sig;
}
