#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>


extern void *ft_calloc(size_t nmemb, size_t size);

int main(void)
{
	// errno = 0;
	// int *tab;

	// size_t i;
	// // i = 0;

	// size_t nmemb;
	// nmemb = 0;
	// nmemb = ~nmemb;

	// tab = ft_calloc(nmemb, sizeof(int));

	// if (tab == NULL)
	// {
	// 	printf("Erreur Calloc_1\n");
	// 	// printf("Errno = %d\n", errno);
	// 	return (1);
	// }

	// for(i = 0; i < nmemb; i++)
	// {
	// 	printf("tab[%zu] = %d\n", i, tab[i]);

	// 	if(tab[i] != 0)
	// 	{
	// 		printf("Erreur Calloc_2: tab[%zu] = %d\n", i, tab[i]);
	// 		free(tab);
	// 		return (1);
	// 	}
	// }

	// // printf("Errno = %d\n", errno);
	// free(tab);
	// return(0);
	int *tab;
	size_t i;
	size_t nmemb;

	nmemb = 5;
	tab = ft_calloc(nmemb, sizeof(int));

	if (tab == NULL)
	{
		printf("Test 1 KO : ft_calloc renvoie NULL\n");
		return (1);
	}
	for (i = 0; i < nmemb; i++)
	{
		printf("tab[%zu] = %d\n", i, tab[i]);
		if (tab[i] != 0)
		{
			printf("Test 1 KO : tab[%zu] = %d\n", i, tab[i]);
			free(tab);
			return(1);
		}
	}
	printf("Test 1 OK : %zu cases a zero\n", nmemb);
	free(tab);


	tab = ft_calloc(0, sizeof(int));
	free(tab);
	tab = ft_calloc(5, 0);
	free(tab);
	printf("Test 2 OK : nmemb = 0, size = 0, pas de crash\n");


	errno = 0;
	tab = ft_calloc(SIZE_MAX, sizeof(int));
	if(tab == NULL)
	{
		printf("Test 3 OK : depassement max rejete\n");
	}
	else
	{
		printf("Test 3 KO : depassement non rejete\n");
		free(tab);
		return (1);
	}
	return (0);
}

