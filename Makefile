# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 15:53:24 by mmousson          #+#    #+#              #
#    Updated: 2019/02/21 14:05:16 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang
LOGFOLDER = ~/fractol_logfolder
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft/includes -I/usr/local/include

LIBFT = ./libft/libft.a
LIBMLX = /usr/local/lib/libmlx.a

SRCS =	./src/core/main.c						\
		./src/core/select_set_function.c		\
		./src/core/initiate_image.c				\
		./src/pixels/put_pixel_to_image.c		\
		./src/pixels/clerp.c					\
		./src/burningship/burningship_main.c	\
		./src/julia/julia_main.c				\
		./src/mandelbrot/mandelbrot_main.c		\
		./src/key_handler/key_manager.c			\
		./src/key_handler/escape_handler.c

OBJS = $(SRCS:.c=.o)

OBJ_ROOT = _OBJ
MOVED_OBJ = $(subst .c,.o,$(subst ./src/,./_OBJ/,$(SRCS)))
OBJ_DIRS = $(dir $(MOVED_OBJ))
CHARACTERS := a b c d e f g h i j k l m n o p q r s t u v w x y z _
strlen = $(strip $(eval __temp := $(subst $(sp),x,$1))$(foreach a,$(CHARACTERS),$(eval __temp := $$(subst $a,x,$(__temp))))$(eval __temp := $(subst x,x ,$(__temp)))$(words $(__temp)))

all: $(NAME)

log_check:
	@$(MAKE) --no-print-directory -C libft
	@/bin/rm -rf $(LOGFOLDER)
	@/bin/mkdir $(LOGFOLDER)
	@if ! test -e $(OBJ_ROOT); then mkdir $(OBJ_ROOT); fi;
	@for dir in $(OBJ_DIRS); do \
		if ! test -e $$dir; then mkdir $$dir; fi; \
	done;

$(OBJ_ROOT)/%.o: src/%.c | log_check
	@/usr/bin/touch $(LOGFOLDER)/relink
	@/bin/echo -n "Precompiling $(notdir $@)..."
	@$(CC) -c $< $(CFLAGS) -o $@ 2> $(LOGFOLDER)/tmp.log || /usr/bin/touch $(LOGFOLDER)/tmp.errors
	@if [ $(call strlen,($(notdir $@))) -lt "16" ]; then /bin/echo  -n "	"; fi;
	@if [ $(call strlen,($(notdir $@))) -lt "8" ]; then /bin/echo  -n "	"; fi;
	@if test -e $(LOGFOLDER)/tmp.errors; \
		then echo "	 \x1b[1;31m[KO]\x1b[0m" && /bin/cat 1>&2 $(LOGFOLDER)/tmp.log && touch files_missing; \
	elif test -s $(LOGFOLDER)/tmp.log; then \
		echo "	 \x1b[1;33m[WARNING]\x1b[0m" && /bin/cat $(LOGFOLDER)/tmp.log; \
	else \
		echo "	 \x1b[1;32m[OK]\x1b[0m"; fi;
	@/bin/rm -f $(LOGFOLDER)/tmp.log && rm -f $(LOGFOLDER)/tmp.errors


$(NAME): $(MOVED_OBJ) $(HEADERS)
	@/bin/rm -rf ~/$(NAME)_logs
	@/bin/mkdir ~/$(NAME)_logs
	@if [ ! -e files_missing ] && [ -e $(LOGFOLDER)/relink ]; then \
		$(CC) $(MOVED_OBJ) -o $(NAME) $(LIBFT) $(LIBMLX) -framework OpenGL -framework AppKit; \
		echo "\x1b[1;34m[FRACTOL COMPILATION SUCCESSFUL]\x1b[0m"; \
	elif [ -e files_missing ]; then \
		echo "\x1b[1;31m[FRACTOL COMPILATION FAILED]\x1b[0m"; \
	fi;
	@/bin/rm -f $(LOGFOLDER)/relink
	@/bin/rm -f files_missing

clean:
	@$(MAKE) --no-print-directory -C libft clean
	@/bin/rm -f files_missing
	@/bin/rm -rf $(OBJ_ROOT)
	@/bin/echo "\x1b[1;33m[21SH CLEANED]\x1b[0m"

fclean:
	@$(MAKE) --no-print-directory -C libft fclean
	@/bin/rm -f files_missing
	@/bin/rm -rf $(OBJ_ROOT)
	@/bin/rm -f $(NAME)
	@echo "\x1b[1;33m[FRACTOL CLEANED]\x1b[0m"
	@echo "\x1b[1;35m[FRACTOL BINARY DELETED]\x1b[0m"

fclean_nolib:
	@/bin/rm -f files_missing
	@/bin/rm -rf $(OBJ_ROOT)
	@/bin/rm -f $(NAME)
	@echo "\x1b[1;33m[FRACTOL CLEANED]\x1b[0m"
	@echo "\x1b[1;35m[FRACTOL BINARY DELETED]\x1b[0m"

re: fclean all
re_nolib: fclean_nolib all

.PHONY: all clean fclean re log_check
