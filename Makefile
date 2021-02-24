# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastasia <anastasia@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 19:16:42 by anastasia         #+#    #+#              #
#    Updated: 2021/02/24 18:39:10 by anastasia        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

SRC				=	cub3d.c \
			

SRCS			=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJ))

SRCS_DIR		=	./srcs/
OBJS_DIR		=	./objs/
LIBFT_DIR		=	./libft/

I_INC			=	-I ./includes/ -I ./libft/ 

RM 				=	rm -rf

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

LIBFT			=	@make -sC $(LIBFT_DIR)

all:				$(NAME)

OBJ				=	$(SRC:.c=.o)

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.c ./includes/cub3d.h
					mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -c $< -o $@ $(I_INC)

$(NAME):			$(OBJS) ./includes/cub3d.h
					$(LIBFT)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft $(I_INC) 

clean:
					$(RM) $(OBJS_DIR)
					@make clean -C $(LIBFT_DIR)

fclean:				clean
					$(RM) $(NAME)
					@make fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY:				all clean fclean re