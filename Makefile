# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 19:53:14 by pramos-m          #+#    #+#              #
#    Updated: 2023/04/07 21:48:27 by pramos-m         ###   ########.fr        #
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

#----------------PHILO-----------------#

INCLUDE = -I$(INC_DIR) -I$(LIB_DIR) -I$(PRINT_DIR) -Ibonus/inc/

SRC_FLS = philosophers.c \
			.c \
			.C \
			.c 

UTL_FLS = philo_utils.c

SRCS += $(addprefix $(SRC_DIR), $(SRC_FLS))
SRCS += $(addprefix $(UTILS), $(UTL_FLS))

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))
DEPS = $(OBJS:%.o=%.d)

#------------------RULES-------------------#
