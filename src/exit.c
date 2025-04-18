/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:35:02 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/16 18:47:34 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file(t_game *game)
{
	int	i;

	if (!game->file)
		return ;
	i = 0;
	while (game->file[i])
	{
		free(game->file[i]);
		i++;
	}
	free(game->file);
	game->file = NULL;
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_textures(t_game *game)
{
	if (game->tex.north.img)
		mlx_destroy_image(game->mlx, game->tex.north.img);
	if (game->tex.south.img)
		mlx_destroy_image(game->mlx, game->tex.south.img);
	if (game->tex.east.img)
		mlx_destroy_image(game->mlx, game->tex.east.img);
	if (game->tex.west.img)
		mlx_destroy_image(game->mlx, game->tex.west.img);
}

void	free_mlx(t_game *game)
{
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	exit_hook(t_game *game)
{
	clean_exit(game, EXIT_SUCCESS);
	return (0);
}

void	error_exit(t_game *game, char *message)
{
	ft_printf("Error\n%s\n", message);
	clean_exit(game, EXIT_FAILURE);
}

void	clean_exit(t_game *game, int status)
{
	free_file(game);
	free_map(game);
	free_textures(game);
	free_mlx(game);
	exit(status);
}