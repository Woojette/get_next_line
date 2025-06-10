#include "get_next_line.h"

char    *ft_strdup(char *str)
{
    char    *resultat;
    size_t  len;
    size_t  i;

    i = 0;
    len = ft_strlen(str);
    resultat = malloc(sizeof(char) * (len + 1));
    if (resultat == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        resultat[i] = str[i];
        i++;
    }
    resultat[i] = '\0';
    return (resultat);
}