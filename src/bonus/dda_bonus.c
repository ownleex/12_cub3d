/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:18:31 by cparodi           #+#    #+#             */
/*   Updated: 2025/05/05 19:25:05 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	calculate_next_step(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step.x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step.y;
		ray->side = 1;
	}
}

static void	run_dda(t_game *game, t_ray *ray)
{
	bool	hit;
	t_door	*door;

	hit = false;
	while (!hit)
	{
		calculate_next_step(ray);
		if (game->map[ray->map_y][ray->map_x] == '1')
			hit = true;
		else if (game->map[ray->map_y][ray->map_x] == 'D')
		{
			door = game->door_list;
			while (door)
			{
				if (!door->is_open && (ray->map_y == door->y && \
ray->map_x == door->x))
					hit = true;
				door = door->next;
			}
		}
	}
}

static void	wall_distance(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos.x
				+ (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos.y
				+ (1 - ray->step.y) / 2) / ray->dir.y;
}

void	perform_dda(t_game *game, t_ray *ray)
{
	run_dda(game, ray);
	wall_distance(game, ray);
}
