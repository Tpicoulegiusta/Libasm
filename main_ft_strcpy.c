#include <string.h>
#include <stdio.h>


extern char *ft_strcpy(char *dest, const char *src); //rdi, rsi, return = rax//


int main(void)
{
	{
		const char *src = "veryloooooooooooooongstring\0";
		char dest[28];

		printf("ft   dest : \"%s\"\n", ft_strcpy(dest, src));
		printf("real dest : \"%s\"\n", strcpy(dest, src));
	}
	printf("\n");

	{
		const char *src = "\0";
		char dest[28];

		printf("ft   dest : \"%s\"\n", ft_strcpy(dest, src));
		printf("real dest : \"%s\"\n", strcpy(dest, src));
	}


	return(0);
}