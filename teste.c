#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;
	//char buf[400];
	char *line;
	int r;

	fd = open("files/43_no_nl", O_RDWR|O_CREAT);
	line = get_next_line(fd);
	printf("print: %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("print: %s\n", line);
	line = get_next_line(fd);
	printf("print: %s\n", line);
	line = get_next_line(fd);
	printf("print: %s\n", line);
	//r = read(fd, buf, 400) ;
	//printf("print: %s\n", buf);
	//read(fd, buf, 2) ;
	//printf("print: %s\n", buf);
	// read(fd, buf, 2) ;
	// printf("print: %s\n", buf);
	// read(fd, buf, 2) ;
	// printf("print: %s\n", buf);
	// read(fd, buf, 2) ;
	// printf("print: %s\n", buf);
	// read(fd, buf, 2) ;
	// printf("print: %s\n", buf);
	close(fd);
	return(0);
}