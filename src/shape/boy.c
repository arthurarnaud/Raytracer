/*
** boy.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May 14 17:38:13 2016 Antoine Baché
** Last update Sat May 21 07:10:30 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

inline static double	calc_g_boy(t_ray *ray, t_vec3 *tmp)
{
  return (-2187.0 * tmp->x * tmp->x * tmp->x * tmp->x * tmp->y * tmp->y - 144.0
	  * tmp->x * tmp->x * tmp->z * tmp->z - 1620.0 * tmp->x * tmp->x *
	  tmp->y * tmp->y * tmp->z * tmp->z - 144.0 * tmp->y * tmp->y * tmp->z
	  * tmp->z + 610.9402588 * tmp->y * tmp->y * tmp->y * tmp->z * tmp->z -
	  810.0 * tmp->x * tmp->x * tmp->x * tmp->x * tmp->z * tmp->z - 810.0 *
	  tmp->y * tmp->y * tmp->y * tmp->y * tmp->z * tmp->z - 1832.820776 *
	  tmp->x * tmp->x * tmp->y * tmp->z * tmp->z + 916.4103882 * tmp->x *
	  tmp->y * tmp->y * tmp->z * tmp->z * tmp->z - 305.4701294 * tmp->x *
	  tmp->x * tmp->x * tmp->z * tmp->z * tmp->z - 610.9402588 * tmp->y *
	  tmp->y * tmp->y * tmp->z * tmp->z * tmp->z + 64.0 * tmp->z * tmp->z *
	  tmp->z + 1832.820776 * tmp->x * tmp->x * tmp->y * tmp->z * tmp->z *
	  tmp->z - 2187.0 * tmp->x * tmp->x * tmp->y * tmp->y * tmp->y * tmp->y
	  + 324.0 * tmp->x * tmp->x * tmp->z * tmp->z * tmp->z * tmp->z + 324.0
	  * tmp->y * tmp->y * tmp->z * tmp->z * tmp->z * tmp->z - 288.0 *
	  tmp->z * tmp->z * tmp->z * tmp->z + 432.0 * tmp->z * tmp->z * tmp->z
	  * tmp->z * tmp->z - 729.0 * tmp->x * tmp->x * tmp->x * tmp->x *
	  tmp->x * tmp->x - 729.0 * tmp->y * tmp->y * tmp->y * tmp->y * tmp->y
	  * tmp->y - 216.0 * tmp->z * tmp->z * tmp->z * tmp->z * tmp->z *
	  tmp->z + 648.0 * tmp->x * tmp->x * tmp->y * tmp->y * tmp->z -
	  2749.231165 * tmp->x * tmp->x * tmp->x * tmp->y * tmp->y * tmp->z +
	  324.0 * tmp->x * tmp->x * tmp->x * tmp->x * tmp->z + 324.0 * tmp->y *
	  tmp->y * tmp->y * tmp->y * tmp->z - 4123.846747 * tmp->x * tmp->y *
	  tmp->y * tmp->y * tmp->y * tmp->z + 1374.615582 * tmp->x * tmp->x *
	  tmp->x * tmp->x * tmp->x * tmp->z);
}

inline static double	calc_f_boy(t_ray *ray, t_vec3 *tmp)
{
  return (-8748.0 * tmp->x * tmp->x * tmp->x * tmp->y * tmp->y * ray->dir.x -
	  3240.0 * tmp->x * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.x - 3240.0 * tmp->x * tmp->x * tmp->x * tmp->z * tmp->z * ray->dir.x - 288.0 * tmp->x * tmp->z * tmp->z * ray->dir.x - 3665.641552 * tmp->x * tmp->y * tmp->z * tmp->z * ray->dir.x - 916.4103882 * tmp->x * tmp->x * tmp->z * tmp->z * tmp->z * ray->dir.x + 916.4103882 * tmp->y * tmp->y * tmp->z * tmp->z * tmp->z * ray->dir.x + 3665.641552 * tmp->x * tmp->y * tmp->z * tmp->z * tmp->z * ray->dir.x - 4374.0 * tmp->x * tmp->y * tmp->y * tmp->y * tmp->y * ray->dir.x + 648.0 * tmp->x * tmp->z * tmp->z * tmp->z * tmp->z * ray->dir.x - 4374.0 * tmp->x * tmp->x * tmp->x * tmp->x * tmp->x * ray->dir.x - 8247.693495 * tmp->x * tmp->x * tmp->y * tmp->y * tmp->z * ray->dir.x + 1296.0 * tmp->x * tmp->y * tmp->y * tmp->z * ray->dir.x + 1296.0 * tmp->x * tmp->x * tmp->x * tmp->z * ray->dir.x + 6873.07791 * tmp->x * tmp->x * tmp->x * tmp->x * tmp->z * ray->dir.x - 4123.846747 * tmp->y * tmp->y * tmp->y * tmp->y * tmp->z * ray->dir.x - 1832.820776 * tmp->x * tmp->x * tmp->z * tmp->z * ray->dir.y + 1832.8207764 * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.y - 3240.0 * tmp->y * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.y - 3240.0 * tmp->x * tmp->x * tmp->y * tmp->z * tmp->z * ray->dir.y - 288.0 * tmp->y * tmp->z * tmp->z * ray->dir.y - 8748.0 * tmp->x * tmp->x * tmp->y * tmp->y * tmp->y * ray->dir.y + 1832.820776 * tmp->x * tmp->x * tmp->z * tmp->z * tmp->z * ray->dir.y - 1832.8207764 * tmp->y * tmp->y * tmp->z * tmp->z * tmp->z * ray->dir.y + 1832.8207764 * tmp->x * tmp->y * tmp->z * tmp->z * tmp->z * ray->dir.y + 648.0 * tmp->y * tmp->z * tmp->z * tmp->z * tmp->z * ray->dir.y - 4374.0 * tmp->y * tmp->y * tmp->y * tmp->y * tmp->y * ray->dir.y - 4374.0 * tmp->x * tmp->x * tmp->x * tmp->x * tmp->y * ray->dir.y + 1296.0 * tmp->y * tmp->y * tmp->y * tmp->z * ray->dir.y - 16495.386988 * tmp->x * tmp->y * tmp->y * tmp->y * tmp->z * ray->dir.y + 1296.0 * tmp->x * tmp->x * tmp->y * tmp->z * ray->dir.y - 5498.46233 * tmp->x * tmp->x * tmp->x * tmp->y * tmp->z * ray->dir.y + 648.0 * tmp->x * tmp->x * tmp->y * tmp->y * ray->dir.z - 2749.231165 * tmp->x * tmp->x * tmp->x * tmp->y * tmp->y * ray->dir.z + 192.0 * tmp->z * tmp->z * ray->dir.z + 2749.2311646 * tmp->x * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.z - 916.4103882 * tmp->x * tmp->x * tmp->x * tmp->z * tmp->z * ray->dir.z - 1832.8207764 * tmp->y * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.z + 5498.462328 * tmp->x * tmp->x * tmp->y * tmp->z * tmp->z * ray->dir.z - 1152.0 * tmp->z * tmp->z * tmp->z * ray->dir.z + 1296.0 * tmp->x * tmp->x * tmp->z * tmp->z * tmp->z * ray->dir.z + 1296.0 * tmp->y * tmp->y * tmp->z * tmp->z * tmp->z * ray->dir.z + 324.0 * tmp->x * tmp->x * tmp->x * tmp->x * ray->dir.z + 324.0 * tmp->y * tmp->y * tmp->y * tmp->y * ray->dir.z - 4123.846747 * tmp->x * tmp->y * tmp->y * tmp->y * tmp->y * ray->dir.z + 2160.0 * tmp->z * tmp->z * tmp->z * tmp->z * ray->dir.z + 1374.615582 * tmp->x * tmp->x * tmp->x * tmp->x * tmp->x * ray->dir.z - 1296.0 * tmp->z * tmp->z * tmp->z * tmp->z * tmp->z * ray->dir.z - 288.0 * tmp->x * tmp->x * tmp->z * ray->dir.z - 3240.0 * tmp->x * tmp->x * tmp->y * tmp->y * tmp->z * ray->dir.z - 288.0 * tmp->y * tmp->y * tmp->z * ray->dir.z + 1221.8805176 * tmp->y * tmp->y * tmp->y * tmp->z * ray->dir.z - 1620.0 * tmp->x * tmp->x * tmp->x * tmp->x * tmp->z * ray->dir.z - 1620.0 * tmp->y * tmp->y * tmp->y * tmp->y * tmp->z * ray->dir.z - 3665.641552 * tmp->x * tmp->x * tmp->y * tmp->z * ray->dir.z);
}

inline static double	calc_e_boy(t_ray *ray, t_vec3 *tmp)
{
  return (-13122.0 * tmp->x * tmp->x * tmp->y * tmp->y * ray->dir.x * ray->dir.x - 4860.0 * tmp->x * tmp->x * tmp->z * tmp->z * ray->dir.x * ray->dir.x - 1620.0 * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.x * ray->dir.x - 144.0 * tmp->z * tmp->z * ray->dir.x * ray->dir.x - 1832.820776 * tmp->y * tmp->z * tmp->z * ray->dir.x * ray->dir.x - 916.4103882 * tmp->x * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.x + 1832.820776 * tmp->y * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.x - 10935.0 * tmp->x * tmp->x * tmp->x * tmp->x * ray->dir.x * ray->dir.x - 2187.0 * tmp->y * tmp->y * tmp->y * tmp->y * ray->dir.x * ray->dir.x + 324.0 * tmp->z * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.x + 1944.0 * tmp->x * tmp->x * tmp->z * ray->dir.x * ray->dir.x + 648.0 * tmp->y * tmp->y * tmp->z * ray->dir.x * ray->dir.x - 8247.693495 * tmp->x * tmp->y * tmp->y * tmp->z * ray->dir.x * ray->dir.x + 13746.15582 * tmp->x * tmp->x * tmp->x * tmp->z * ray->dir.x * ray->dir.x - 13122.0 * tmp->x * tmp->x * tmp->y * tmp->y * ray->dir.y * ray->dir.y - 1620.0 * tmp->x * tmp->x * tmp->z * tmp->z * ray->dir.y * ray->dir.y - 4860.0 * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.y * ray->dir.y - 144.0 * tmp->z * tmp->z * ray->dir.y * ray->dir.y + 1832.8207764 * tmp->y * tmp->z * tmp->z * ray->dir.y * ray->dir.y + 916.4103882 * tmp->x * tmp->z * tmp->z * tmp->z * ray->dir.y * ray->dir.y - 1832.8207764 * tmp->y * tmp->z * tmp->z * tmp->z * ray->dir.y * ray->dir.y - 2187.0 * tmp->x * tmp->x * tmp->x * tmp->x * ray->dir.y * ray->dir.y - 10935.0 * tmp->y * tmp->y * tmp->y * tmp->y * ray->dir.y * ray->dir.y + 324.0 * tmp->z * tmp->z * tmp->z * tmp->z * ray->dir.y * ray->dir.y + 648.0 * tmp->x * tmp->x * tmp->z * ray->dir.y * ray->dir.y + 1944.0 * tmp->y * tmp->y * tmp->z * ray->dir.y * ray->dir.y - 24743.080482 * tmp->x * tmp->y * tmp->y * tmp->z * ray->dir.y * ray->dir.y - 2749.231165 * tmp->x * tmp->x * tmp->x * tmp->z * ray->dir.y * ray->dir.y - 144.0 * tmp->x * tmp->x * ray->dir.z * ray->dir.z - 1620.0 * tmp->x * tmp->x * tmp->y * tmp->y * ray->dir.z * ray->dir.z - 144.0 * tmp->y * tmp->y * ray->dir.z * ray->dir.z + 1944.0 * tmp->x * tmp->x * tmp->z * tmp->z * ray->dir.z * ray->dir.z + 1944.0 * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.z * ray->dir.z - 1728.0 * tmp->z * tmp->z * ray->dir.z * ray->dir.z + 610.9402588 * tmp->y * tmp->y * tmp->y * ray->dir.z * ray->dir.z + 4320.0 * tmp->z * tmp->z * tmp->z * ray->dir.z * ray->dir.z - 810.0 * tmp->x * tmp->x * tmp->x * tmp->x * ray->dir.z * ray->dir.z - 810.0 * tmp->y * tmp->y * tmp->y * tmp->y * ray->dir.z * ray->dir.z - 3240.0 * tmp->z * tmp->z * tmp->z * tmp->z * ray->dir.z * ray->dir.z - 1832.820776 * tmp->x * tmp->x * tmp->y * ray->dir.z * ray->dir.z + 192.0 * tmp->z * ray->dir.z * ray->dir.z + 2749.2311646 * tmp->x * tmp->y * tmp->y * tmp->z * ray->dir.z * ray->dir.z - 916.4103882 * tmp->x * tmp->x * tmp->x * tmp->z * ray->dir.z * ray->dir.z - 1832.8207764 * tmp->y * tmp->y * tmp->y * tmp->z * ray->dir.z * ray->dir.z + 5498.462328 * tmp->x * tmp->x * tmp->y * tmp->z * ray->dir.z * ray->dir.z - 3665.641552 * tmp->x * tmp->z * tmp->z * ray->dir.x * ray->dir.y - 6480.0 * tmp->x * tmp->y * tmp->z * tmp->z * ray->dir.x * ray->dir.y - 17496.0 * tmp->x * tmp->y * tmp->y * tmp->y * ray->dir.x * ray->dir.y + 3665.641552 * tmp->x * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.y + 1832.8207764 * tmp->y * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.y - 17496.0 * tmp->x * tmp->x * tmp->x * tmp->y * ray->dir.x * ray->dir.y - 16495.386988 * tmp->y * tmp->y * tmp->y * tmp->z * ray->dir.x * ray->dir.y - 16495.38699 * tmp->x * tmp->x * tmp->y * tmp->z * ray->dir.x * ray->dir.y + 2592.0 * tmp->x * tmp->y * tmp->z * ray->dir.x * ray->dir.y - 8247.693495 * tmp->x * tmp->x * tmp->y * tmp->y * ray->dir.x * ray->dir.z + 1296.0 * tmp->x * tmp->y * tmp->y * ray->dir.x * ray->dir.z - 2749.2311646 * tmp->x * tmp->x * tmp->z * tmp->z * ray->dir.x * ray->dir.z + 2749.2311646 * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.x * ray->dir.z + 10996.924656 * tmp->x * tmp->y * tmp->z * tmp->z * ray->dir.x * ray->dir.z + 1296.0 * tmp->x * tmp->x * tmp->x * ray->dir.x * ray->dir.z + 2592.0 * tmp->x * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.z + 6873.07791 * tmp->x * tmp->x * tmp->x * tmp->x * ray->dir.x * ray->dir.z - 4123.846747 * tmp->y * tmp->y * tmp->y * tmp->y * ray->dir.x * ray->dir.z - 6480.0 * tmp->x * tmp->y * tmp->y * tmp->z * ray->dir.x * ray->dir.z - 6480.0 * tmp->x * tmp->x * tmp->x * tmp->z * ray->dir.x * ray->dir.z - 576.0 * tmp->x * tmp->z * ray->dir.x * ray->dir.z - 7331.283104 * tmp->x * tmp->y * tmp->z * ray->dir.x * ray->dir.z + 5498.462328 * tmp->x * tmp->x * tmp->z * tmp->z * ray->dir.y * ray->dir.z - 5498.4623292 * tmp->y * tmp->y * tmp->z * tmp->z * ray->dir.y * ray->dir.z + 5498.4623292 * tmp->x * tmp->y * tmp->z * tmp->z * ray->dir.y * ray->dir.z + 1296.0 * tmp->y * tmp->y * tmp->y * ray->dir.y * ray->dir.z - 16495.386988 * tmp->x * tmp->y * tmp->y * tmp->y * ray->dir.y * ray->dir.z + 2592.0 * tmp->y * tmp->z * tmp->z * tmp->z * ray->dir.y * ray->dir.z + 1296.0 * tmp->x * tmp->x * tmp->y * ray->dir.y * ray->dir.z - 5498.46233 * tmp->x * tmp->x * tmp->x * tmp->y * ray->dir.y * ray->dir.z - 3665.641552 * tmp->x * tmp->x * tmp->z * ray->dir.y * ray->dir.z + 3665.6415528 * tmp->y * tmp->y * tmp->z * ray->dir.y * ray->dir.z - 6480.0 * tmp->y * tmp->y * tmp->y * tmp->z * ray->dir.y * ray->dir.z - 6480.0 * tmp->x * tmp->x * tmp->y * tmp->z * ray->dir.y * ray->dir.z - 576.0 * tmp->y * tmp->z * ray->dir.y * ray->dir.z);
}

inline static double	calc_d_boy(t_ray *ray, t_vec3 *tmp)
{
  return (-26244.0 * tmp->x * tmp->y * tmp->y * ray->dir.x * ray->dir.y *
	  ray->dir.y - 3240.0 * tmp->x * tmp->z * tmp->z * ray->dir.x * ray->dir.y * ray->dir.y - 8748.0 * tmp->x * tmp->x * tmp->x * ray->dir.x * ray->dir.y * ray->dir.y + 916.4103882 * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.y * ray->dir.y - 8247.693495 * tmp->x * tmp->x * tmp->z * ray->dir.x * ray->dir.y * ray->dir.y - 24743.080482 * tmp->y * tmp->y * tmp->z * ray->dir.x * ray->dir.y * ray->dir.y + 1296.0 * tmp->x * tmp->z * ray->dir.x * ray->dir.y * ray->dir.y - 3240.0 * tmp->x * tmp->y * tmp->y * ray->dir.x * ray->dir.z * ray->dir.z + 3888.0 * tmp->x * tmp->z * tmp->z * ray->dir.x * ray->dir.z * ray->dir.z - 3240.0 * tmp->x * tmp->x * tmp->x * ray->dir.x * ray->dir.z * ray->dir.z - 288.0 * tmp->x * ray->dir.x * ray->dir.z * ray->dir.z - 3665.641552 * tmp->x * tmp->y * ray->dir.x * ray->dir.z * ray->dir.z - 2749.2311646 * tmp->x * tmp->x * tmp->z * ray->dir.x * ray->dir.z * ray->dir.z + 2749.2311646 * tmp->y * tmp->y * tmp->z * ray->dir.x * ray->dir.z * ray->dir.z + 10996.924656 * tmp->x * tmp->y * tmp->z * ray->dir.x * ray->dir.z * ray->dir.z - 1832.820776 * tmp->x * tmp->x * ray->dir.y * ray->dir.z * ray->dir.z + 1832.8207764 * tmp->y * tmp->y * ray->dir.y * ray->dir.z * ray->dir.z + 3888.0 * tmp->y * tmp->z * tmp->z * ray->dir.y * ray->dir.z * ray->dir.z - 3240.0 * tmp->y * tmp->y * tmp->y * ray->dir.y * ray->dir.z * ray->dir.z - 3240.0 * tmp->x * tmp->x * tmp->y * ray->dir.y * ray->dir.z * ray->dir.z - 288.0 * tmp->y * ray->dir.y * ray->dir.z * ray->dir.z + 5498.462328 * tmp->x * tmp->x * tmp->z * ray->dir.y * ray->dir.z * ray->dir.z - 5498.4623292 * tmp->y * tmp->y * tmp->z * ray->dir.y * ray->dir.z * ray->dir.z + 5498.4623292 * tmp->x * tmp->y * tmp->z * ray->dir.y * ray->dir.z * ray->dir.z - 8748.0 * tmp->x * tmp->y * tmp->y * ray->dir.x * ray->dir.x * ray->dir.x - 3240.0 * tmp->x * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.x - 14580.0 * tmp->x * tmp->x * tmp->x * ray->dir.x * ray->dir.x * ray->dir.x - 305.4701294 * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.x + 13746.15582 * tmp->x * tmp->x * tmp->z * ray->dir.x * ray->dir.x * ray->dir.x - 2749.231165 * tmp->y * tmp->y * tmp->z * ray->dir.x * ray->dir.x * ray->dir.x + 1296.0 * tmp->x * tmp->z * ray->dir.x * ray->dir.x * ray->dir.x + 610.9402588 * tmp->z * tmp->z * ray->dir.y * ray->dir.y * ray->dir.y - 3240.0 * tmp->y * tmp->z * tmp->z * ray->dir.y * ray->dir.y * ray->dir.y - 14580.0 * tmp->y * tmp->y * tmp->y * ray->dir.y * ray->dir.y * ray->dir.y - 610.9402588 * tmp->z * tmp->z * tmp->z * ray->dir.y * ray->dir.y * ray->dir.y - 8748.0 * tmp->x * tmp->x * tmp->y * ray->dir.y * ray->dir.y * ray->dir.y + 1296.0 * tmp->y * tmp->z * ray->dir.y * ray->dir.y * ray->dir.y - 16495.386988 * tmp->x * tmp->y * tmp->z * ray->dir.y * ray->dir.y * ray->dir.y + 916.4103882 * tmp->x * tmp->y * tmp->y * ray->dir.z * ray->dir.z * ray->dir.z + 4320.0 * tmp->z * tmp->z * ray->dir.z * ray->dir.z * ray->dir.z - 305.4701294 * tmp->x * tmp->x * tmp->x * ray->dir.z * ray->dir.z * ray->dir.z - 610.9402588 * tmp->y * tmp->y * tmp->y * ray->dir.z * ray->dir.z * ray->dir.z - 4320.0 * tmp->z * tmp->z * tmp->z * ray->dir.z * ray->dir.z * ray->dir.z + 64.0 * ray->dir.z * ray->dir.z * ray->dir.z + 1832.820776 * tmp->x * tmp->x * tmp->y * ray->dir.z * ray->dir.z * ray->dir.z - 1152.0 * tmp->z * ray->dir.z * ray->dir.z * ray->dir.z + 1296.0 * tmp->x * tmp->x * tmp->z * ray->dir.z * ray->dir.z * ray->dir.z + 1296.0 * tmp->y * tmp->y * tmp->z * ray->dir.z * ray->dir.z * ray->dir.z - 1832.820776 * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.y - 3240.0 * tmp->y * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.y - 8748.0 * tmp->y * tmp->y * tmp->y * ray->dir.x * ray->dir.x * ray->dir.y + 1832.820776 * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.y - 26244.0 * tmp->x * tmp->x * tmp->y * ray->dir.x * ray->dir.x * ray->dir.y + 1296.0 * tmp->y * tmp->z * ray->dir.x * ray->dir.x * ray->dir.y - 16495.38699 * tmp->x * tmp->y * tmp->z * ray->dir.x * ray->dir.x * ray->dir.y + 1944.0 * tmp->x * tmp->x * ray->dir.x * ray->dir.x * ray->dir.z + 648.0 * tmp->y * tmp->y * ray->dir.x * ray->dir.x * ray->dir.z - 8247.693495 * tmp->x * tmp->y * tmp->y * ray->dir.x * ray->dir.x * ray->dir.z - 2749.2311646 * tmp->x * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.z + 5498.462328 * tmp->y * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.z + 13746.15582 * tmp->x * tmp->x * tmp->x * ray->dir.x * ray->dir.x * ray->dir.z + 1296.0 * tmp->z * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.z - 9720.0 * tmp->x * tmp->x * tmp->z * ray->dir.x * ray->dir.x * ray->dir.z - 3240.0 * tmp->y * tmp->y * tmp->z * ray->dir.x * ray->dir.x * ray->dir.z - 288.0 * tmp->z * ray->dir.x * ray->dir.x * ray->dir.z - 3665.641552 * tmp->y * tmp->z * ray->dir.x * ray->dir.x * ray->dir.z + 648.0 * tmp->x * tmp->x * ray->dir.y * ray->dir.y * ray->dir.z + 1944.0 * tmp->y * tmp->y * ray->dir.y * ray->dir.y * ray->dir.z - 24743.080482 * tmp->x * tmp->y * tmp->y * ray->dir.y * ray->dir.y * ray->dir.z + 2749.2311646 * tmp->x * tmp->z * tmp->z * ray->dir.y * ray->dir.y * ray->dir.z - 5498.4623292 * tmp->y * tmp->z * tmp->z * ray->dir.y * ray->dir.y * ray->dir.z - 2749.231165 * tmp->x * tmp->x * tmp->x * ray->dir.y * ray->dir.y * ray->dir.z + 1296.0 * tmp->z * tmp->z * tmp->z * ray->dir.y * ray->dir.y * ray->dir.z - 3240.0 * tmp->x * tmp->x * tmp->z * ray->dir.y * ray->dir.y * ray->dir.z - 9720.0 * tmp->y * tmp->y * tmp->z * ray->dir.y * ray->dir.y * ray->dir.z - 288.0 * tmp->z * ray->dir.y * ray->dir.y * ray->dir.z + 3665.6415528 * tmp->y * tmp->z * ray->dir.y * ray->dir.y * ray->dir.z + 10996.924656 * tmp->x * tmp->z * tmp->z * ray->dir.x * ray->dir.y * ray->dir.z + 5498.4623292 * tmp->y * tmp->z * tmp->z * ray->dir.x * ray->dir.y * ray->dir.z - 16495.386988 * tmp->y * tmp->y * tmp->y * ray->dir.x * ray->dir.y * ray->dir.z - 16495.38699 * tmp->x * tmp->x * tmp->y * ray->dir.x * ray->dir.y * ray->dir.z + 2592.0 * tmp->x * tmp->y * ray->dir.x * ray->dir.y * ray->dir.z - 7331.283104 * tmp->x * tmp->z * ray->dir.x * ray->dir.y * ray->dir.z - 12960.0 * tmp->x * tmp->y * tmp->z * ray->dir.x * ray->dir.y * ray->dir.z);
}

inline static double	calc_c_boy(t_ray *ray, t_vec3 *tmp)
{
  return (-13122.0 * tmp->x * tmp->x * ray->dir.x * ray->dir.x * ray->dir.y *
	  ray->dir.y - 13122.0 * tmp->y * tmp->y * ray->dir.x * ray->dir.x *
	  ray->dir.y * ray->dir.y - 1620.0 * tmp->z * tmp->z * ray->dir.x *
	  ray->dir.x * ray->dir.y * ray->dir.y + 648.0 * tmp->z * ray->dir.x *
	  ray->dir.x * ray->dir.y * ray->dir.y - 8247.693495 * tmp->x * tmp->z
	  * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y - 4860.0 * tmp->x
	  * tmp->x * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z - 1620.0
	  * tmp->y * tmp->y * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z
	  + 1944.0 * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.z *
	  ray->dir.z - 144.0 * ray->dir.x * ray->dir.x * ray->dir.z *
	  ray->dir.z - 1832.820776 * tmp->y * ray->dir.x * ray->dir.x *
	  ray->dir.z * ray->dir.z - 2749.2311646 * tmp->x * tmp->z * ray->dir.x
	  * ray->dir.x * ray->dir.z * ray->dir.z + 5498.462328 * tmp->y *
	  tmp->z * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z - 1620.0 *
	  tmp->x * tmp->x * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z -
	  4860.0 * tmp->y * tmp->y * ray->dir.y * ray->dir.y * ray->dir.z *
	  ray->dir.z + 1944.0 * tmp->z * tmp->z * ray->dir.y * ray->dir.y *
	  ray->dir.z * ray->dir.z - 144.0 * ray->dir.y * ray->dir.y *
	  ray->dir.z * ray->dir.z + 1832.8207764 * tmp->y * ray->dir.y *
	  ray->dir.y * ray->dir.z * ray->dir.z + 2749.2311646 * tmp->x * tmp->z
	  * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z - 5498.4623292 *
	  tmp->y * tmp->z * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z -
	  3665.641552 * tmp->x * ray->dir.x * ray->dir.y * ray->dir.z *
	  ray->dir.z - 6480.0 * tmp->x * tmp->y * ray->dir.x * ray->dir.y *
	  ray->dir.z * ray->dir.z + 10996.924656 * tmp->x * tmp->z * ray->dir.x
	  * ray->dir.y * ray->dir.z * ray->dir.z + 5498.4623292 * tmp->y *
	  tmp->z * ray->dir.x * ray->dir.y * ray->dir.z * ray->dir.z - 17496.0
	  * tmp->x * tmp->y * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y
	  - 16495.386988 * tmp->y * tmp->z * ray->dir.x * ray->dir.y *
	  ray->dir.y * ray->dir.y - 916.4103882 * tmp->x * tmp->x * ray->dir.x
	  * ray->dir.z * ray->dir.z * ray->dir.z + 916.4103882 * tmp->y *
	  tmp->y * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z +
	  3665.641552 * tmp->x * tmp->y * ray->dir.x * ray->dir.z * ray->dir.z
	  * ray->dir.z + 2592.0 * tmp->x * tmp->z * ray->dir.x * ray->dir.z *
	  ray->dir.z * ray->dir.z + 1832.820776 * tmp->x * tmp->x * ray->dir.y
	  * ray->dir.z * ray->dir.z * ray->dir.z - 1832.8207764 * tmp->y *
	  tmp->y * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z +
	  1832.8207764 * tmp->x * tmp->y * ray->dir.y * ray->dir.z * ray->dir.z
	  * ray->dir.z + 2592.0 * tmp->y * tmp->z * ray->dir.y * ray->dir.z *
	  ray->dir.z * ray->dir.z - 10935.0 * tmp->x * tmp->x * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.x - 2187.0 * tmp->y * tmp->y *
	  ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x - 810.0 * tmp->z *
	  tmp->z * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 324.0 *
	  tmp->z * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x +
	  6873.07791 * tmp->x * tmp->z * ray->dir.x * ray->dir.x * ray->dir.x *
	  ray->dir.x - 2187.0 * tmp->x * tmp->x * ray->dir.y * ray->dir.y *
	  ray->dir.y * ray->dir.y - 10935.0 * tmp->y * tmp->y * ray->dir.y *
	  ray->dir.y * ray->dir.y * ray->dir.y - 810.0 * tmp->z * tmp->z *
	  ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 324.0 * tmp->z *
	  ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y - 4123.846747 *
	  tmp->x * tmp->z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
	  + 324.0 * tmp->x * tmp->x * ray->dir.z * ray->dir.z * ray->dir.z *
	  ray->dir.z + 324.0 * tmp->y * tmp->y * ray->dir.z * ray->dir.z *
	  ray->dir.z * ray->dir.z - 3240.0 * tmp->z * tmp->z * ray->dir.z *
	  ray->dir.z * ray->dir.z * ray->dir.z - 288.0 * ray->dir.z *
	  ray->dir.z * ray->dir.z * ray->dir.z + 2160.0 * tmp->z * ray->dir.z
	  * ray->dir.z * ray->dir.z * ray->dir.z - 17496.0 * tmp->x * tmp->y
	  * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y - 5498.46233 *
	  tmp->y * tmp->z * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y
	  - 8247.693495 * tmp->x * tmp->x * ray->dir.x * ray->dir.y *
	  ray->dir.y * ray->dir.z - 24743.080482 * tmp->y * tmp->y *
	  ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z + 2749.2311646 *
	  tmp->z * tmp->z * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z
	  + 1296.0 * tmp->x * ray->dir.x * ray->dir.y * ray->dir.y *
	  ray->dir.z - 6480.0 * tmp->x * tmp->z * ray->dir.x * ray->dir.y *
	  ray->dir.y * ray->dir.z + 13746.15582 * tmp->x * tmp->x * ray->dir.x
	  * ray->dir.x * ray->dir.x * ray->dir.z - 2749.231165 * tmp->y *
	  tmp->y * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z -
	  916.4103882 * tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.x
	  * ray->dir.z + 1296.0 * tmp->x * ray->dir.x * ray->dir.x *
	  ray->dir.x * ray->dir.z - 6480.0 * tmp->x * tmp->z * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.z - 1832.8207764 * tmp->z *
	  tmp->z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z + 1296.0
	  * tmp->y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z -
	  16495.386988 * tmp->x * tmp->y * ray->dir.y * ray->dir.y *
	  ray->dir.y * ray->dir.z + 1221.8805176 * tmp->z * ray->dir.y *
	  ray->dir.y * ray->dir.y * ray->dir.z - 6480.0 * tmp->y * tmp->z *
	  ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z + 5498.462328 *
	  tmp->z * tmp->z * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.z
	  + 1296.0 * tmp->y * ray->dir.x * ray->dir.x * ray->dir.y *
	  ray->dir.z - 16495.38699 * tmp->x * tmp->y * ray->dir.x * ray->dir.x
	  * ray->dir.y * ray->dir.z - 3665.641552 * tmp->z * ray->dir.x *
	  ray->dir.x * ray->dir.y * ray->dir.z - 6480.0 * tmp->y * tmp->z *
	  ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.z);
}

inline static double	calc_b_boy(t_ray *ray, t_vec3 *tmp)
{
  return (-8748.0 * tmp->x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y
	  * ray->dir.y - 2749.231165 * tmp->z * ray->dir.x * ray->dir.x *
	  ray->dir.x * ray->dir.y * ray->dir.y - 3240.0 * tmp->x * ray->dir.x *
	  ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 2749.2311646 *
	  tmp->z * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z *
	  ray->dir.z - 3240.0 * tmp->x * ray->dir.x * ray->dir.x * ray->dir.x *
	  ray->dir.z * ray->dir.z - 916.4103882 * tmp->z * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z + 610.9402588 *
	  ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z -
	  3240.0 * tmp->y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z *
	  ray->dir.z - 1832.8207764 * tmp->z * ray->dir.y * ray->dir.y *
	  ray->dir.y * ray->dir.z * ray->dir.z - 1832.820776 * ray->dir.x *
	  ray->dir.x * ray->dir.y * ray->dir.z * ray->dir.z - 3240.0 * tmp->y *
	  ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.z * ray->dir.z +
	  5498.462328 * tmp->z * ray->dir.x * ray->dir.x * ray->dir.y *
	  ray->dir.z * ray->dir.z - 8748.0 * tmp->y * ray->dir.x * ray->dir.x *
	  ray->dir.y * ray->dir.y * ray->dir.y - 916.4103882 * tmp->x *
	  ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z +
	  1832.820776 * tmp->y * ray->dir.x * ray->dir.x * ray->dir.z *
	  ray->dir.z * ray->dir.z + 1296.0 * tmp->z * ray->dir.x * ray->dir.x *
	  ray->dir.z * ray->dir.z * ray->dir.z + 916.4103882 * tmp->x *
	  ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z -
	  1832.8207764 * tmp->y * ray->dir.y * ray->dir.y * ray->dir.z *
	  ray->dir.z * ray->dir.z + 1296.0 * tmp->z * ray->dir.y * ray->dir.y *
	  ray->dir.z * ray->dir.z * ray->dir.z + 3665.641552 * tmp->x *
	  ray->dir.x * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z +
	  1832.8207764 * tmp->y * ray->dir.x * ray->dir.y * ray->dir.z *
	  ray->dir.z * ray->dir.z - 4374.0 * tmp->x * ray->dir.x * ray->dir.y *
	  ray->dir.y * ray->dir.y * ray->dir.y - 4123.846747 * tmp->z *
	  ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y +
	  648.0 * tmp->x * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z *
	  ray->dir.z + 648.0 * tmp->y * ray->dir.y * ray->dir.z * ray->dir.z *
	  ray->dir.z * ray->dir.z - 4374.0 * tmp->x * ray->dir.x * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.x + 1374.615582 * tmp->z *
	  ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x -
	  4374.0 * tmp->y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
	  * ray->dir.y + 432.0 * ray->dir.z * ray->dir.z * ray->dir.z *
	  ray->dir.z * ray->dir.z - 1296.0 * tmp->z * ray->dir.z * ray->dir.z
	  * ray->dir.z * ray->dir.z * ray->dir.z - 4374.0 * tmp->y *
	  ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y +
	  648.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y *
	  ray->dir.z - 8247.693495 * tmp->x * ray->dir.x * ray->dir.x *
	  ray->dir.y * ray->dir.y * ray->dir.z - 3240.0 * tmp->z * ray->dir.x
	  * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z - 16495.386988
	  * tmp->y * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y *
	  ray->dir.z + 324.0 * ray->dir.x * ray->dir.x * ray->dir.x *
	  ray->dir.x * ray->dir.z + 6873.07791 * tmp->x * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z - 1620.0 * tmp->z
	  * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z +
	  324.0 * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y *
	  ray->dir.z - 4123.846747 * tmp->x * ray->dir.y * ray->dir.y *
	  ray->dir.y * ray->dir.y * ray->dir.z - 1620.0 * tmp->z * ray->dir.y
	  * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z - 5498.46233 *
	  tmp->y * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y *
	  ray->dir.z);
}

inline static double	calc_a_boy(t_ray *ray, t_vec3 *tmp)
{
  return (-2187.0 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x *
	  ray->dir.y * ray->dir.y - 1620.0 * ray->dir.x * ray->dir.x *
	  ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z - 810.0 *
	  ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z *
	  ray->dir.z - 810.0 * ray->dir.y * ray->dir.y * ray->dir.y *
	  ray->dir.y * ray->dir.z * ray->dir.z + 916.4103882 * ray->dir.x *
	  ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z -
	  305.4701294 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z *
	  ray->dir.z * ray->dir.z - 610.9402588 * ray->dir.y * ray->dir.y *
	  ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z + 1832.820776 *
	  ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.z * ray->dir.z *
	  ray->dir.z - 2187.0 * ray->dir.x * ray->dir.x * ray->dir.y *
	  ray->dir.y * ray->dir.y * ray->dir.y + 324.0 * ray->dir.x *
	  ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z +
	  324.0 * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z *
	  ray->dir.z * ray->dir.z - 729.0 * ray->dir.x * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x - 729.0 *
	  ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y *
	  ray->dir.y - 216.0 * ray->dir.z * ray->dir.z * ray->dir.z *
	  ray->dir.z * ray->dir.z * ray->dir.z - 2749.231165 * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z -
	  4123.846747 * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y *
	  ray->dir.y * ray->dir.z + 1374.615582 * ray->dir.x * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z);
}
#pragma message("Wtf les malloc failed ??")
t_intersect		get_intersect_boy(t_obj *obj, t_ray *ray)
{
  t_intersect		inter;
  double		coef[7];
  t_vec3		tmp;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  tmp = sub_vec3(ray->pos, obj->pos);
  coef[0] = calc_a_boy(ray, &tmp);
  coef[1] = calc_b_boy(ray, &tmp);
  coef[2] = calc_c_boy(ray, &tmp);
  coef[3] = calc_d_boy(ray, &tmp);
  coef[4] = calc_e_boy(ray, &tmp);
  coef[5] = calc_f_boy(ray, &tmp);
  coef[6] = calc_g_boy(ray, &tmp);
  if ((inter.dist = solver_n_degree(coef, 6)) <= 0.0 ||
      inter.dist == NOT_A_SOLUTION)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(ray->pos, mult_vec3(ray->dir, inter.dist));
  return (inter);
}