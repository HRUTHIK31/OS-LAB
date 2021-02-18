#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
 
#define BUFF_SIZE 1024
 
int main(int argc, char* argv[])
{
	int srcFD;
	char *buff[BUFF_SIZE];
	
	/*Check if both src & dest files are received or -help is received to get usage*/
	if(argc != 2 || argv[1] == "-help")
	{
		printf("\nUsage: rmcmd source_file \n\n More or less arguments are passed\n");
		exit(EXIT_FAILURE);
	}
 
	/*Open source file*/
	srcFD = open(argv[1],O_RDONLY);
 
	if(srcFD == -1)
	{
		printf("\nError opening file %s errno = %d\n",argv[1],errno);
		exit(EXIT_FAILURE);	
	}
	
	/*Open destination file with respective flags & modes
	  O_CREAT & O_TRUNC is to truncate existing file or create a new file
	  S_IXXXX are file permissions for the user,groups & others*/
	unlink(argv[1]);
	
	if(close(srcFD) == -1)
		printf("\nError in closing file %s\n",argv[1]);
 
	
	exit(EXIT_SUCCESS);
	
	
}
