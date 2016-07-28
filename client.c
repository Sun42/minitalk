/*
** client.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_prin
**
**  Made by christophe sundas 
**  Login   <sundas_c@epitech.net
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas
** Last update Thu Nov 27 23:30:52 2008 christophe sundas
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include "client.h"

int		main(int ac, char **av)
{
  pid_t		s_pid;
  char		*str;
  unsigned char	bintab[8];
  
  if (ac != 3)
    {
      my_putstr("usage pid string \n");
      exit(-1);
    }
  s_pid = my_getnbr(av[1]);
  str = av[2];
  while (*str)
    {
      my_char_to_bin(*str, bintab);
      send_char(bintab, s_pid);
      str++;
    }
  return (0);
}

void	send_char(unsigned char bintab[8], pid_t s_pid)
{
  int	i;
    
  i = 0;
  while (i < 8)
    {
      send_bit(bintab[i], s_pid);
      if (usleep(1) == -1)
	go_to_end();
      i++;
    }
}

void	my_char_to_bin(unsigned char c, unsigned char bintab[8])
{
  int	i;

  i = 0;
  while (i < 8)
    {
      bintab[i] = (c & 01);
      c >>= 1;
      i++;
    }
}

void	send_bit(unsigned char bit, pid_t s_pid)
{
  if (bit)
    {
      if (kill(s_pid, SIGUSR2) == -1)
        go_to_end();
    }
  else
    {
      if (kill(s_pid, SIGUSR1) == -1)
        go_to_end();
    }
}

void	go_to_end()
{
  if (errno != 0)
    my_put_nbr_error(errno);
  exit(-1);
}
