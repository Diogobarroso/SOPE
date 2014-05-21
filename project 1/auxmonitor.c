#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno ;

int main ()
{
	int i = 3;
	close(piperr[0]);
	i = 3;
	for(i; i < argc; i++)
  	if (fopen (argv[i], "rb") == NULL)
      		write(piperr, i);
   	else
      		fclose (argv[i]);

	return 0;
}

//---------------------------------------------------------
//a inserir no monitor principal
piperr[2];
pipe(piperr);

exec("auxmonitor", "auxmonitor");

close(piperr[1]);

if(piperr[0])
{
	kill(pid[piperr[0]]);
}
