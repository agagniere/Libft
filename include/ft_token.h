/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 05:43:19 by angagnie          #+#    #+#             */
/*   Updated: 2017/04/19 15:16:24 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# include "ft_stream.h"
# include "stdint.h"

typedef struct s_tokenizer	t_tokenizer;
typedef struct s_token		t_token;

struct						s_token
{
	uint8_t		tag;
	t_substr	data;
};

struct						s_tokenizer
{
	const t_is	*in;
	const void	*map;
	t_token		current;
	int			eof;
};

/*
** Fields shouldnt be modified by the user.
*/

# define NEW_TOKENIZER(IS,M) (t_tokenizer){IS, M, NEW_TOKEN, 0}
# define NEW_TOKEN (t_token){0, {NULL, 0}}

#endif
