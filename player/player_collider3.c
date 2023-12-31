/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collider3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:04:32 by lloison           #+#    #+#             */
/*   Updated: 2023/02/25 14:14:36 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_in_collider(t_data *data, t_pos tpos)
{
	t_list	*curr_tile;
	t_pos	*pos;

	curr_tile = data->player->collider.all_tiles;
	while (curr_tile)
	{
		pos = (t_pos *)curr_tile->content;
		if (pos->x == tpos.x && pos->y == tpos.y)
			return (TRUE);
		curr_tile = curr_tile->next;
	}
	return (FALSE);
}
