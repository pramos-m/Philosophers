# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 16:43:07 by pramos-m          #+#    #+#              #
#    Updated: 2023/01/21 17:33:03 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MKFL = Makefile

SRC_DIR = src/

OBJ_DIR = obj/

CFLAGS = -Wall -Wextra -Werror -W -O3 -Ofast

RM = rm -f

MK = mkdir -p

INCLUDE = -I ./

SRC_PRT = ft_printf.c

UTL_PRT = ft_print_char.c ft_print_decimal.c ft_print_hexa_low.c ft_print_hexa_up.c \
			ft_print_pointer.c ft_print_str.c ft_print_unsigned.c

SRCS += $(SRC_PRT)

SRCS += $(addprefix $(SRC_DIR), $(UTL_PRT))

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

DEPS = $(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o: %.c $(MKFL)
	$(MK) $(dir $@)
	$(CC) $(CFLAGS) -MT $@ -MMD -MP $(INCLUDE) -c $< -o $@

all :
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(NAME)::
	@printf ''

-include $(DEPS)

clean :
	@$(RM) -r $(OBJ_DIR)

fclean :
	@$(MAKE) clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
