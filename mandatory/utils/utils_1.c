/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:37:21 by sharrach          #+#    #+#             */
/*   Updated: 2022/11/16 10:59:00 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**ft_free_arr(int i, char **arr)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (0);
}

static size_t	ft_split_strlen(char const *s, char c)
{
	size_t	str_len;

	str_len = 0;
	while (s[str_len] && s[str_len] != c)
		str_len++;
	return (str_len);
}

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i ++;
	if (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static	char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	if (s == NULL)
		return (0);
	str_len = len;
	if (len > ft_strlen(s) - start)
		str_len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		str_len = 0;
	str = (char *) malloc (sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < str_len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	str_len;
	char	**arr;

	if (!s)
		return (0);
	arr = (char **) malloc (sizeof(char *) * (ft_count_strs(s, c) + 1));
	if (arr == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_count_strs(s, c))
	{
		while (s[j] == c)
			j++;
		str_len = ft_split_strlen(&s[j], c);
		arr[i] = ft_substr(s, j, str_len);
		if (arr[i] == NULL)
			return (ft_free_arr(i, arr));
		j += str_len;
		i ++;
	}
	arr[i] = 0;
	return (arr);
}