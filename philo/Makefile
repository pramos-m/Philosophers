# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 19:53:14 by pramos-m          #+#    #+#              #
#    Updated: 2023/05/01 15:07:51 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-----------------RULES------------------#

NAME = philo
#----------------COMANDS-----------------#

CFLAGS = -Wall -Werror -Wextra -W -O3 -Ofast
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

INC_FLS = philosophers philosophers_utils

SRCS += $(addprefix $(SRC_DIR), $(SRC_FLS))
SRCS += $(addprefix $(UTILS), $(UTL_FLS))

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))
DEPS = $(OBJS:%.o=%.d)
INCS = $(addprefix $(INC_DIR), $(addsuffix .h, $(INC_FLS)))

#------------------RULES-------------------#

$(OBJ_DIR)%.o: %.c $(INCS)
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) -fsanitize=address -MMD $(INCLUDE) -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o philo

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