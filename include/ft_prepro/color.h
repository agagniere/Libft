/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:47:45 by angagnie          #+#    #+#             */
/*   Updated: 2022/04/03 11:51:33 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools.h"

#define NORMAL     0
#define BOLD       1
#define DIM        2
#define ITALIC     3
#define UNDERLINED 4
#define NEGATIVE   6

#define BLACK      30
#define RED        31
#define GREEN      32
#define YELLOW     33
#define BLUE       34
#define PURPLE     35
#define CYAN       36
#define LIGHT_GREY 37
#define DEFAULT    39
#define WHITE      97

#define BG_BLACK      40
#define BG_RED        41
#define BG_GREEN      42
#define BG_YELLOW     43
#define BG_BLUE       44
#define BG_PURPLE     45
#define BG_CYAN       46
#define BG_LIGHT_GREY 47
#define BG_DEFAULT    49
#define BG_WHITE      107

#define COLOR(...) PP_CAT(PRIVATE_COLOR_, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

/* Private: */

#define PRIVATE_COLOR_1(A) PP_STR(\e[PP_CAT(A,m))
#define PRIVATE_COLOR_2(A, B) PP_STR(\e[A;PP_CAT(B,m))
#define PRIVATE_COLOR_3(A, B, C) PP_STR(\e[A;B;PP_CAT(C,m))
#define PRIVATE_COLOR_4(A, B, C, D) PP_STR(\e[A;B;C;PP_CAT(D,m))
#define PRIVATE_COLOR_5(A, B, C, D, E) PP_STR(\e[A;B;C;D;PP_CAT(E,m))
