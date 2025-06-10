#include "get_next_line.h"

static size_t	ft_compter_split(char const *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			j++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (j);
}

static size_t	ft_pareil(size_t i, char const *s, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

static void	ft_free(char **resultat, size_t j)
{
	while (j > 0)
	{
		j--;
		free(resultat[j]);
	}
	free(resultat);
}

char	**ft_split_n(char const *s, char c)
{
	char	**resultat;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	resultat = malloc(sizeof(char *) * (ft_compter_split(s, c) + 1));
	if (resultat == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		i = ft_pareil(i, s, c);
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
		{
			resultat[j] = ft_substr(s, start, (i - start + 1));
			if (resultat[j] == NULL)
				return (ft_free(resultat, j), NULL);
			j++;
		}
	}
	return (resultat[j] = NULL, resultat);
}