# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 19:53:14 by pramos-m          #+#    #+#              #
#    Updated: 2023/04/12 11:51:26 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-----------------RULES------------------#

NAME = philosophers

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
LIB_DIR = ./lib/

OBJ_DIR = ./.obj/

LIBFT_DIR = $(LIB_DIR)libft/

PRINT_DIR = $(LIB_DIR)printf/

LIBRARY = $(LIB_DIR)/*/*.a

#----------------PHILO-----------------#

INCLUDE = -I$(INC_DIR) -I$(LIB_DIR) -I$(PRINT_DIR) -Ibonus/inc/

SRC_FLS = philosophers.c \
			simulation.c
			# .C \
			# .c 

UTL_FLS = philo_utils.c

SRCS += $(addprefix $(SRC_DIR), $(SRC_FLS))
SRCS += $(addprefix $(UTILS), $(UTL_FLS))

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))
DEPS = $(OBJS:%.o=%.d)

#------------------RULES-------------------#

$(OBJ_DIR)%.o: %.c $(LIBRARY)
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@

all:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	$(CC) $(CFLAGS) -MMD $(OBJS) $(LIBRARY) -o philosophers

$(NAME)::
	@echo "nothing to be done philosophers"

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@echo "clean done"

fclean:
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(NAME)
	@$(RM) -rf $(OBJ_DIR)
	@echo "fclean done"

re:
	@$(MAKE) fclean
	@$(MAKE) all