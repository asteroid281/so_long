/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:41:42 by yunozdem          #+#    #+#             */
/*   Updated: 2023/12/24 16:35:37 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (c);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (c);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (c);
	}
	else
	{
		return (0);
	}
}
