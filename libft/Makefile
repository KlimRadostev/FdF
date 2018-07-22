#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kradoste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 16:00:50 by kradoste          #+#    #+#              #
#    Updated: 2018/07/19 17:23:17 by kradoste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
CFLAG = -Wall -Werror -Wextra
SOURCE = *.c

all : $(NAME)

$(NAME) :
		make -C libft
		make -C minilibx_macos
		cc -g -I includes $(SOURCE) -o $(NAME) -L minilibx_macos -lft -lmlx -framework OpenGL -framework AppKit

.PHONY : clean fclean re

clean :
		/bin/rm -f *~
		/bin/rm -f \#*\#
		/bin/rm -f *.o
		/bin/rm -rf *.dSYM
		/bin/rm -f includes/*~
		/bin/rm -f includes/\#*\#

fclean : clean
		make fclean -C libft
		/bin/rm -f $(NAME)

re : fclean all