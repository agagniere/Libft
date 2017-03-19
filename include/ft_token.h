/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 05:43:19 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/18 20:55:16 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# include "ft_stream.h"

typedef struct s_tokenizer	t_tokenizer;

struct						s_tokenizer
{
	t_is		*in;
	t_string	current[1];
	uint8_t		tag;
	int			eof;
};

# define NEW_TOKENIZER(IS) (t_tokenizer){IS, {NULL, 0}, 0, 0}

# define TK_SKIP(TK, N) ((TK)->in->buff_i += N)

# define TK_ACCEPT(TK, C) (fta_append((TK)->current, &(C), 1))

# define TK_EMPTY(TK) (TK)->current.size = 0

#endif
