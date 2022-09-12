
#include "../includes/pipex.h"

void	error_message(char *error)
{
	perror(error);
	exit (1);
}

int	message(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}
