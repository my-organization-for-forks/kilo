/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:18:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/13 20:54:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>

#include "ft_io.h"
#include "ft_exit.h"

struct termios	g_original_termios;

void	disable_raw_mode(void)
{
	struct termios	raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	ft_set_exit_handler(NULL);
}

void	enable_raw_mode(void)
{
	struct termios	raw;

	tcgetattr(STDIN_FILENO, &g_original_termios);
	ft_set_exit_handler(disable_raw_mode);
	raw = g_original_termios;
	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int	main(void)
{
	char	c;

	enable_raw_mode();
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
	{
		if (32 <= c && c <= 126)
		{
			ft_write(STDOUT_FILENO, &c, 1);
		}
		else
		{
			ft_puts(STDOUT_FILENO, "(");
			ft_putn(STDOUT_FILENO, (int)*((unsigned char *)&c));
			ft_puts(STDOUT_FILENO, ")");
		}
		ft_puts(STDOUT_FILENO, "\n");
	}
	return (ft_exit(0));
}
