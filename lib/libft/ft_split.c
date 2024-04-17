/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:56:08 by lbastien          #+#    #+#             */
/*   Updated: 2022/11/08 17:25:07 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<string.h>

static char	**ft_malloc_error(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

size_t	ft_countwords(const	char *s, char c)
{
	int		i;
	int		count;
	int		len;
	int		check_i;

	len = ft_strlen(s);
	count = 0;
	i = 0;
	while (i < len)
	{
		while (s[i] == c && i < len)
			i++;
		check_i = i;
		while (s[i] != c && i < len)
			i++;
		if (i > check_i)
			count++;
		i++;
	}
	return (count);
}

char	*ft_create_word(char const *s, int i, char c)
{
	char	*word;
	int		j;
	int		k;

	j = 0;
	k = i;
	while (s[k] != c && s[k])
	{
		j++;
		k++;
	}
	word = (char *)malloc(sizeof(char) * j + 1);
	if (!word)
		return (0);
	j = 0;
	while (s[i] != c && s[i])
		word[j++] = s[i++];
	word[j] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_count;
	size_t	word_index;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	word_index = 0;
	word_count = ft_countwords(s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (0);
	while (word_index < word_count)
	{
		while (s[i] == c && i < len)
			i++;
		array[word_index] = ft_create_word(s, i, c);
		if (!array[word_index])
			return (ft_malloc_error(array));
		i += ft_strlen(array[word_index]);
		word_index++;
	}
	array[word_index] = 0;
	return (array);
}
/* Main
#include<stdio.h>
int	main(void)
{
	size_t	i;
	char	str[50] = "Hello this is a test";
	size_t	word_count;
	char	**array;
	char 	c = ' ';

	i = 0;
	word_count = ft_countwords(str, c);
	printf("The number of words is : %zu\n", ft_countwords(str, c));
	array = ft_split (str, c);
	while (i < word_count)
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
*/
