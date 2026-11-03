#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	// const char *s1 = "";
	// const char *s2 = "";

	// const char *s1 = "";
	// const char *s2 = "abc";

	// const char *s1 = "abc";
	// const char *s2 = "";

	// const char *s1 = "abcdefg";
	// const char *s2 = "gfedcba";

	// const char *s1 = "abcdefghijkl";
	// const char *s2 = "gfedcba";

	{
		const char *s1 = "abc\0";
		const char *s2 = "abc\0";

		printf("chaine 1 = \"%s\"\n", s1);
		printf("chaine 2 = \"%s\"\n", s2);


		printf("Result du ft_cmp   = %d\n", ft_strcmp(s1, s2));
		printf("Result du vrai cmp = %d\n", strcmp(s1, s2));
	}
	printf("\n");

	{
		const char *s1 = "abc\0";
		const char *s2 = "abcd\0";

		printf("chaine 1 = \"%s\"\n", s1);
		printf("chaine 2 = \"%s\"\n", s2);


		printf("Result du ft_cmp   = %d\n", ft_strcmp(s1, s2));
		printf("Result du vrai cmp = %d\n", strcmp(s1, s2));
	}
	printf("\n");

	{
		const char *s1 = "\0";
		const char *s2 = "\0";

		printf("chaine 1 = \"%s\"\n", s1);
		printf("chaine 2 = \"%s\"\n", s2);


		printf("Result du ft_cmp   = %d\n", ft_strcmp(s1, s2));
		printf("Result du vrai cmp = %d\n", strcmp(s1, s2));
	}
	printf("\n");

	{
		const char *s1 = "\0";
		const char *s2 = "abc\0";

		printf("chaine 1 = \"%s\"\n", s1);
		printf("chaine 2 = \"%s\"\n", s2);


		printf("Result du ft_cmp   = %d\n", ft_strcmp(s1, s2));
		printf("Result du vrai cmp = %d\n", strcmp(s1, s2));
	}
	printf("\n");

	{
		const char *s1 = "abc\0";
		const char *s2 = "\0";

		printf("chaine 1 = \"%s\"\n", s1);
		printf("chaine 2 = \"%s\"\n", s2);


		printf("Result du ft_cmp   = %d\n", ft_strcmp(s1, s2));
		printf("Result du vrai cmp = %d\n", strcmp(s1, s2));
	}
	printf("\n");
	return (0);
}