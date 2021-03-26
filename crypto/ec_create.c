#include <stdio.h>
#include <stdlib.h>

#include "hblk_crypto.h"

EC_KEY *ec_create(void)
{
	uint8_t set_group_status;
	uint8_t gen_key_status;
	EC_KEY *key = EC_KEY_new();
	EC_GROUP *grp = EC_GROUP_new_by_curve_name(EC_CURVE);
	if(!key)
	{
		return NULL;
	}
	set_group_status = EC_KEY_set_group(key, grp);
	if(set_group_status != 1)
	{
		fprintf(stderr, "%s", "ec_create.c : error while setting group\n");
		return NULL;
	}
	else
	{
		gen_key_status = EC_KEY_generate_key(key);
		if(gen_key_status != 1)
		{
			fprintf(stderr, "%s", "ec_create.c : error while generating the key\n");
			return NULL;
		}
	}
	EC_GROUP_free(grp);
	return key;
}
