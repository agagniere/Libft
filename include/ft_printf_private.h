/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:38:16 by angagnie          #+#    #+#             */
/*   Updated: 2023/02/11 18:56:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_string.h"
#include "ft_variadic.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>

#define FTPF_CV       "diouxXDOUeEfFgGaAcCsSpnbB"
#define FTPF_NUMERIC  "diouDOUxXpb"
#define FTPF_LM       "hljzLt"
#define FTPF_SWITCHES "0+- #_"

typedef struct s_modifier
{
	union
	{
		bool t[6];
		struct
		{
			bool zero;
			bool plus;
			bool minus;
			bool space;
			bool alternate;
			bool underscore;
		} n;
	} booleans;
	char conversion;
	char length;
	int  size;
	int  precision;
} t_modifier;

#define NEW_MODIFIER (t_modifier){ .size = -1, .precision = -1 };

int ft_string_vprintf(t_string* string, char const* format, va_list ap);

void db_print_modifier(t_modifier* m);
void pf_convert(t_modifier* m, t_string* out, ft_va_list ap);

int pf_cv_di(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_s(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_ws(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_c(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_wc(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_o(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_x(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_cx(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_u(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_b(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_p(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_n(t_modifier* m, t_string* out, ft_va_list ap);
int pf_cv_cb(t_modifier* m, t_string* out, ft_va_list ap);
