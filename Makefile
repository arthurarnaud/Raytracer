##
## Makefile for Raytracer2 in /raytracer2
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Thu Apr 14 12:22:26 2016 Antoine Baché
## Last update Thu May 26 20:59:03 2016 Antoine Baché
##

DEBUG=			no

SRC_PREFIX=		src/

SRC_FILES=		init_data.c			\
			joystick.c			\
			calc_fragment.c			\
			calc_ray.c			\
			camera.c			\
			free.c				\
			launch.c			\
			main.c				\
			node_intersect.c		\
			node_intersect2.c		\
			set_frame.c			\
			vector.c			\
			vector_add.c			\
			vector_tools.c			\
			vector_op.c			\
			obj_vector.c			\
			obj_vector_op.c			\
			move_ray.c			\
			get_light.c			\
			focale.c			\
			check_box.c			\
			build_bsp.c			\
			scene_intersect.c		\
			get_tex_pix.c			\
			delete_object.c			\
			skybox.c			\
			events.c

EFFECT_PREFIX=		src/effect/

EFFECT_FILES=		effect.c			\
			black_and_white.c		\
			pastel.c			\
			stained_glass.c			\
			negative.c			\
			bayer.c				\
			sepia.c				\
			eight_bit.c			\
			solarized.c			\
			rotate.c			\
			contrast.c			\
			blit_scaled_blur.c		\
			antialiasing.c

NOISE_PREFIX=		src/noise/

NOISE_FILES=		perlin.c			\
			perlin_calc_color.c		\
			perlin_calc_init.c		\
			perlin_calc_pixel.c		\
			perlin_calc_smooth.c		\
			perlin_calc_smooth_values.c	\
			perlin_gradient.c		\
			perlin_tables.c			\
			perlin_tables_4d.c		\
			perlin_tables_4d_next.c		\
			permutation_table.c		\
			simplex.c			\
			simplex_calc_det.c		\
			simplex_calc_grad.c		\
			simplex_calc_init.c		\
			simplex_calc_offset.c		\
			simplex_calc_offset_next.c	\
			simplex_calc_pixel.c		\
			simplex_calc_table.c		\
			simplex_mask.c

LOADER_PREFIX=		src/loader/

LOADER_FILES=		count.c				\
			get_material.c			\
			load_config.c			\
			load_effect.c			\
			load_light_type.c		\
			load_mat.c			\
			load_obj.c			\
			load_obj_type.c			\
			load_obj_type_more.c		\
			load_obj_part_two.c		\
			load_obj_part_three.c		\
			load_obj_part_four.c		\
			load_obj_part_five.c		\
			load_obj_part_six.c		\
			load_obj_part_seven.c		\
			load_polygons.c			\
			load_scene.c			\
			obj_type.c

SOLVER_PREFIX=		src/solver/

SOLVER_FILES=		second_degree.c			\
			third_degree.c			\
			fourth_degree.c			\
			fourth_degree_extended.c	\
			n_degree_solve.c		\
			n_degree_solvers.c		\
			check_solution.c

SHAPE_PREFIX=		src/shape/

SHAPE_FILES=		plane.c				\
			cylinder.c			\
			sphere.c			\
			tore.c				\
			triangle.c			\
			cone.c				\
			mobius.c			\
			void_cube.c			\
			klein.c				\
			klein_coefs.c			\
			klein_coef_more.c		\
			klein_normale.c			\
			hyperbola.c			\
			ellipsoid.c			\
			ply.c				\
			cassini.c			\
			chair.c				\
			kusner.c			\
			tritrumpet.c			\
			whitney.c			\
			tetrahedral.c			\
			barth_sextic.c			\
			bifolia.c			\
			duplin.c			\
			cushion.c			\
			tooth.c				\
			heart.c				\
			hunt.c				\
			miter.c				\
			kiss.c				\
			bohemian_dome.c			\
			bohemian_star.c			\
			c8.c				\
			chubs.c				\
			devil.c				\
			quartic_cylinder.c		\
			light.c				\
			no_shape.c			\
			bohemian_dome_normale.c		\
			bohemian_star_normale.c		\
			c8_normale.c			\
			cassini_normale.c		\
			chair_normale.c			\
			chubs_normale.c			\
			cushion_normale.c		\
			devil_normale.c			\
			heart_normale.c			\
			hunt_normale.c			\
			barth_sextic_normale.c		\
			normale_generic.c

