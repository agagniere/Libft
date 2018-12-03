/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepro_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:12:15 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/03 20:21:16 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPRO_PRIVATE_H
# define FT_PREPRO_PRIVATE_H

# define _ARG_COUNT1(...) _ARG_COUNT2(A, ##__VA_ARGS__, _AC4)
# define _ARG_COUNT2(...) _AC3(__VA_ARGS__)
# define _AC3(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,n,...) n
# define _AC4 24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

# define _TO_STR(M) #M
# define _CAT(A,B) A##B

# define _MIN1(A) (A)
# define _MIN2(A,B) ((A) < (B) ? (A) : (B))
# define _MIN3(A,B,C) (_MIN2(A, _MIN2(B, C)))
# define _MIN4(A,...) (_MIN2(A, _MIN3(__VA_ARGS__)))
# define _MIN5(A,...) (_MIN2(A, _MIN4(__VA_ARGS__)))
# define _MIN6(A,...) (_MIN2(A, _MIN5(__VA_ARGS__)))
# define _MIN7(A,...) (_MIN2(A, _MIN6(__VA_ARGS__)))
# define _MIN8(A,...) (_MIN2(A, _MIN7(__VA_ARGS__)))
# define _MIN9(A,...) (_MIN2(A, _MIN8(__VA_ARGS__)))

# define _MAX1(A) (A)
# define _MAX2(A,B) ((A) < (B) ? (A) : (B))
# define _MAX3(A,B,C) (_MAX2(A, _MAX2(B, C)))
# define _MAX4(A,...) (_MAX2(A, _MAX3(__VA_ARGS__)))
# define _MAX5(A,...) (_MAX2(A, _MAX4(__VA_ARGS__)))
# define _MAX6(A,...) (_MAX2(A, _MAX5(__VA_ARGS__)))
# define _MAX7(A,...) (_MAX2(A, _MAX6(__VA_ARGS__)))
# define _MAX8(A,...) (_MAX2(A, _MAX7(__VA_ARGS__)))
# define _MAX9(A,...) (_MAX2(A, _MAX8(__VA_ARGS__)))

#endif
