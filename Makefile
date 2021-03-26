#This is a comment

#variables
.PHONY = all

CC =gcc
CFLAGS=

deps=$(wildcard *.c)
BINS=$(deps:%.c=%.o)


all: HELLOW

#TARGET : [DEPENDENCIES...]
#<tab> RULE

BINS:$(deps)
	@echo "Generating binary objects"
	@${CC} -c $^ ${CFLAGS}

HELLOW: ${BINS}
	@echo "Generating executble"
	@${CC} -o $@ $^

CLEAN :
	@echo "Removing all binary exec files"
	@rm -rvf *.o ${BINS} HELLOW