THREADPOOL_PREFIX=	src/threadpool/

THREADPOOL_FILES=	init.c				\
			pool.c				\
			queue.c				\
			task.c				\
			raytracer.c			\
			loop.c

TOOLS_PREFIX=		src/tools/

TOOLS_FILES=		memory.c			\
			my_bzero.c			\
			my_memset.c			\
			my_strlen.c			\
			my_getnbr.c			\
			my_getdouble.c			\
			my_strcmp.c			\
			my_strncmp.c			\
			my_gethexa.c			\
			my_puterr.c			\
			my_strndup.c			\
			str_to_wordtab.c		\
			get_next_line.c			\
			blit_scaled.c			\
			swap_double.c			\
			trigo.c				\
			pixelarray.c			\
			bmp.c

PLY_PREFIX=		src/ply/

PLY_FILES=		add_element.c			\
			check_var.c			\
			get_ply.c			\
			init.c				\
			fill_ply.c			\
			parse_prop.c			\
			free_ply.c			\
			read_header.c			\
			resize.c			\
			build_obj.c			\
			set_box.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

SRC_EFFECT=		$(addprefix $(EFFECT_PREFIX),$(EFFECT_FILES))

SRC_NOISE=		$(addprefix $(NOISE_PREFIX),$(NOISE_FILES))

SRC_LOADER=		$(addprefix $(LOADER_PREFIX),$(LOADER_FILES))

SRC_SHAPE=		$(addprefix $(SHAPE_PREFIX),$(SHAPE_FILES))

SRC_SOLVER=		$(addprefix $(SOLVER_PREFIX),$(SOLVER_FILES))

SRC_THREADPOOL=		$(addprefix $(THREADPOOL_PREFIX),$(THREADPOOL_FILES))

SRC_TOOLS=		$(addprefix $(TOOLS_PREFIX),$(TOOLS_FILES))

SRC_PLY=		$(addprefix $(PLY_PREFIX),$(PLY_FILES))

SRC+=			$(SRC_EFFECT)

SRC+=			$(SRC_NOISE)

SRC+=			$(SRC_THREADPOOL)

SRC+=			$(SRC_TOOLS)

SRC+=			$(SRC_LOADER)

SRC+=			$(SRC_PLY)

SRC+=			$(SRC_SHAPE)

SRC+=			$(SRC_SOLVER)

NAME=			raytracer2

HEAD=			-Iinclude			\
			-I/home/${USER}/.froot/include

LIB=			-L/usr/local/lib		\
			-L/home/${USER}/.froot/lib	\
			-llapin 			\
			-lsfml-audio 			\
			-lsfml-graphics 		\
			-lsfml-window 			\
			-lsfml-system 			\
			-lstdc++ 			\
			-ldl 				\
			-lpthread			\
			-lm

CFLAGS=			$(HEAD) -W -Wall -Wextra

ifeq ($(DEBUG), yes)
	CFLAGS+=	 -g -D DEBUG
	LIB+=		-rdynamic
else
	CFLAGS+=	-Werror
endif

CC=			gcc

RM=			rm -f

OBJ=			$(SRC:.c=.o)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIB)
	@echo -ne '\e[1m\e[32m[ OK ] \e[0m'
	@echo "Compiled Raytracer2"

%.o:	%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -ne '\e[1m\e[32m[ OK ] \e[0m'
	@echo "Compiling" $<

all:	$(NAME) infos

