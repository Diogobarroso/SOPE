#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	execl("/bin/tailf", "-F", "text.txt", (char *)NULL);

	/*
	char fifo[] = "fifo";
	int nFiles = argc - 3;
	pid_t pid[nFiles];
	int index = 0;
	int myPid;

	int pf[2]; //pipe pai-filho
	int i = 0;

	pipe(pf);

	mkfifo( fifo , S_IRWXU);
	for(i; i < nFiles; i++){
		pid[i] = fork();

		if(pid[i] > 0){
			close(pf[0]); //fecha leitura pipe pai-filho
		} else {
			index = i + 3;
			myPid = getpid();
			close(pf[1]); //fecha escrita pipe pai-filho
		}
	}

	i = 0;

	if( index > 0) {
		FILE *file = fopen( argv[index], "r");
		printf("I'm process number %d", myPid);
	}
	*/

	return 0;
}
	
