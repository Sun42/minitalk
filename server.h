/*
** client.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_prin 
**
** Made by christophe sundas
** Login   <sundas_c@epitech.net
**
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas
** Last update Thu Nov 27 23:32:03 2008 christophe sundas
*/

/*
**server.h
*/
void	handler(int sig_num);
void	go_to_end();
void	server(int val);
void	affiche_bintab(unsigned char binchar[8]);

/*
** bintab.h
*/
unsigned char	bin_to_char(unsigned char bintab[8]);
void		add_to_tab(unsigned char bintab[8], int val);

/*
**server_utils
*/
void	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
void	my_put_nbr_error(int numerror);
void	my_putstr_error(char *error);

/*
**server_utils2.h
*/
int	my_power_rec(int nb, int power);
int	my_put_nbr(int nb);
int	display(int x);
int	is_negative(int nb);

/*
**server_utils.h
*/
int	my_getnbr(char *str);
