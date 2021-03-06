#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

#include "hblk_crypto.h"

/**
 * ec_save - saves an existing EC key pair on the disk
 * @key: points to the EC key pair to be saved on disk
 * @folder: path to the folder in which to save the keys
 *
 * Return: 1 or 0 upon success or failure
 */
int ec_save(EC_KEY *key, char const *folder)
{
	char *pub;
	char *pri;
	char *sep = "/";
	FILE *fpub;
	FILE *fpri;

	if (!key)
		return (0);

	if (opendir(folder))
	{
		fprintf(stderr, "%s", "Directory exists\n");
	}
	else if (errno == ENOENT)
	{
		if (mkdir(folder, 0777) == -1)
			return (0);
	}
	pub = malloc(strlen(folder) + strlen(PUB_FILENAME) + 2);
	pub = strcpy(pub, folder);
	strcat(pub, sep);
	strcat(pub, PUB_FILENAME);
	pri = malloc(strlen(folder) + strlen(PRI_FILENAME) + 2);
	pri = strcpy(pri, folder);
	strcat(pri, sep);
	strcat(pri, PRI_FILENAME);
	fpub = fopen(pub, "w+");
	fpri = fopen(pri, "w+");
	if (PEM_write_EC_PUBKEY(fpub, key) == 0)
	{
		free(pub);
		free(pri);
		fclose(fpub);
		fclose(fpri);
		return (0);
	}
	if (PEM_write_ECPrivateKey(fpri, key, NULL, NULL, 0, NULL, NULL) == 0)
	{
		free(pub);
		free(pri);
		fclose(fpub);
		fclose(fpri);
		return (0);
	}
	free(pub);
	free(pri);
	fclose(fpub);
	fclose(fpri);
	return (1);
}

