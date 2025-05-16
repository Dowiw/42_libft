/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:41:44 by kmonjard          #+#    #+#             */
/*   Updated: 2025/05/16 17:41:45 by kmonjard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Look for string little in string big: return NULL if N/A, else &big
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*little_mark;

	little_mark = NULL;
	if (*little == '\0')
		return ((char *)big);
	while (len > 0)
	{
		if (*little == *big)
		{
			little_mark = (char *)little;
			while (*little_mark == *big)
			{
				little_mark++;
				big++;
			}
			if (*little_mark == '\0')
			{
				return ((char *)big);
			}
		}
		little++;
		big++;
		len--;
	}
	return (little_mark);
}

int main() {
	#include <string.h>
	#include <stdio.h>
	char *a = "helohellohelo";
	char *needle = "ell";
	printf("%s", ft_strnstr(a, needle, 5));
}
