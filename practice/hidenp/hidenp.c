/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:31:05 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/27 17:25:12 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : hidenp
// Expected files   : hidenp.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program named hidenp that takes two strings and displays 1
// followed by a newline if the first string is hidden in the second one,
// otherwise displays 0 followed by a newline.

// Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
// find each character from s1 in s2, in the same order as they  appear in s1.
// Also, the empty string is hidden in any string.

// If the number of parameters is not 2, the program displays a newline.

// Examples :

// $>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
// 1$
// $>./hidenp "abc" "2altrb53c.sse" | cat -e
// 1$
// $>./hidenp "abc" "btarc" | cat -e
// 0$
// $>./hidenp | cat -e
// $
// $>

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int j;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;

	while (av[2][j])
	{
		if (av[1][i + 1] == '\0')
		{
			if (av[1][i] == av[2][j])
			{
				write(1, "1\n", 2);
				return (0);
			}
			j++;
		}
		else if (av[1][i] == av[2][j])
		{
			i++;
			j++;
		}
		else
			j++;
	}
	write(1, "0\n", 2);
	return (0);
}