primes: primes.o circbuffer.o
	gcc circbuffer.o primes.o -o primes -D_REENTRANT -lpthread -Wall
primes.o: primes.c
	cc -c primes.c
circbuffer.o: circbuffer.h circbuffer.c
	cc -c circbuffer.c
