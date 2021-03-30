#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

#include "hblk_crypto.h"

/**
 * ec_load - loads an EC key pair from the disk
 * @folder: the path to the folder from which to load the keys
 *
 * Return: pointer to the created EC key pair, NULL upon failure
 */
EC_KEY *ec_load(char const *folder)
{
	char *pub;
	char *pri;
	char *sep = "/";
	FILE *fpub;
	FILE *fpri;
	EC_KEY *key = NULL;

	opendir(folder);
	if (errno == ENOENT)
	{
		return (NULL);
	}
	pub = malloc(strlen(folder) + strlen(PUB_FILENAME) + 2);
	pub = strcpy(pub, folder);
	strcat(pub, sep);
	strcat(pub, PUB_FILENAME);
	pri = malloc(strlen(folder) + strlen(PRI_FILENAME) + 2);
	pri = strcpy(pri, folder);
	strcat(pri, sep);
	strcat(pri, PRI_FILENAME);
	fpub = fopen(pub, "r");
	fpri = fopen(pri, "r");
	if (!fpub || !fpri)
	{
		fprintf(stderr, "%s", "No pem files were found\n");
		free(pub);
		free(pri);
		fclose(fpub);
		fclose(fpri);
		return (NULL);
	}
	key = PEM_read_EC_PUBKEY(fpub, NULL, NULL, NULL);
	if (!key)
	{
		fprintf(stderr, "%s", "Failed to read public key\n");
		free(pub);
		free(pri);
		fclose(fpub);
		fclose(fpri);
		return (NULL);
	}
	else
	{
		key = PEM_read_ECPrivateKey(fpri, &key, NULL, NULL);
		if (!key)
		{
			fprintf(stderr, "%s", "Failed to read private key\n");
			free(pub);
			free(pri);
			fclose(fpub);
			fclose(fpri);
			return (NULL);
		}
	}
	free(pub);
	free(pri);
	fclose(fpub);
	fclose(fpri);
	return (key);
}
