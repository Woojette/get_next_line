#include "get_next_line.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  i;
    size_t  j;
    size_t  len;
    char    *resultat;

    i = 0;
    j = 0;
    len = ft_strlen(s1) + ft_strlen(s2);
    resultat = malloc(sizeof(char) * (len + 1));
    if (resultat == NULL)
        return (NULL);
    while (s1[i] != '\0')
    {
        resultat[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        resultat[j] = s2[j];
        j++;
    }
    resultat[i + j] = '\0';
    return (resultat);
}