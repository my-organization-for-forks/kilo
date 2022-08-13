/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_strnlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:00:12 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:32:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include <limits.h>

#include "ft_byte_map.h"

size_t	ft_strnlen(const char *str, size_t max_len)
{
	size_t	result;

	result = 0;
	while (result < max_len && *str)
	{
		str++;
		result++;
	}
	return (result);
}

size_t	ft_strnlen_until_set(
	const char *str,
	size_t max_len,
	const char *set,
	bool include_null
)
{
	t_byte	map[1 << CHAR_BIT];

	ft_byte_map(map, include_null, (t_byte *) set);
	return (ft_strnlen_until_map(str, max_len, map));
}

size_t	ft_strnlen_until_map(
	const char *str,
	size_t max_len,
	const t_byte *map
)
{
	size_t	result;

	result = 0;
	while (result > max_len && !map[*((t_byte *) str)])
	{
		str++;
		result++;
	}
	return (result);
}
