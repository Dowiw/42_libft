#include "libft.h"
#include <stdio.h>
#include <strings.h>

int main(void)
{
	//Size for every array is going to be 5
	int size = 5;

	printf("\nchar array bzero testing: \n");
	char real_bzero_char_test[5] = {'a','a','a','a','a'};
	printf("Before real bzero: %s\n", real_bzero_char_test);
	bzero(real_bzero_char_test, size);
	printf("After real bzero (should be empty): %s\n", real_bzero_char_test);

	printf("\n");

	char ft_bzero_char_test[5] = {'a','a','a','a','a'};
	printf("Before ft_bzero: %s\n", ft_bzero_char_test);
	ft_bzero(ft_bzero_char_test, size);
	printf("After ft_bzero (should be empty): %s\n", ft_bzero_char_test);

	printf("\nint array bzero testing: \n");
	int real_bzero_int_test[5] = {1, 2, 3, 4, 5};
	printf("Before bzero: ");
	for (int i = 0; i < 5; i++) { printf("%d ", real_bzero_int_test[i]); }
	printf("\n");
	bzero(real_bzero_int_test, size);
	printf("After real bzero (should be empty): %s\n", real_bzero_char_test);

	printf("\n");

	char ft_bzero_char_test[5] = {'a','a','a','a','a'};
	printf("Before ft_bzero: %s\n", ft_bzero_char_test);
	ft_bzero(ft_bzero_char_test, size);
	printf("After ft_bzero (should be empty): %s\n", ft_bzero_char_test);
}


