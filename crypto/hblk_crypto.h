#include <openssl/sha.h>
#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <openssl/pem.h>
#include <stdint.h>

#define EC_CURVE NID_secp256k1

#define EC_PUB_LEN 65
#define SIG_MAX_LEN 72

#define PRI_FILENAME "key.pem"
#define PUB_FILENAME "key_pub.pem"

typedef struct sig_s
{
	uint8_t sig[SIG_MAX_LEN];
	uint8_t len;
} sig_t;

uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]);
EC_KEY *ec_create(void);
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN]);
int ec_save(EC_KEY *key, char const *folder);
EC_KEY *ec_load(char const *folder);
