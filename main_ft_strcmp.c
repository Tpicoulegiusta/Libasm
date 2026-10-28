#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	int result;
	int result_2;
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

	const char *s1 = "abc";
	const char *s2 = "abc";

	printf("chaine 1 = %s\n", s1);
	printf("chaine 2 = %s\n", s2);


	result = ft_strcmp(s1, s2);


	printf("Result du ft_cmp = %d\n", result);

	result_2 = strcmp(s1, s2);

	printf("Result du vrai cmp = %d\n", result_2);


	return (0);
}