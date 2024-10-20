CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJS_OG = $(SRCS:.c=.o) 
SRCS = ft_atoi.c \
		ft_strtod.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_count_char.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_is_char_in_set.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strncmp.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memchr.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_strnstr.c \
		ft_memmove.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_split_s.c \
		ft_reverse_str.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strtrim.c \
		basic.c \
		format1.c \
		format2.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_print_str_set.c \
		print.c \
		free_split.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstfind.c
NAME = libft.a

$(NAME): all

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

fclean: clean
	@rm -f $(NAME)

all: $(OBJS_OG)
	@rm -f $(NAME)
	@ar -rcs $(NAME) $(OBJS_OG)
	@touch $@

clean:
	@rm -f $(OBJS_OG) $(OBJS_BONUS) mandatory bonus all

re: fclean all

.PHONY: all clean fclean re