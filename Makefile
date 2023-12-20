NAME 	= so_long
NAME_BONUS = so_long_bonus
CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

SRCS = ./utls/check_elements.c ./utls/check_file_is_valide.c ./utls/ft_put_str.c \
       ./utls/check_map.c ./utls/check_path.c ./utls/ft_display_movement.c       \
       ./utls/ft_put_image.c ./utls/ft_exit.c ./utls/ft_itoa.c  ./utls/ft_load_image.c \
       ./utls/ft_movement.c ./utls/ft_put_floor_player.c ./utls/ft_split.c \
       ./utls/get_map.c so_long.c ./get_next_line_d/get_next_line.c ./get_next_line_d/get_next_line_utils.c

SRCS_BONUS = ./utls_bonus/check_elements.c ./utls_bonus/check_file_is_valide.c ./utls_bonus/ft_put_str.c \
             ./utls_bonus/check_map.c ./utls_bonus/check_path.c ./utls_bonus/ft_display_movement_bonus.c \
             ./utls_bonus/ft_put_image.c ./utls_bonus/ft_exit.c ./utls_bonus/ft_itoa.c \
             ./utls_bonus/ft_movement.c ./utls_bonus/ft_put_floor_player.c ./utls_bonus/ft_split.c \
             ./utls_bonus/get_map.c ./utls_bonus/ft_animation_bonus.c ./utls/ft_load_image.c \
             ./utls_bonus/ft_animation_utils_bonus.c so_long_bonus.c ./get_next_line_d/get_next_line.c ./get_next_line_d/get_next_line_utils.c 

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $^ -o $@

	@echo "\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "                                \033[44mBy: zelabbas\033[0m"

$(NAME_BONUS) : $(OBJS_BONUS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $^ -o $@

	@echo "\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "                                \033[44mBy: zelabbas\033[0m"

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

bonus: $(NAME_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all