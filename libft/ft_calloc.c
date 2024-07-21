/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:00:49 by yunozdem          #+#    #+#             */
/*   Updated: 2023/12/25 20:18:26 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	totsize;
	void	*ptr;

	totsize = count * size;
	ptr = malloc(totsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, totsize);
	return (ptr);
}
