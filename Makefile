# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 18:30:04 by raida             #+#    #+#              #
#    Updated: 2021/04/29 11:22:58 by raida            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

PART12		=	ft_atoi.c			\
				ft_bzero.c			\
				ft_calloc.c			\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_memccpy.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_strchr.c			\
				ft_strdup.c			\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_tolower.c		\
				ft_toupper.c		\
				ft_putchar_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_putstr_fd.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strjoin.c		\
				ft_strmapi.c		\
				ft_strtrim.c		\
				ft_substr.c			

BONUS		=	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c

PART12_OBJS	= $(PART12:.c=.o)
BONUS_OBJS	= $(BONUS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
HEADER		= libft.h

ifdef WITH_BONUS
OBJS = $(PART12_OBJS) $(BONUS_OBJS)
else
OBJS = $(PART12_OBJS)
endif

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER)

$(NAME):$(OBJS)
		ar rcs $(NAME) $(OBJS)
all:	$(NAME)

clean:
		rm -f $(OBJS) ${BONUS_OBJS}
	
fclean:	clean
		rm -f $(NAME)
	
re:		fclean all

bonus:
		$(MAKE) WITH_BONUS=1 all

.PHONY:	all clean fclean re bonus