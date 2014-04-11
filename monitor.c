

int main(int argc, char* argv[])
{
	
	int pf[2]; //pipe pai-filho
	int i = 0;

	pipe(fd);

	int mkfifo( 'FIFO' , 
	for(i; i < argc; i++)
	{
		pid = fork();

		if(pid > 0)
		{
			close(pf[0]); //fecha leitura pipe pai-filho
		}
		else
		{
			close(pf[1]); //fecha escrita pipe pai-filho
		}
	}
