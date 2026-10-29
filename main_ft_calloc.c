#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


extern void *ft_calloc(size_t nmemb, size_t size);

int main(void)
{
	errno = 0;
	int *tab;

	size_t i;
	// i = 0;

	size_t nmemb;
	nmemb = 0;
	nmemb = ~nmemb;

	tab = ft_calloc(nmemb, sizeof(int));

	if (tab == NULL)
	{
		printf("Erreur Calloc_1\n");
		// printf("Errno = %d\n", errno);
		return (1);
	}

	for(i = 0; i < nmemb; i++)
	{
		printf("tab[%zu] = %d\n", i, tab[i]);

		if(tab[i] != 0)
		{
			printf("Erreur Calloc_2: tab[%zu] = %d\n", i, tab[i]);
			free(tab);
			return (1);
		}
	}

	// printf("Errno = %d\n", errno);
	free(tab);
	return(0);
}

