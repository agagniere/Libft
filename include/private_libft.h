/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_libft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 05:36:52 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/21 05:50:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_LIBFT_H
# define PRIVATE_LIBFT_H

# define _ARG_COUNT1(...) _ARG_COUNT2(A, ##__VA_ARGS__, _ARG_COUNT4)
# define _ARG_COUNT2(...) _ARG_COUNT3(__VA_ARGS__)
# define _ARG_COUNT3(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,n,...) n
# define _ARG_COUNT4 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

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
