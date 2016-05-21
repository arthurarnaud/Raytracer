/*
** bifolia.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 15 00:07:30 2016 Antoine Baché
** Last update Sat May 21 07:09:37 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

inline static double	calc_c_bifolia(t_ray *ray, t_vec3 tmp)
{
  return (6.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x + 2.0 * tmp.y * tmp.y
	  * ray->dir.x * ray->dir.x + 2.0 * tmp.z * tmp.z * ray->dir.x *
	  ray->dir.x - 3.0 * tmp.y * ray->dir.x * ray->dir.x + 2.0 * tmp.x *
	  tmp.x * ray->dir.y * ray->dir.y + 6.0 * tmp.y * tmp.y * ray->dir.y *
	  ray->dir.y + 2.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 2.0 *
	  tmp.x * tmp.x * ray->dir.z * ray->dir.z + 2.0 * tmp.y * tmp.y *
	  ray->dir.z * ray->dir.z + 6.0 * tmp.z * tmp.z * ray->dir.z *
	  ray->dir.z - 3.0 * tmp.y * ray->dir.z * ray->dir.z - 6.0 * tmp.x *
	  ray->dir.x * ray->dir.y + 8.0 * tmp.x * tmp.y * ray->dir.x *
	  ray->dir.y + 8.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.z - 6.0 *
	  tmp.z *ray->dir.y * ray->dir.z + 8.0 * tmp.y * tmp.z * ray->dir.y *
	  ray->dir.z);
}

inline static double	calc_b_bifolia(t_ray *ray, t_vec3 tmp)
{
  return (4.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y + 4.0 * tmp.x *
	  ray->dir.x * ray->dir.z * ray->dir.z - 3.0 * ray->dir.y * ray->dir.z *
	  ray->dir.z + 4.0 * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z + 4.0 *
	  tmp.x * ray->dir.x * ray->dir.x * ray->dir.x + 4.0 * tmp.y *
	  ray->dir.y *
	  ray->dir.y * ray->dir.y + 4.0 * tmp.z * ray->dir.z * ray->dir.z *
	  ray->dir.z - 3.0 * ray->dir.x * ray->dir.x * ray->dir.y + 4.0 * tmp.y *
	  ray->dir.x * ray->dir.x * ray->dir.y + 4.0 * tmp.z * ray->dir.x *
	  ray->dir.x * ray->dir.z + 4.0 * tmp.z * ray->dir.y * ray->dir.y *
	  ray->dir.z);
}

static void	get_dist_bifolia(t_ray *ray, t_intersect *inter,
				 t_vec3 tmp)
{
  double	s[5];

  s[0] = 2.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + 2.0 *
    ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z + 2.0 * ray->dir.y *
    ray->dir.y * ray->dir.z * ray->dir.z + ray->dir.x * ray->dir.x * ray->dir.x
    * ray->dir.x + ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y +
    ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[1] = calc_b_bifolia(ray, tmp);
  s[2] = calc_c_bifolia(ray, tmp);
  s[3] = 4.0 * tmp.x * tmp.y * tmp.y * ray->dir.x + 4.0 * tmp.x * tmp.z * tmp.z
    * ray->dir.x + 4.0 * tmp.x * tmp.x * tmp.x * ray->dir.x - 6.0 * tmp.x *
    tmp.y * ray->dir.x - 3.0 * tmp.x * tmp.x * ray->dir.y - 3.0 * tmp.z * tmp.z
    * ray->dir.y + 4.0 * tmp.y * tmp.z * tmp.z * ray->dir.y + 4.0 * tmp.y *
    tmp.y * tmp.y * ray->dir.y + 4.0 * tmp.x * tmp.x * tmp.y * ray->dir.y +
    4.0 * tmp.z * tmp.z * tmp.z * ray->dir.z + 4.0 * tmp.x * tmp.x * tmp.z *
    ray->dir.z + 4.0 * tmp.y * tmp.y * tmp.z * ray->dir.z - 6.0 * tmp.y * tmp.z
    * ray->dir.z;
  s[4] = 2.0 * tmp.x * tmp.x * tmp.y * tmp.y + 2.0 * tmp.x * tmp.x * tmp.z *
    tmp.z + 2.0 * tmp.y * tmp.y * tmp.z * tmp.z - 3.0 * tmp.y * tmp.z * tmp.z +
    tmp.x * tmp.x * tmp.x * tmp.x + tmp.y * tmp.y * tmp.y * tmp.y + tmp.z *
    tmp.z * tmp.z * tmp.z - 3.0 * tmp.x * tmp.x * tmp.y;
  if ((inter->dist = solver_n_degree(s, 4))
      == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_bifolia(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_bifolia(ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}