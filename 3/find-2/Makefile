#
# Makefile
# CS50
#

all: generate find

generate: generate.c
#	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c
	gcc -o generate generate.c

find: find.c helpers.c helpers.h
#	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -lcs50 -lm
	gcc -o find find.c	

clean:
#	rm -f *.o a.out core find generate
	rm -f *.exe