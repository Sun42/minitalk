/*
** client.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_prin
**
**  Made by christophe sundas
**  Login   <sundas_c@epitech.net
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas 
** Last update Thu Nov 27 23:25:20 2008 christophe sundas
*/

#ifndef __MINITALK_H__
# define __MINITALK_H__

/*
** client.h
*/
void	send_char(unsigned char bintab[8], pid_t s_pid);
void	my_char_to_bin(unsigned char c, unsigned char bintab[8]);

/*
** client_utils.h
*/
void	send_bit(unsigned char bit, pid_t s_pid);
void	go_to_end();
void	my_putchar(char c);
int	my_putstr(char *str);
void	my_put_nbr_error(int numerror);
int	my_strlen(char *str);
int	my_getnbr(char *str);

#endif
