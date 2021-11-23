/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 06:11:16 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/21 09:22:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft.h"

#include <wchar.h>

size_t ft_wstrlen(const wchar_t* wstr);
size_t ft_wstrconv(char* buff, const wchar_t* wstr);
size_t ft_wstrnconv(char* buff, const wchar_t* wstr, size_t n);
size_t ft_widetoa(char* buff, wint_t w);
