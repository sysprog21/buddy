CFLAGS= -O2 -Wall -fPIC -pg -g

all: test-malloc

alloc.o: alloc.c
	$(CC) $(CFLAGS) -c alloc.c -o $@

test-malloc: alloc.o test-malloc.c
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJS) test-malloc
