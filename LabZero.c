#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <locale.h>

 	

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Rus");
	int p_id;
	int status;

	switch(p_id = fork())
		{
		  case -1: 
		  	perror(1);
		  case 0: 
		  	printf("потомок %d ", p_id);
		  	printf("%s\n", argv[1]);
		  	execvp(argv[1], &argv[1]);
		  	exit(1);
		  default: 
		  	waitpid(pi_d, &status, 0);
		  	printf("Родитель %d Статус %d\n", pi_d, WEXITSTATUS(status));
		  	break;
		}
	return 0;
}