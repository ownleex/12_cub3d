/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:34:04 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/25 16:12:24 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	load_texture(t_game *game, t_texture *texture, char *path)
{
	while (*path && (*path == ' ' || *path == '\t'))
		path++;
	texture->img = mlx_xpm_file_to_image(game->mlx, path, \
&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("Error\nFailed to load texture: %s\n", path);
		return (false);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
&texture->line_length, &texture->endian);
	if (texture->width != 64 || texture->height != 64)
	{
		printf("Error\nThe texture %s is not 64x64 pixels \
(current dimensions: %dx%d)\n", path, texture->width, texture->height);
		mlx_destroy_image(game->mlx, texture->img);
		texture->img = NULL;
		return (false);
	}
	return (true);
}

int	get_tex_pixel(t_texture *texture, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= texture->width || y >= texture->height)
		return (0);
	dst = texture->addr + \
(y * texture->line_length + x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

t_texture	*select_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step.x < 0)
			return (&game->tex.west);
		else
			return (&game->tex.east);
	}
	else
	{
		if (ray->step.y < 0)
		{
			if (((game->frame / 15) % 4) == 0)
				return (&game->tex.north);
			else if (((game->frame / 15) % 4) == 1)
				return (&game->tex.north_a);
			else if (((game->frame / 15) % 4) == 2)
				return (&game->tex.north_b);
			else
				return (&game->tex.north_c);
		}
		else
			return (&game->tex.south);
	}
}
