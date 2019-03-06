# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 00:53:31 by mmousson          #+#    #+#              #
#    Updated: 2019/02/20 02:11:29 by mmousson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
HEADER = libft.h
LOGFOLDER = ~/libft_logs
CFLAGS = -Wall -Wextra -Werror -I./includes

SRC =	ft_memset.c				\
		ft_bzero.c				\
		ft_memcpy.c				\
		ft_memccpy.c			\
		ft_strlen.c				\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memmove.c			\
		ft_strdup.c				\
		ft_strcpy.c				\
		ft_strncpy.c			\
		ft_strcat.c				\
		ft_strncat.c			\
		ft_strlcat.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strstr.c				\
		ft_strrstr.c			\
		ft_strnstr.c			\
		ft_strcmp.c				\
		ft_strncmp.c			\
		ft_atoi.c				\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isxdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_putchar.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_putstr.c				\
		ft_putendl.c			\
		ft_putnbr.c				\
		ft_memalloc.c			\
		ft_memdel.c				\
		ft_strnew.c				\
		ft_strdel.c				\
		ft_strclr.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strmap.c				\
		ft_strmapi.c			\
		ft_strequ.c				\
		ft_strnequ.c			\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_strsplit.c			\
		ft_itoa.c				\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_lstnew.c				\
		ft_lstdelone.c			\
		ft_lstdel.c				\
		ft_lstadd.c				\
		ft_lstiter.c			\
		ft_lstmap.c				\
		ft_lstpush.c			\
		ft_rotate_left.c		\
		ft_stradd.c				\
		ft_strmultiply.c		\
		ft_putllong.c			\
		ft_putfloat.c			\
		ft_min.c				\
		ft_dmin.c				\
		ft_max.c				\
		ft_dmax.c				\
		ft_abs.c				\
		ft_clamp.c				\
		ft_strdivide_two.c		\
		ft_strendswith.c		\
		ft_fabs.c				\
		get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

log_check:
	@rm -rf $(LOGFOLDER)
	@/bin/mkdir $(LOGFOLDER)

%.o: %.c | log_check
	@if [ ! -e libft_link ]; then \
		/bin/echo ""; \
		/bin/echo -n "COMPILING LIBFT STATIC LIBRARY... "; \
	fi;
	@/usr/bin/touch libft_link
	@$(CC) -c $< $(CFLAGS) -o $@ 2> $(LOGFOLDER)/tmp.log || /usr/bin/touch $(LOGFOLDER)/tmp.errors
	@if test -e $(LOGFOLDER)/tmp.errors; then /bin/cat $(LOGFOLDER)/tmp.log; elif test -s$(LOGFOLDER)/tmp.log; then /bin/cat $(LOGFOLDER)/tmp.log; fi;
	@rm -f $(LOGFOLDER)/tmp.log && rm -f $(LOGFOLDER)/tmp.errors

$(NAME): $(OBJ)
	@if [ -e libft_link ]; then \
		ar rc $(NAME) $(OBJ); \
		ranlib $(NAME); \
		echo "	 \x1b[1;32m[LIBFT READY]\x1b[0m\n"; \
	fi;
	@rm -f libft_link

clean:
	@rm -f $(OBJ)
	@echo "\x1b[1;33m[LIBFT CLEANED]\x1b[0m"

fclean:
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@echo "\x1b[1;33m[LIBFT CLEANED]\x1b[0m"
	@echo "\x1b[1;35m[LIBFT LIBRARY DELETED]\x1b[0m"

re: fclean all

.PHONY: all clean fclean re log_check
