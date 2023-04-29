# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 19:53:14 by pramos-m          #+#    #+#              #
#    Updated: 2023/04/25 13:32:37 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-----------------RULES------------------#

NAME = philo
#----------------COMANDS-----------------#

CFLAGS = -Wall -Werror -Wextra -W -O3 -Ofast
XFLAGS = -fsanitize=address -g3
RM = rm -rf
MD = mkdir -p
CP = cp -f

#------------------PATH-------------------#

SRC_DIR = src/
UTILS = utils/
INC_DIR = ./inc/
OBJ_DIR = ./.obj/

#----------------PHILO-----------------#

INCLUDE = -I$(INC_DIR) -Ibonus/inc/

SRC_FLS = philosophers.c \
			philo_init.c \
			philo_simulation.c \
			philo_eating.c \
			philo_errors.c

UTL_FLS = philo_utils.c \
			philo_print_utils.c \
			philo_extra_utils.c \
			philo_lib_utils.c

SRCS += $(addprefix $(SRC_DIR), $(SRC_FLS))
SRCS += $(addprefix $(UTILS), $(UTL_FLS))

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))
DEPS = $(OBJS:%.o=%.d)

#------------------RULES-------------------#

$(OBJ_DIR)%.o: %.c
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) -o philo

$(NAME)::
	@echo "nothing to be done philosophers"

clean:
	@$(RM) -rf $(OBJ_DIR) $(NAME)
	@echo "clean done"

fclean:
	@$(RM) $(NAME)
	@$(RM) -rf $(OBJ_DIR)
	@echo "fclean done"

re:
	@$(MAKE) fclean
	@$(MAKE) all