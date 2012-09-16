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

netif.o: netif.c netif.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c netif.c

main: main.c endianess.o arp.o netif.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o main main.c endianess.o arp.o netif.o

test: main
	./main
