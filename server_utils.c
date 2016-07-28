/*
** server_utils.c for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/minitalk
**
** Made by christophe sundas  
** Login   <sundas_c@epitech.net
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas 
** Last update Thu Nov 27 23:32:45 2008 christophe sundas
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "server.h"

void	my_putstr_error(char *error)
{
  write(2, error, my_strlen(error));
}

void	my_put_nbr_error(int numerror)
{
  char	*error;

  error = strerror(numerror);
  write(2, error, my_strlen(error));
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*str)
    {
      i++;
      str++;
    }
  return (i);
}

int	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
