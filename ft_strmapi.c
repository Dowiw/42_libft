/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:29:48 by kmonjard          #+#    #+#             */
/*   Updated: 2025/05/23 13:29:49 by kmonjard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Applies function (*f) to characters of (*s) and stores results to new (char *)
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	out = malloc(sizeof(char) * (s_len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
