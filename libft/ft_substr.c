/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:52:22 by yunozdem          #+#    #+#             */
/*   Updated: 2023/12/25 19:54:24 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	end;

	end = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (start < slen)
		end = slen - start;
	if (end > len)
		end = len;
	str = (char *)malloc(sizeof(char) * (end + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, end + 1);
	return (str);
}
