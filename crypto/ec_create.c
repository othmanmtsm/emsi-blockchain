#include <stdio.h>
#include <stdlib.h>

#include "hblk_crypto.h"

/**
 * ec_create - Creates a new EC key pair
 *
 * Return: Pointer to an EC_KEY structure, NULL upon failure
 */
EC_KEY *ec_create(void)
{
	uint8_t gen_key_status;
	EC_KEY *key;

	key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!key)
	{
		return (NULL);
	}
	else
	{
		gen_key_status = EC_KEY_generate_key(key);
		if (gen_key_status != 1)
		{
			fprintf(stderr, "%s", "ec_create.c : error while generating the key\n");
			EC_KEY_free(key);
			return (NULL);
		}
	}
	return (key);
}
