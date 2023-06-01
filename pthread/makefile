CC=gcc
CFLAGS+=-pthread
LDFLAGS+=-pthread
all:a
a:main.o
	$(CC) $^  -o $@  $(LDFLAGS) $(CFLAGS)
clean:
	rm -rf *.o a
