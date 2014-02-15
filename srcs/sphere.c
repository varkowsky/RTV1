/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 21:19:42 by ebaudet           #+#    #+#             */
/*   Updated: 2014/02/14 21:19:42 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "rtv1.h"

t_sphere	*sphere_new(double x, double y, double z, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->position = vector_new(x, y, z);
	sphere->radius = radius;
	return (sphere);
}

void		sphere_del(t_sphere *sphere)
{
	if (sphere)
	{
		vector_del(sphere->position);
		free(sphere);
		sphere = NULL;
	}
}

int			intersection_sphere(t_sphere *sphere, t_ray *ray, double *t)
{
	t_vector	*dist;
	double		b;
	double		d;
	double		t0;
	double		t1;
	int			result;

	dist = vector_copy(sphere->position);
	vector_sub(dist, ray->o);
	b = vector_dot(ray->d, dist);
	d = (b * b) - vector_dot(dist, dist) + sphere->radius * sphere->radius;
	if (d < 0)
		return (-1);
	t0 = b - sqrt(d);
	t1 = b + sqrt(d);
	result = -1;
	if ((t0 > 0.1) && (t0 < *t))
	{
		t0 = *t;
		result = 0; 
	}
	if ((t1 > 0.1) && (t1 < *t))
	{
		t1 = *t;
		result = 0;
	}
	return (result);
}
