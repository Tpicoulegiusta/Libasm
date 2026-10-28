#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *string);


int main (void)
{
	// const char *string = "\0";
	// const char *string = "Is\0";
	// const char *string = "Isibio\0";
	const char *string = "Isibio0o0o0o0o0o0o0o0o0o0o0o0o0oo0o\0";
	size_t length = ft_strlen(string); //mine strlen


	size_t real_length = strlen(string); //real strlen


	printf("Taille : %zu\n", length);
	printf("Taille via le vrai strlen : %zu\n", real_length);
	return(0);
}