#include "get_next_line.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int    i;
    size_t          n;
    char            *resultat;

    i = 0;
    n = 0;
    if (len > (ft_strlen((char *)s) - start))
        len = ft_strlen((char *)s) - start;
    if (start >= ft_strlen((char *)s))
        return (strdup(""));
    resultat = malloc((len + 1) * sizeof(char));
    if (resultat == NULL)
        return (NULL);
    while (s[start + i] != '\0' && n < len && start < ft_strlen((char *)s))
    {
        resultat[i] = s[start + i];
        n++;
        i++;
    }
    resultat[i] = '\0';
    return (resultat);
}