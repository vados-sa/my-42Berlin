#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>



char *get_next_line(int fd);

#endif