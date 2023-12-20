/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:45 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/18 16:02:07 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_separator(char s, char charset)
{
	return (s == charset);
}

static int	count_strings(char const *str, char charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && check_separator(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !check_separator(str[i], charset))
			i++;
	}
	return (count);
}

static char	*ft_word(const char **str, char charset)
{
	int			len_word;
	int			i;
	const char	*start;
	char		*word;

	len_word = 0;
	start = *str;
	while (**str && **str != charset)
	{
		len_word++;
		(*str)++;
	}
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	*str = start;
	i = 0;
	while (i < len_word)
	{
		word[i] = **str;
		(*str)++;
		i++;
	}
	word[len_word] = '\0';
	return (word);
}

static void	*ft_free_all_split_alloc(char **split, size_t elts)
{
	size_t	i;

	i = 0;
	while (i < elts)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	char	**strings;

	if (!str)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (count_strings(str, c) + 1));
	if (!strings)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && check_separator(*str, c))
			str++;
		if (*str)
		{
			strings[i] = ft_word(&str, c);
			if (!strings[i])
				return (ft_free_all_split_alloc(strings, i));
			i++;
		}
	}
	strings[i] = 0;
	return (strings);
}
