/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:29:49 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/05 18:14:35 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		clean_exit(game, EXIT_SUCCESS);
	else if (keycode == KEY_W)
		game->keys[KEY_W] = 1;
	else if (keycode == KEY_A)
		game->keys[KEY_A] = 1;
	else if (keycode == KEY_S)
		game->keys[KEY_S] = 1;
	else if (keycode == KEY_D)
		game->keys[KEY_D] = 1;
	else if (keycode == KEY_LEFT)
		game->key_left = 1;
	else if (keycode == KEY_RIGHT)
		game->key_right = 1;
	else if (keycode == KEY_E)
		game->keys[KEY_E] = 1;
	else if (keycode == KEY_TAB)
	{
		game->mouse_captured = !game->mouse_captured;
		mlx_mouse_move(game->mlx, game->win, \
WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys[KEY_W] = 0;
	else if (keycode == KEY_A)
		game->keys[KEY_A] = 0;
	else if (keycode == KEY_S)
		game->keys[KEY_S] = 0;
	else if (keycode == KEY_D)
		game->keys[KEY_D] = 0;
	else if (keycode == KEY_LEFT)
		game->key_left = 0;
	else if (keycode == KEY_RIGHT)
		game->key_right = 0;
	return (0);
}

int	update_game(t_game *game)
{
	game->frame++;
	if (game->keys[KEY_W])
		move_forward(game);
	if (game->keys[KEY_S])
		move_backward(game);
	if (game->keys[KEY_A])
		move_left(game);
	if (game->keys[KEY_D])
		move_right(game);
	if (game->key_left)
		rotate(game, -ROT_SPEED);
	if (game->key_right)
		rotate(game, ROT_SPEED);
	else if (game->keys[KEY_E])
	{
		interact_door(game);
		game->keys[KEY_E] = 0;
	}
	return (render(game));
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		printf("Error\nUsage: ./cub3D <map.cub>\n");
		return (EXIT_FAILURE);
	}
	if (!is_valid_ext(argv[1], ".cub"))
	{
		printf("Error\nInvalid file extension. Expected .cub\n");
		return (EXIT_FAILURE);
	}
	game = parsing(game, argv[1]);
	printf("Usage:\n- [E] to open and close doors\n- [TAB] to rotate with mouse\n\
- [<-] & [->] to rotate\n- [W] [A] [S] [D] to move\n\
- [ESC] or click X window to quit\n");
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 6, (1L << 6), mouse_move, &game);
	mlx_hook(game.win, 17, 0, exit_hook, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
