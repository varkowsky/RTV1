/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 00:56:14 by ebaudet           #+#    #+#             */
/*   Updated: 2014/02/15 00:56:14 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "rtv1.h"

int		eb_mlx_key_hook(int	keycode)
{
	if (keycode == KEY_ESC)
	{
		ft_error("Merci pour le poisson.");
	}
	return (0);
}