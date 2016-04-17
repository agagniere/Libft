/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:37:29 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/17 15:21:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define ABS(v) ((v) < 0 ? -(v) : (v))

static void		aux(int n, int b, char *ans, int *p)
{
	char const	base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

/*
** itoa_base :	 NxN	->	String
** |			(n,b)	|->	n expressed in base b
** -
** @return : An allocated null-termminated characters array.
** | If _value_ is strictly negative, the first character will be '-'.
** | If _base_ is not in [2;36], NULL is returned.
** -
** @param _value_ : the number to be expressed in base _base_
** @param _base_ : an integer that should be in range [2;36]
** -
** -----===== Mathematical property used =====-----
** Let b in [| 2 ; +infinity [|
** Postulate : 0 has a decomposition in base b : "0"
** for all n in N*,
** |	"n has a decomposition in base b"
** | <=> there exist a unique (k, a0, a1, ..., ak) in N^(k+2)
** | such that the sum for i = 0 to k of	(ai * b^i)
** | equals n, with ak > 0.
** | => k = (int)(log(n) / log(b))	where log in the natural logarithm
** -
** Negative numbers can be expressed in base b by using the decomposition
** of its opposite, preceded by '-'.
*/

char			*ft_itoa_base(int value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 36 < base
		|| !(ans = (char *)malloc(sizeof(char) * (sizeof(int) * 8 + 1))))
		return (NULL);
	p = 0;
	if (value < 0)
		ans[p++] = '-';
	else
		aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
