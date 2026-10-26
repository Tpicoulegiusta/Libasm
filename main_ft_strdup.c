#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern char *ft_strdup(const char *s);

int main (void)
{

	const char str[] = "Caca";
	const char str_2[] = "Caca";

	char *result = ft_strdup(str);

	printf("Result wiz mine ft_strdup = %s\n", result);

	char *result_2 = strdup(str_2);

	printf("Result wize real one strdup = %s\n", result_2);


	return(0);
}




