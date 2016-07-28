/*
** client.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_prin 
**
** Made by christophe sundas 
** Login   <sundas_c@epitech.net
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas 
** Last update Thu Nov 27 23:26:22 2008 christophe sundas
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "client.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
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

int	my_getnbr(char *str)
{
  int	i;
  int	numb_find;
  int	ten;
  int	neg;

  i = 0;
  numb_find = 0;
  ten = 1;
  neg = 1;
  while (str[i] != '\0' && str[i] >= '+' && str[i] <= '9')
    {
      if (str[i] >= '0' && str[i] <= '9')
        {
          if (i > 0)
            numb_find = numb_find * 10;
          ten = str[i] - '0';
          numb_find = numb_find + ten;
        }
      if (str[i] == '-')
        neg = -neg;
      i = i + 1;
    }
  numb_find = (numb_find * neg);
  return (numb_find);
}
