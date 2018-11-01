# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/19 11:53:58 by xmoreau      #+#   ##    ##    #+#        #
#    Updated: 2017/12/26 18:15:31 by xmoreau     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = get_next_line

OBJS = get_next_line.o \
		main.o

all: $(NAME)

$(NAME): $(OBJS)
	make -C ../libft
	$(CC) $(CFLAGS) -o  $(NAME) $(OBJS) -L ../libft/ -lft

./%.o: ./%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C ../libft clean

fclean: clean
	make -C ../libft fclean
	rm -rf $(NAME)
	rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re
