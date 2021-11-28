/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:17 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/17 09:50:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
** gnl :    N x A       ->  N x S
** |        (fd, &line) |-> (status, *line)
** -
** @param : fd : int            // File descriptor to read from.
** @param : line : char **      // The address of the output string.
** -
** @precondition : fd should already be opened
** @precondition : *line initial value should be NULL
** -
*/
int get_next_line(int const fd, char** line);
