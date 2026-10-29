#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>


extern ssize_t ft_read (int fd, void *buf, size_t count);


int main (void)
{
	ssize_t my_read;
	ssize_t real_read;
	char buffer[100];
	int fd;

	errno = 0;
	printf("Errno avant mon ft_read = %d\n", errno);

	my_read = ft_read(12, buffer, sizeof(buffer) - 1);
	printf("Errno apres mon ft_read = %d\n", errno);

	errno = 0;
	printf("Errno avant le vrai read = %d\n", errno);

	real_read = read(12, buffer, sizeof(buffer) - 1);
	printf("Errno apres le vrai read = %d\n", errno);

	printf("Octets lu par ft_read : %zd\n", my_read);
	printf("Octets lu par read levrai : %zd\n", real_read);

	fd = open("main_ft_read.c", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur open\n");
		return (1);
	}
	printf("fd ouvert = %d\n", fd);

	errno = 0;
	my_read = ft_read(fd, buffer, 19);
	printf("Errno apres mon ft_read = %d\n", errno);
	if (my_read >= 0)
		buffer[my_read] = '\0';
	printf("Lu par ft_read = \"%s\"\n", buffer);

	lseek(fd, 0, SEEK_SET);

	errno = 0;
	real_read = read(fd, buffer, 19);
	printf("Errno apres le vrai read = %d\n", errno);
	if (real_read >= 0)
		buffer[real_read] = '\0';
	printf("Lu par read levrai = \"%s\"\n", buffer);

	close(fd);

	printf("Octets lu par ft_read = %zd\n", my_read);
	printf("Octets lu par read = %zd\n", real_read);


	return (0);
}



