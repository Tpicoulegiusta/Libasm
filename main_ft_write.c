#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern ssize_t ft_write(int fd, const void *buf, size_t count);

int main (void)
{
	ssize_t written;
	ssize_t written_2;

	errno = 0;
	printf("Errno avant mon ft_write= %d\n", errno);

	written = ft_write(12, "Hello\n", 6);
	printf("Errno apres le ft_write = %d\n", errno);
	
	errno = 0;
	printf("Errno avant le vrai write = %d\n", errno);
	
	written_2 = write(12, "Hello\n", 6);
	printf("Errno apres le vrai write = %d\n", errno);

	printf("O ctets ecrits par ft_write : %zd\n", written);
	printf("O ctets ecrits par write levrai : %zd\n", written_2);

	return (0);
}