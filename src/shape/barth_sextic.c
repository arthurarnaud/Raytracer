/*
** barth_sextic.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May 14 23:04:44 2016 Antoine Baché
** Last update Sun May 22 22:10:46 2016 Arthur ARNAUD
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	get_dist_barth_sextic(t_ray *ray, t_intersect *inter,
				      t_vec3 tmp)
{
  double	s[7];

#include "shape/barth_sextic.txt"
  if ((inter->dist = solver_n_degree(s, 6)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_barth_sextic(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_barth_sextic(ray, &inter, ray->pos);
  if (inter.dist <= 0.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  calc_normale_barth(&inter);
  return (inter);
}
