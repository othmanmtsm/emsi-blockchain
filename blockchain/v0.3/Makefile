C = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -I. -Itransaction -Iprovided -I../../crypto
AR = ar -rcs
RM = rm -f
CTAGS = ctags
TAGS = .tags

TASK0 = blockchain_create
TASK1 = block_create
TASK2 = block_destroy
TASK3 = blockchain_destroy
TASK4 = block_hash
TASK5 = blockchain_serialize
TASK6 = blockchain_deserialize
TASK7 = block_is_valid
TASK10 = hash_matches_difficulty
TASK11 = block_mine
TASK12 = blockchain_difficulty
TASK13 = tx_out_create
TASK14 = unspent_tx_out_create
TASK15 = tx_in_create
TASK16 = transaction_hash
TASK17 = tx_in_sign
TASK17 = tx_in_sign
TASK18 = transaction_create
TASK19 = transaction_is_valid
TASK20 = coinbase_create
TASK21 = coinbase_is_valid
TASK22 = transaction_destroy

SRC = $(wildcard *.c) $(wildcard transaction/*.c) $(wildcard provided/*.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

.PHONY: all clean distclean oclean tags libhblk_blockchain.a

all: libhblk_blockchain.a

clean: oclean
	$(RM) libhblk_crypto.a

distclean: clean
	$(RM) $(TAGS)

oclean:
	$(RM) $(OBJ)

tags:
	$(CTAGS) -f $(TAGS) -R

libhblk_blockchain.a: $(OBJ)
	$(AR) $@ $^
