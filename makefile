project1: monitor.o
	gcc monitor.o -o ./bin/monitor
monitor.o: monitor.c
	cc -c monitor.c
