# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gavril <gavril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 19:22:08 by alancel           #+#    #+#              #
#    Updated: 2021/04/28 15:03:57 by gavril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_memset.c \
				ft_bzero.c \
				ft_strlen.c \
				ft_memchr.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memcmp.c \
				ft_strlcpy.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcat.c \
				ft_strnstr.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_split.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_free_w.c \
				ft_lst_free.c

CC			=	gcc
	
OBJS		=	$(SRCS:.c=.o)

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

BONUS_SRCS	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc -c $(SRCS)
				ar rc $(NAME) $^
				ranlib $(NAME)

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

bonus:			$(OBJS) $(BONUS_OBJS)
				gcc -c $(SRCS) $(BONUS_SRCS)
				ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
				ranlib $(NAME)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus