/*
** load_scene.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun Apr 17 19:17:30 2016 Ludovic Petrenko
** Last update Tue Apr 19 22:20:53 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/str.h"

t_scene		*load_scene(const char *file)
{
  t_scene	*scene;
  t_bunny_ini	*ini;

  if (!(ini = bunny_load_ini(file)))
    {
    return (NULL);
    }
  if (!(scene = my_malloc(sizeof(t_scene))))
    {
      bunny_delete_ini(ini);
      return (NULL);
    }
  load_scene_info(scene, ini);
  load_camera(&scene->cam, ini);
  if (load_materials(scene, ini) ||
      load_scene_elements(scene, ini))
    {
      bunny_delete_ini(ini);
      my_free(scene);
      return (NULL);
    }
  return (scene);
}

void	load_scene_info(t_scene *s, const t_bunny_ini *ini)
{
  char	*tmp;

  s->spec.bg_color = DEFAULT_BG_COLOR;
  if ((tmp = (char *)bunny_ini_get_field(ini, "scene", "bg_color", 0)))
    s->spec.bg_color = my_gethexa(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "scene", "ambiant", 0)))
    s->spec.ambiant = my_getdouble(tmp);
}

void	load_camera(t_camera *c, const t_bunny_ini *ini)
{
  char	*tmp;

  c->pos = DEFAULT_CAM_POS;
  c->dir = DEFAULT_CAM_DIR;
  c->focale = DEFAULT_CAM_FOCALE;
  c->fov = DEFAULT_CAM_FOV;
  if ((tmp = (char *)bunny_ini_get_field(ini, "camera", "position", 0)))
    c->pos.x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "camera", "position", 1)))
    c->pos.y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "camera", "position", 2)))
    c->pos.z = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "camera", "direction", 0)))
    c->dir.x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "camera", "direction", 1)))
    c->dir.y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "camera", "direction", 2)))
    c->dir.z = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "camera", "focale", 0)))
    c->focale = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, "camera", "fov", 0)))
    c->fov = my_getdouble(tmp);
}

int	load_materials(t_scene *s, const t_bunny_ini *ini)
{
  s->nb_mat = ini_count_prefix(ini, "mat_");
  if (!(s->mat = my_calloc(s->nb_mat, sizeof(t_material))))
    return (1);
  if (load_mat(s->mat, ini))
    {
      my_free(s->mat);
      return (1);
    }
  return (0);
}

int	load_scene_elements(t_scene *s, const t_bunny_ini *ini)
{
  s->nb_light = ini_count_prefix(ini, "light_");
  s->nb_obj = ini_count_prefix(ini, "obj_");
  if (!(s->objs = my_calloc(s->nb_obj + s->nb_light, sizeof(t_obj))))
    return (1);
  if (!(s->lights = my_calloc(s->nb_light, sizeof(t_obj))))
    {
      my_free(s->objs);
      return (1);
    }
  load_objs(s, s->objs, ini);
  return (0);
}