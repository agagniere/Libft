/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:37:29 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/27 16:22:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**
** @file ft_itoa_base.c
*/

#include "libft.h"

#include "ft_prepro/tools.h" // ABS

#include <stdlib.h> // malloc

static void aux(int n, int b, char* ans, int* p)
{
	char const base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

/**
** @brief Convert an integer to an ascii character string.
**
** itoa_base :	 NxN	->	String
**  			(n,b)	|->	n expressed in base b
**
** @return : An allocated null-termminated characters array.
** If @a value is strictly negative, the first character will be '-'.
** If @a base is not in [2;36], NULL is returned.
**
** @param value : the number to be expressed in base @a base
** @param base : an integer that should be in range [2;36]
**
** @section Mathematical property used
** Let @f$ b \in [| 2 ; +\infty [| @f$
** @subsection Postulate
** 0 has a decomposition in base b : `"0"`
** @subsection Induction
** @f$ \forall n \in N* @f$,
** 	"n has a decomposition in base b"
** @f[
**  \Leftrightarrow \exists ! (k, a_0, a_1, ..., a_k) \in N^{k+2}
**  \sum_{i=0}^{k} (a_i * b^i) = 0
**  \Rightarrow k = (int)(\log(n) / \log(b))
** @f]
** where log is the natural logarithm
**
** Negative numbers can be expressed in base b by using the decomposition
** of its opposite, preceded by '-'.
*/

char* ft_itoa_base(int value, int base)
{
	char* ans;
	int   p;

	if (base < 2 || 36 < base ||
	    !(ans = (char*)malloc(sizeof(char) * ((sizeof(int) << 3) + 2))))
		return (NULL);
	p = 0;
	if (value < 0)
		ans[p++] = '-';
	aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
