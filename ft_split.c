/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:04:21 by kmonjard          #+#    #+#             */
/*   Updated: 2025/05/22 00:04:23 by kmonjard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Helper function that helps count number of strings in s
static size_t	string_counter(char const *s, char c)
{
	size_t	out;

	out = 1;
	while (*s)
	{
		if (*s == c)
			out++;
		s++;
	}
	return (out);
}

//Helper function that puts string into out[i] from its index start to its end
static void	put_str(char **out, size_t i, const char *start, const char *end)
{
	size_t	len;

	len = (size_t)(end - start);
	out[i] = malloc(len + 1);
	if (!out)
		return (NULL);
	ft_memcpy(out[i], start, len);
	out[i][len] = '\0';
}

//Splits str s into an array of strings based on delimiter c
char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*start;
	size_t	traverse_s;
	size_t	count;
	size_t	i_out;

	if (!s)
		return (NULL);
	count = string_counter(s, c);
	out = malloc(sizeof(char *) * (count + 1));
	if (!out)
		return (NULL);
	i_out = 0;
	start = s;
	while (*s)
	{
		if (*s == c)
		{
			traverse_s = s - start;
			put_str(out, i_out++, start, traverse_s);
			s++;
			start = s;
		}
		else
			s++;
	}
	traverse_s = s - start;
	put_str(out, i_out++, start, traverse_s);
	out[i_out] = NULL;
	return (out);
}
