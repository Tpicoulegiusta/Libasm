#include <string.h>
#include <stdio.h>


extern char *ft_strcpy(char *dest, const char *src); //rdi, rsi, return = rax//


int main(void)
{
	// const char *src = "\0";
	const char *src = "veryloooooooooooooongstring\0";
	// char dest[10];
	char dest[27];


	// printf("dest avant: %s\n", dest);
	// ft_strcpy(dest, src);
	// printf("dest apres: %s\n", dest);

	printf("dest avant: %s\n", dest);
	strcpy(dest, src);
	printf("dest apres: %s\n", dest);


	return(0);
}