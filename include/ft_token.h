/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 05:43:19 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/19 14:35:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# include "ft_string.h"

typedef struct s_tokenizer	t_tokenizer;

struct						s_tokenizer
{
	t_is	in;
	t_token	current;
};

#endif
