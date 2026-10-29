#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>


extern ssize_t ft_write(int fd, const void *buf, size_t count);

int main (void)
{
	ssize_t written;
	ssize_t written_2;
	int fd;

	errno = 0;
	printf("Errno avant mon ft_write= %d\n", errno);

	written = ft_write(12, "Hello\n", 6);
	printf("Errno apres le ft_write = %d\n", errno);
	

	errno = 0;
	printf("Errno avant le vrai write = %d\n", errno);
	
	written_2 = write(12, "Hello\n", 6);
	printf("Errno apres le vrai write = %d\n", errno);

	printf("Octets ecrits par ft_write : %zd\n", written);
	printf("Octets ecrits par write levrai : %zd\n", written_2);


	fd = open("test_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd == -1)
	{
		printf("Erreur open\n");
		return (1);
	}
	printf("fd ouvert = %d\n", fd);

	errno = 0;
	written = ft_write(fd, "Hello de ft_write\n", 18);
	printf("Errno apres le ft_write = %d\n", errno);

	errno = 0;
	written_2 = write(fd, "Hello de write\n", 15);
	printf("Errno apres le write = %d\n", errno);

	close (fd);

	printf("Octets ecrits par ft_write : %zd\n", written);
	printf("Octets ecrits par write levrai : %zd\n", written_2);
	//cat test_write.txt

	return (0);
}

