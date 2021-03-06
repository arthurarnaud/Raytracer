/*
** load_scene.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun Apr 17 19:17:30 2016 Ludovic Petrenko
** Last update Sun May 22 22:47:09 2016 Antoine Baché
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/str.h"

t_scene		*load_scene(const char *file, t_data *data)
{
  t_scene	*scene;
  t_bunny_ini	*ini;

  if (!(ini = bunny_load_ini(file)))
    return (NULL);
  if (!(scene = my_calloc(1, sizeof(t_scene))) ||
      !(scene->zbuf = my_calloc(data->config.width * data->config.height,
				sizeof(double))) ||
      !(scene->cache = bunny_new_pixelarray(data->config.width,
					    data->config.height + 1)))
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
  bunny_delete_ini(ini);
  return (scene);
}

void	load_scene_info(t_scene *s, const t_bunny_ini *ini)
{
  char	*tmp;

  s->spec.bg_color.full = DEFAULT_BG_COLOR;
  if ((tmp = (char *)bunny_ini_get_field(ini, SCENE_FIELD, BACK_FIELD, 0)))
    s->spec.bg_color.full = my_gethexa(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, SCENE_FIELD, AMB_FIELD, 0)))
    s->spec.ambiant = my_getdouble(tmp);
  s->select = NULL;
  s->spec.skybox = NULL;
  if ((tmp = (char *)bunny_ini_get_field(ini, SCENE_FIELD, SKYBOX_FIELD, 0)))
    s->spec.skybox = bunny_load_pixelarray(tmp);
}

void	load_camera(t_camera *c, const t_bunny_ini *ini)
{
  char	*tmp;

  c->pos = DEFAULT_CAM_POS;
  c->dir = DEFAULT_CAM_DIR;
  c->focale = DEFAULT_CAM_FOCALE;
  c->fov = DEFAULT_CAM_FOV;
  if ((tmp = (char *)bunny_ini_get_field(ini, CAM_FIELD, POS_FIELD, 0)))
    c->pos.x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, CAM_FIELD, POS_FIELD, 1)))
    c->pos.y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, CAM_FIELD, POS_FIELD, 2)))
    c->pos.z = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, CAM_FIELD, DIR_FIELD, 0)))
    c->dir.x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, CAM_FIELD, DIR_FIELD, 1)))
    c->dir.y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, CAM_FIELD, DIR_FIELD, 2)))
    c->dir.z = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, CAM_FIELD, FOCALE_FIELD, 0)))
    c->focale = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, CAM_FIELD, FOV_FIELD, 0)))
    c->fov = my_getdouble(tmp);
}

int	load_materials(t_scene *s, const t_bunny_ini *ini)
{
  s->nb_mat = ini_count_prefix(ini, MAT_PREFIX);
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
  s->nb_light = ini_count_prefix(ini, LIGHT_PREFIX);
  s->nb_obj = ini_count_prefix(ini, OBJ_PREFIX);
  if (!(s->objs = my_calloc(s->nb_obj + s->nb_light, sizeof(t_obj))))
    return (1);
  if (!(s->lights = my_calloc(s->nb_light, sizeof(t_obj))))
    {
      my_free(s->objs);
      return (1);
    }
  return (load_objs(s, s->objs, ini));
}
