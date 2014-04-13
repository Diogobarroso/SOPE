#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int pipefd[2];
	pipe(pipefd);
	
	if(fork() == 0){
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		dup2(pipefd[1], 2);
		close(pipefd[1]);
		execlp("tail", "tail", "-F", argv[3], "-n", "0", (char *)NULL);
	} else {
		char buffer[1024];
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		execlp("grep", "grep", "--line-buffered", argv[2]);
		/*while(read(pipefd[0], buffer, sizeof(buffer)) != 0){
			int i = 0;
			for(i; i < sizeof(buffer); i++)
				printf("%c", buffer[i]);
		}*/
	}

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
	
