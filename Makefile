CC=gcc
CFLAGS=-O3
LDFLAGS=

all: main

clean:
	rm -f main *.o

endianess.o: endianess.c endianess.h datatypes.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c endianess.c

arp.o: arp.c netif.h endianess.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c arp.c endianess.c

main: main.c endianess.o arp.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o main main.c endianess.o arp.o

test: main
	./main
