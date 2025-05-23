/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:37:47 by kmonjard          #+#    #+#             */
/*   Updated: 2025/05/23 10:37:48 by kmonjard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Helper function that counters the number of digits in n
static size_t	digit_counter(long long nmbr)
{
	size_t	out;

	out = 0;
	if (nmbr < 0)
	{
		out++;
		nmbr = -nmbr;
	}
	if (nmbr == 0)
		out++;
	while (nmbr != 0)
	{
		nmbr /= 10;
		out++;
	}
	return (out);
}

//Converts an integer into a mallocated string
char	*ft_itoa(int n)
{
	char		*out;
	size_t		i_out;
	long long	nmbr;

	nmbr = (long long)n;
	out = malloc(sizeof(char) * (digit_counter(n)));
	if (!out)
		return (NULL);
	out[digit_counter(n)] = '\0';
	if (nmbr == 0)
		out[0] = '0';
	if (nmbr < 0)
	{
		out[0] = '-';
		nmbr = -nmbr;
	}
	i_out = digit_counter(n) - 1;
	while (nmbr != 0)
	{
		out[i_out] = (nmbr % 10) + '0';
		nmbr /= 10;
		i_out--;
	}
	return (out);
}

/*
int main(void)
{
	#include <limits.h>
	char *test = ft_itoa(111);
	printf("%s\n", test);
	free(test); return (0);
}
*/
