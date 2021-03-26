#include <stdio.h>
#include <stdlib.h>

#include "hblk_crypto.h"

uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_POINT *point;
	const EC_GROUP *group;
	if(!key || !pub)
	{
		return NULL;
	}
	group = EC_KEY_get0_group(key);
	point = EC_KEY_get0_public_key(key);
	if(!group || !point)
	{
		return NULL;
	}
	if(!EC_POINT_point2oct(group, point, POINT_CONVERSION_UNCOMPRESSED, pub, EC_PUB_LEN, NULL))
	{
		return NULL;
	}
	return pub;
}