infos:
ifeq ($(DEBUG), yes)
	@echo -e '\n [0;1;31;91mm[0;1;33;93mmm[0;1;32;92mm[0m   [0;1;34;94mmm[0;1;35;95mmm[0;1;31;91mmm[0m [0;1;33;93mm[0;1;32;92mmm[0;1;36;96mmm[0m  [0;1;35;95mm[0m    [0;1;33;93mm[0m   [0;1;36;96mm[0;1;34;94mmm[0m         [0;1;36;96mm[0m    [0;1;31;91mm[0m  [0;1;33;93mm[0;1;32;92mmm[0;1;36;96mm[0m  [0;1;34;94mm[0;1;35;95mmm[0;1;31;91mm[0m   [0;1;32;92mmm[0;1;36;96mmm[0;1;34;94mmm[0m\n [0;1;33;93m#[0m   [0;1;36;96m"[0;1;34;94mm[0m [0;1;35;95m#[0m      [0;1;32;92m#[0m    [0;1;35;95m#[0m [0;1;31;91m#[0m    [0;1;32;92m#[0m [0;1;36;96mm[0;1;34;94m"[0m   [0;1;31;91m"[0m        [0;1;34;94m#[0;1;35;95m#[0m  [0;1;31;91m#[0;1;33;93m#[0m [0;1;32;92mm"[0m  [0;1;34;94m"m[0m [0;1;35;95m#[0m   [0;1;33;93m"[0;1;32;92mm[0m [0;1;36;96m#[0m\n [0;1;32;92m#[0m    [0;1;35;95m#[0m [0;1;31;91m#m[0;1;33;93mmm[0;1;32;92mmm[0m [0;1;36;96m#[0;1;34;94mmm[0;1;35;95mmm[0;1;31;91m"[0m [0;1;33;93m#[0m    [0;1;36;96m#[0m [0;1;34;94m#[0m   [0;1;31;91mm[0;1;33;93mm[0m        [0;1;35;95m#[0m [0;1;31;91m#[0;1;33;93m#[0m [0;1;32;92m#[0m [0;1;36;96m#[0m    [0;1;35;95m#[0m [0;1;31;91m#[0m    [0;1;36;96m#[0m [0;1;34;94m#m[0;1;35;95mmm[0;1;31;91mmm[0m\n [0;1;36;96m#[0m    [0;1;31;91m#[0m [0;1;33;93m#[0m      [0;1;34;94m#[0m    [0;1;33;93m#[0m [0;1;32;92m#[0m    [0;1;34;94m#[0m [0;1;35;95m#[0m    [0;1;32;92m#[0m        [0;1;31;91m#[0m [0;1;33;93m"[0;1;32;92m"[0m [0;1;36;96m#[0m [0;1;34;94m#[0m    [0;1;31;91m#[0m [0;1;33;93m#[0m    [0;1;34;94m#[0m [0;1;35;95m#[0m\n [0;1;34;94m#[0;1;35;95mmm[0;1;31;91mm"[0m  [0;1;32;92m#m[0;1;36;96mmm[0;1;34;94mmm[0m [0;1;35;95m#[0;1;31;91mmm[0;1;33;93mmm[0;1;32;92m"[0m [0;1;36;96m"m[0;1;34;94mmm[0;1;35;95mm"[0m  [0;1;33;93m"m[0;1;32;92mmm[0;1;36;96m"[0m        [0;1;33;93m#[0m    [0;1;34;94m#[0m  [0;1;35;95m#[0;1;31;91mmm[0;1;33;93m#[0m  [0;1;32;92m#[0;1;36;96mmm[0;1;34;94mm"[0m  [0;1;31;91m#m[0;1;33;93mmm[0;1;32;92mmm[0m\n'
endif
	@echo -ne '\e[1m\e[36mCompilation line: \e[0m'
	@echo $(CC) -o file.o -c file.c $(CFLAGS)
	@echo -ne '\e[1m\e[36mLinking: \e[0m'
	@echo $(CC) files.o ... -o $(NAME) $(LIB)


clean:
	@$(RM) $(OBJ)
	@echo -ne '\e[1m\e[31m[ RM ] \e[0m'
	@echo "Removing OBJ files ..."

fclean:	clean
	@$(RM) $(NAME)
	@echo -ne '\e[1m\e[31m[ RM ] \e[0m'
	@echo "Removing binaries ..."

re:	fclean all

.PHONY:	all clean fclean re
