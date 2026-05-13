CC = g++
CFLAGS = -Wall -std=c++14

final: final.o player.o squid.o squidqueue.o
	$(CC) $(CFLAGS) -o final final.o player.o squid.o squidqueue.o

final.o: final.cpp player.hpp squid.hpp squidqueue.hpp
	$(CC) $(CFLAGS) -c final.cpp

player.o: player.cpp player.hpp
	$(CC) $(CFLAGS) -c player.cpp

squid.o: squid.cpp squid.hpp
	$(CC) $(CFLAGS) -c squid.cpp

squidqueue.o: squidqueue.cpp squidqueue.hpp
	$(CC) $(CFLAGS) -c squidqueue.cpp