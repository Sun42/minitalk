/*
** client.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_prin 
**
** Made by christophe sundas
** Login   <sundas_c@epitech.net  
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas
** Last update Thu Nov 27 23:35:53 2008 christophe sundas
*/

#include "server.h"

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
