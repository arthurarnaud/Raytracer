/*
** init_data.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 22:32:39 2016 Ludovic Petrenko
** Last update Sun May 22 16:31:58 2016 Antoine Baché
*/

#include "raytracer.h"
#include "threadpool.h"
#include "loader.h"
#include "tools/math.h"

static void	set_fields(t_data *data)
{
  start_threadpool();
  data->config.width = DEFAULT_WIDTH;
  data->config.height = DEFAULT_HEIGHT;
  data->config.fullscreen = false;
  data->config.minimum_fps = DEFAULT_FPS;
  data->effect = NO_EFFECT;
  data->joy.lon = 0;
  data->joy.lat = 0;
  data->joy.hor = 0;
  data->joy.ver = 0;
  my_sin(0.0, DRAW);
  my_cos(0.0, DRAW);
}

int	init_data(int ac, char **av, t_data **data)
{
  bunny_set_maximum_ram(2 * 1000 * 1000 * 1000);
  bunny_set_memory_check(true);
  if (!(*data = my_calloc(1, sizeof(t_data))))
    return (1);
  set_fields(*data);
  if ((*data)->config.width <= 0 || (*data)->config.height <= 0 ||
      !((*data)->win = bunny_start((*data)->config.width,
				   (*data)->config.height,
				   (*data)->config.fullscreen, WIN_NAME)) ||
      !((*data)->render = bunny_new_pixelarray((*data)->config.width,
					       (*data)->config.height)))
    return (1);
  if (ac == 2)
    {
      if (!((*data)->scene = load_scene(av[1], *data)))
	return (1);
    }
  else if (!((*data)->scene = load_scene(SCENE_DEFAULT, *data)))
    return (1);
  if (!((*data)->scene->cache =
	bunny_new_pixelarray((*data)->config.width, (*data)->config.height)) ||
      load_config(*data, CONFIG_FILE))
    return (1);
  return (0);
}
