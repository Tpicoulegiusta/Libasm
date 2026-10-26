#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


extern ssize_t ft_read (int fd, void *buf, size_t count);


int main (void)
{
	ssize_t my_read;
	ssize_t real_read;
	char buffer[100];

	errno = 0;
	printf("Errno avant mon ft_read = %d\n", errno);

	my_read = ft_read(0, buffer, sizeof(buffer) - 1);
	printf("Errno apres mon ft_read = %d\n", errno);

	errno = 0;
	printf("Errno avant le vrai read = %d\n", errno);

	real_read = read(0, buffer, sizeof(buffer) - 1);
	printf("Errno apres le vrai read = %d\n", errno);

	printf("Octets lu par ft_read : %zd\n", my_read);
	printf("Octets lu par read levrai : %zd\n", real_read);


	return (0);
}



