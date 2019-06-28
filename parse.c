/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:32:00 by krutten           #+#    #+#             */
/*   Updated: 2019/06/28 15:32:02 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void	print_grid(t_filler *specs)
{
	int		i;

	i = -1;
	while (++i < specs->height)
	{
		ft_putstr_fd(specs->grid[i], 2);
		ft_putstr_fd("\n", 2);
	}
}

void	fill_grid(t_filler *specs)
{
	char	*line;
	int		i[3];

	get_next_line(0, &line);
	i[1] = -1;
	while (++i[1] < specs->height)
	{
		i[0] = -1;
		get_next_line(0, &line);
		while (line[++i[0]] != ' ')
		i[2] = -1;
		while (++i[2] < specs->width)
			specs->grid[i[1]][i[2]] = line[++i[0]];
		i[0] = 0;
		i[2] = 0;
	}
}

void	alloc_grid(t_filler *specs)
{
	int		i;

	specs->grid = (char **)malloc(sizeof(char *) * (specs->height + 1));
	i = -1;
	while (++i < specs->height)
	{
		specs->grid[i] = (char *)malloc(sizeof(char) * (specs->width + 1));
		specs->grid[i][specs->width] = '\0';
	}
	specs->grid[i] = NULL;
}

char	**parse_grid(t_filler *specs)
{
	char	*line;

	get_next_line(0, &line);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\n", 2);
	if (ft_strncmp(line, "Plateau ", 8))
	{
		ft_putstr_fd("Wrong header for board\n", 2);
		return (0);
	}
	specs->height = ft_atoi(line + 8);
	specs->width = ft_atoi(line + 8 + ft_digitcount(specs->height));
	ft_putstr_fd("Read header, height and width identified as :\n",2);
	alloc_grid(specs);
	fill_grid(specs);
	print_grid(specs);
	return (0);
}

int		parse_first_line(void)
{
	char	*line;

	get_next_line(0, &line);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\n", 2);
	if (ft_strcmp(line, "$$$ exec p1 : [./krutten.filler]") != 0 &&
				ft_strcmp(line, "$$$ exec p2 : [./krutten.filler]") != 0)
	{
		ft_putstr_fd("initializing player failed(first line read error)\n", 2);
		return (0);
	}
	return (line[10] - 48);
}

int		main(void)
{
	t_filler	*specs;

	if ((specs->player = parse_first_line()) == 0)
		return (0);
	specs->grid = parse_grid(specs);
	return (0);
}