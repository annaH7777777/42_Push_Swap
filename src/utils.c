#include "push_swap.h"

void    terminate(char *str)
{
	write(1, &str, ft_strlen(str));
	exit(1);
}