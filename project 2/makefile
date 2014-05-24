primes: primes.o circbuffer.o
	gcc circbuffer.o primes.o -o ./bin/primes -D_REENTRANT -lpthread -lrt -lm -Wall
primes.o: primes.c
	cc -c primes.c
circbuffer.o: circbuffer.h circbuffer.c
	cc -c circbuffer.c
