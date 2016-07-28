/*
**  client.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_prin 
**
** Made by christophe sundas 
** Login   <sundas_c@epitech.net 
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas 
** Last update Thu Nov 27 23:33:50 2008 christophe sundas
*/

#include "server.h"

int	my_power_rec(int nb, int power)
{
  int	res;

  if (power == 0)
    {
      return (1);
    }
  if (power < 0)
    {
      return (0);
    }
  if (power > 0)
    {
      res = my_power_rec(nb, power - 1);
      if (res > (2147483647 / nb))
        {
          return (0);
        }
      return (res * nb);
    }
}

int	my_put_nbr(int nb)
{
  int	base;
  int	flag;
  int	resultat;

  flag = 0;
  base = 10000000;

  if (is_negative(nb) == 1)
    {
      nb = nb - (nb * 2);
    }
  while (base >= 1)
    {
      resultat=(nb / base) % 10;
      if ((resultat != 0 || flag == 1) || (base == 1 && flag == 0))
        {
          flag = 1;
          display(resultat);
        }
      base = base / 10;
    }
  return (0);
}

int	display(int x)
{
  my_putchar(x + 48);
  return (0);
}

int	is_negative(int nb)
{
  int	bit;

  if (nb < 0)
    {
      my_putchar('-');
      bit = 1;
    }
  if (nb >= 0)
    {
      bit = 0;
    }
  return (bit);
}
