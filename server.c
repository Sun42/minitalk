/*
** server.c  for server in /u/all/sundas_c/cu/rendu/unix/projet/my_prin
**
** Made by christophe sundas
** Login   <sundas_c@epitech.net
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas 
** Last update Thu Nov 27 23:29:44 2008 christophe sundas
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include "server.h"

void	handler(int sig_num);
void	go_to_end();

void			serveuse(int val)
{
  static unsigned char	bintab[8];
  static int	i = 0;
  
  if (val != 1 && val != 0)
    my_putstr_error("val_error, must be a binary digit! ");
  if (i < 7)
    {
      bintab[i] = val;
    }
  i++;
  if (i == 8)
    {
      my_putchar(bin_to_char(bintab));
      i = 0;
    }
}

void	handler(int sig_num)
{
  if ((signal(sig_num, handler)) == SIG_ERR)
    my_putstr_error("Server Error init signal.");
  if (sig_num == SIGUSR1)
    serveuse(0);
  else if (sig_num == SIGUSR2)
    serveuse(1);
}


int	main()
{
  int	err;
  
  if (signal(SIGUSR1, handler) == SIG_ERR)
    my_put_nbr_error(errno);
  if (signal(SIGUSR2, handler) == SIG_ERR)
    my_put_nbr_error(errno);
  my_putstr("Pid :");
  my_put_nbr(getpid());
  my_putchar('\n');
  while (42)
    sleep(1000000000);
  return (0);
}

unsigned char	bin_to_char(unsigned char bintab[8])
{
  unsigned char	c;
  int		i;

  c = 0;
  i = 0;
  while (i < 8)
    {
      bintab[i] ? c += my_power_rec(2 , i) : 0;
      i++;
    }
  return (c);
}

void	go_to_end()
{
  my_put_nbr_error(errno);
  exit(-1);
}
