#ifdef GET_NEXT_LINE_H
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
size_t ft_strlen(char *str);

#endif