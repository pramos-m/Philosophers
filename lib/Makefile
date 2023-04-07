# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 18:01:27 by pramos-m          #+#    #+#              #
#    Updated: 2023/04/07 21:45:21 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR = libft/

PRNT_DIR = printf/

LIBFT = ./$(LIB_DIR)libft.a

PRINTF = ./$(PRNT_DIR)libftprintf.a
# declarem aquestes dos variables per a portar el .a de cada carpeta al path actual
all:
	@$(MAKE) makelib
	@$(MAKE) makeprint

makelib:
	@$(MAKE) -C $(LIB_DIR)
#flag -C indica directori 
makeprint:
	@$(MAKE) -C $(PRNT_DIR)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(MAKE) clean -C $(PRNT_DIR)
#clean borra objectes i dependencies

fclean:
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(MAKE) fclean -C $(PRNT_DIR)
	@rm -f libft.a
	@rm -f libftprintf.a
#borra tot (.a, programas...)
re:
	@$(MAKE) re -C $(LIB_DIR)
	@$(MAKE) re -C $(PRNT_DIR)

.PHONY: all clean fclean re 