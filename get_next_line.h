#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 1
# endif

char *get_next_line(int fd);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(char *str);
char **ft_split_n(char const *s, char c);
size_t ft_strlen(char *str);


#endif