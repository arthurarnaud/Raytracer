/*
** raytracer.h for Raytracer2 in /raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Apr 14 12:39:45 2016 Antoine Baché
** Last update Sun Apr 24 19:50:49 2016 Arthur ARNAUD
*/

#ifndef	RAYTRACER2_H_
# define RAYTRACER2_H_

# include <lapin.h>
# include <stdbool.h>
# include "engine/scene.h"
# include "config.h"
# include "events.h"
# include "tools/memory.h"
# include "ply.h"

# define DEFAULT_WIDTH		1280
# define DEFAULT_HEIGHT		720
# define WIN_NAME		"Ray Ta Soeur"
# define UNUSED			__attribute__((unused))

/*
** Scopes expected in .ini files
*/
# define SCOPE_NETWORK		"network"
# define PORT_NETWORK		"port"
# define CLIENT_NETWORK		"max_client"
# define RADIUS_FIELD		"radius"
# define NORMALE_FIELD		"normale"
# define HEIGHT_FIELD		"height"
# define COLOR_FIELD		"color"
# define POWER_FIELD		"power"
# define DIR_FIELD		"direction"
# define ANGLE_FIELD		"angle"
# define OPACITY_FIELD		"opacity"
# define REFLECT_FIELD		"reflectivity"
# define FRESNEL_FIELD		"fresnel"
# define POS_FIELD		"position"
# define ROT_FIELD		"rotation"
# define MAT_FIELD		"material"
# define CAM_FIELD		"camera"
# define FOV_FIELD		"fov"
# define FOCALE_FIELD		"focale"
# define SCENE_FIELD		"scene"
# define BACK_FIELD		"bg_color"
# define AMB_FIELD		"ambiant"
# define MAT_PREFIX		"mat_"
# define OBJ_PREFIX		"obj_"
# define LIGHT_PREFIX		"light_"

/*
** Default configuration
*/
# define SCENE_DEFAULT		"scenes/default.ini"
# define MAX_CLIENT_DEFAULT	"42"

/*
** Error messages
*/
# define MISSING_PORT_ERROR    	"Missing port in config.ini\n"
# define INVALID_PORT_ERROR	"Invalid port in config.ini\n"
# define CHOOSE_PORT_ERROR     	"Choose a port between 0 and 65535\n"
# define MAX_CLIENT_ERROR    	"Invalid max_client in config.ini\n"
# define NEW_CLIENT_ERROR	"Error: Cannot accept new client\n"
# define MAX_CLIENT_REACHED	"Max number of client reached\n"
# define INIT_SERVER_ERROR	"Error: Cannot start server\n"
# define SOCKET_ERROR		"Error: Cannot create scoket\n"
# define LISTEN_ERROR		"Error: Cannot listen\n"
# define CREATE_THREAD_ERROR	"Error: Cannot create the TCP thread\n"
# define THREAD_ERROR		"Error: In TCP thread\n"

/*
** Dhiver messages
*/
# define NEW_CLIENT		"New client added\n"
# define NEW_CLIENT_CONNECTED	"Infos: New client connected\n"
# define WAIT_CLIENT		"Waiting for clients...\n"

typedef struct		s_network
{
  int			fd;
  int			port;
  int			max_client;
  int			*clients;
  bool			run;
  bool			all_connected;
}			t_network;

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*render;
  int			width;
  int			height;
  bool			fullscreen;
  t_scene		*scene;
  t_config		config;
  t_network		network;
}			t_data;

int			init_data(int ac, char **av, t_data **data);
int			launch_raytracer(t_data *data);
t_bunny_response	main_events(UNUSED t_bunny_event_state s,
				    UNUSED t_bunny_keysym k,
				    t_data *data);
t_bunny_response	main_loop(t_data *data);
int			set_frame(t_data *data);

#endif /* RAYTRACER2_H_ */
