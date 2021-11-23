/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:59:45 by angagnie          #+#    #+#             */
/*   Updated: 2020/03/13 21:12:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

float       ft_modff(float f, float* out_intg);
double      ft_modf(double f, double* out_intg);
long double ft_modfl(long double f, long double* out_intg);
