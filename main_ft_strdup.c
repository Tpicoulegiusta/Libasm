#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern char *ft_strdup(const char *s);

int main (void)
{
	{
		const char str[] = "LOngggggggggggggggggggggstring\0";
		const char str_2[] = "LOngggggggggggggggggggggstring\0";

		char *result = ft_strdup(str);
		printf("Result wiz mine ft_strdup = \"%s\"\n", result);
		free(result);

		char *result_2 = strdup(str_2);
		printf("Result wize real one strdup = \"%s\"\n", result_2);
		free(result_2);
	}
	printf("\n");


	{
		const char str[] = "\0";
		const char str_2[] = "\0";

		char *result = ft_strdup(str);
		printf("Result wiz mine ft_strdup = \"%s\"\n", result);
		free(result);

		char *result_2 = strdup(str_2);
		printf("Result wize real one strdup = \"%s\"\n", result_2);
		free(result_2);
	}

	return(0);
}


