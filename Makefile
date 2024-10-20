CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
OBJS_MAND = $(addprefix objs/, $(notdir $(SRCS_MAND:.c=.o)))
OBJS_BONUS = $(addprefix objs/, $(notdir $(SRCS_BONUS:.c=.o)))
OBJ_DIR = objs
LIBFT = libft/libft.a
LIBMLX = mlx/libmlx.a
NAME = miniRT
SRCS_MAND = vec1.c \
	vec2.c \
	mat1.c mat2.c \
	ray.c \
	parse.c \
	vec_utils.c \
	mat_utils.c \
	mlx_utils1.c \
	mlx_utils2.c \
	append_object1.c append_object2.c \
	camera_set.c \
	hittable1.c \
	hittable2.c \
	hittable_cy.c \
	check_hittable.c \
	shoot_ray.c \
	view.c \
	utils.c \
	main.c
SRCS_BONUS = vec1_bonus.c \
	vec2_bonus.c \
	mat1_bonus.c mat2_bonus.c \
	ray_bonus.c \
	parse_bonus.c \
	vec_utils_bonus.c \
	light_utils_bonus.c \
	mat_utils_bonus.c \
	mlx_utils1_bonus.c \
	mlx_utils2_bonus.c \
	mlx_utils3_bonus.c \
	mlx_texture_utils_bonus.c \
	append_object1_bonus.c \
	append_object2_bonus.c \
	camera_set_bonus.c \
	hittable1_bonus.c \
	hittable2_bonus.c \
	hittable_cy_bonus.c \
	check_hittable_bonus.c \
	shoot_ray_bonus.c \
	view_bonus.c \
	utils_bonus.c \
	texture_bonus.c \
	find_normalized_point_bonus.c \
	main_bonus.c

vpath %.c srcs
vpath %.h includes

all: $(NAME)

$(NAME): $(OBJ_DIR) mandatory

$(OBJ_DIR):
	@mkdir objs

mandatory: $(OBJS_MAND) $(LIBFT) $(LIBMLX)
	rm -f mandatory bonus $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_MAND) $(LIBFT) $(LIBMLX) -framework Opengl -framework Appkit
	touch $@
	$(info ███╗   ███╗██╗███╗   ██╗██╗██████╗ ████████╗)
	$(info ████╗ ████║██║████╗  ██║██║██╔══██╗╚══██╔══╝)
	$(info ██╔████╔██║██║██╔██╗ ██║██║██████╔╝   ██║   )
	$(info ██║╚██╔╝██║██║██║╚██╗██║██║██╔══██╗   ██║   )
	$(info ██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║   ██║   )
	$(info ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝   ╚═╝   by hyungjuk and yeonwkan)

bonus: $(OBJ_DIR) $(OBJS_BONUS) $(LIBFT) $(LIBMLX)
	@rm -f mandatory bonus $(NAME)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBFT) $(LIBMLX) -framework Opengl -framework Appkit
	$(info ███╗   ███╗██╗███╗   ██╗██╗██████╗ ████████╗ bonus!)
	$(info ████╗ ████║██║████╗  ██║██║██╔══██╗╚══██╔══╝)
	$(info ██╔████╔██║██║██╔██╗ ██║██║██████╔╝   ██║   )
	$(info ██║╚██╔╝██║██║██║╚██╗██║██║██╔══██╗   ██║   )
	$(info ██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║   ██║   )
	$(info ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝   ╚═╝   by hyungjuk and yeonwkan)
	@touch $@

libft/libft.a:
	@make -C libft

mlx/libmlx.a:
	@make -C mlx

$(OBJ_DIR)/%.o: mandatory/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR)/%.o: bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJS_MAND)
	@rm -f $(OBJS_BONUS)
	@rm -f mandatory bonus
	@make -C libft fclean
	@make -C mlx clean
	@rm -rf $(OBJ_DIR)

re: fclean
	make all

rebonus: fclean
	make bonus

.PHONY: all clean fclean re rebonus
