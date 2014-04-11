

int main(int argc, char* argv[])
{
	int nFiles = argc - 3;
	pid_t pid[nFiles];
	int index = 0;

	int pf[2]; //pipe pai-filho
	int i = 0;

	pipe(fd);

	int mkfifo( 'FIFO' , 'chmod');
	for(i; i < nFiles; i++){
		pid[i] = fork();

		if(pid[i] > 0){
			close(pf[0]); //fecha leitura pipe pai-filho
		} else {
			index = i + 3;
			close(pf[1]); //fecha escrita pipe pai-filho
		}
	}

	i = 0;

	if( index > 0) {
		FILE *file = *fopen("%s" argv[index], "r");
	}

	
