/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 05:43:19 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/17 17:23:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# include "ft_stream.h"

typedef struct s_tokenizer	t_tokenizer;

struct						s_tokenizer
{
	t_is		*in;
	t_substr	current;
	uint8_t		tag;
	int			eof;
};

# define NEW_TOKENIZER(IS) (t_tokenizer){IS, {NULL, 0}, 0, 0}

# define TK_SKIP(TK, N) ((TK)->in->buff_i += N)

# define TK_SHOW(TK, N) (TK)->current = NEW_SUB(IS_CURRENT((TK)->in) - N, N)

#endif
