/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:50:20 by krutten           #+#    #+#             */
/*   Updated: 2019/06/28 16:50:20 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_filler
{
	char			**grid;
	int				player;
	int				height;
	int				width;
}					t_filler;
#endif