/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:07:28 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/04/13 19:32:52 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = 10 * nb + (nptr[i] - 48);
		i++;
	}
	return (nb * sign);
}
// calculates the number an atribute can be translated
// does not allow buffer overflow or returning the number
// if trash values follow the digit part.
int	ft_atoi2(const char *nptr,	int i, int sign)
{
	long long	nb;

	nb = 0;
	if (!nptr[0])
		ft_error();
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-') && nptr[i + 1] != 0)
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		if (nb * 10 < nb)
			ft_error();
		nb = 10 * nb + (nptr[i] - 48);
		i++;
	}
	nb = nb * sign;
	if (nptr[i] || nb > 2147483647 || nb < -2147483648)
		ft_error();
	return (nb);
}