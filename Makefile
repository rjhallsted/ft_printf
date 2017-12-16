#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 09:37:14 by rhallste          #+#    #+#              #
#    Updated: 2017/12/15 22:39:22 by rhallste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= 	libftprintf.a
CC			=	gcc
EXTRA_FLAGS =	-Weverything -Wno-cast-qual
CFLAGS		=	-Wall -Werror -Wextra

LIST		=	ft_lst_itemcpy				\
				ft_lst_remove_if			\
				ft_lst_swap					\
				ft_lstadd					\
				ft_lstdel					\
				ft_lstdelone				\
				ft_lstdup					\
				ft_lstiter					\
				ft_lstlen					\
				ft_lstmap					\
				ft_lstnew					

LOGIC		=	ft_isalnum					\
				ft_isalpha					\
				ft_isascii					\
				ft_isdigit					\
				ft_islower					\
				ft_isspace					\
				ft_isprint					\
				ft_isupper					

MEM			=	ft_bzero					\
				ft_memalloc					\
				ft_memccpy					\
				ft_memchr					\
				ft_memcmp					\
				ft_memcpy					\
				ft_memdel					\
				ft_memmove					\
				ft_memset					\
				ft_memrealloc

VSNPRINTF	=	$(addprefix ft_vsnprintf/,	\
				ft_vsnprintf				\
				specifiers					\
				specifiers2					\
				ap_to_str					\
				ap_helpers					\
				process_return				)

VPRINTF		=	$(addprefix ft_vprintf/,	\
				ft_vprintf					\
				ap_to_str					\
				ap_helpers					\
				process_return				)

PRINTING	=	ft_printf					\
				ft_printmemory				\
				ft_putchar					\
				ft_putchar_fd				\
				ft_putendl					\
				ft_putendl_fd	 			\
				ft_putnbr					\
				ft_putnbr_fd				\
				ft_putstr					\
				ft_putstr_fd				\
				$(VPRINTF)

STR			=	ft_atoi						\
				ft_intmaxtoa				\
				ft_intmaxtoa_base			\
				ft_itoa						\
				ft_itoa_base				\
				ft_ltoa						\
				ft_ltoa_base				\
				ft_lltoa					\
				ft_lltoa_base				\
				ft_padnumstr				\
				ft_snprintf					\
				ft_strcat					\
				ft_strchr					\
				ft_strclr					\
				ft_strcmp					\
				ft_strcpy					\
				ft_strdel					\
				ft_strdup					\
				ft_strequ					\
				ft_strinsert				\
				ft_striter					\
				ft_striteri					\
				ft_strjoin					\
				ft_strjoinfree				\
				ft_strlcat					\
				ft_strlen					\
				ft_strmap					\
				ft_strmapi					\
				ft_strncat					\
				ft_strncmp					\
				ft_strncpy					\
				ft_strnequ					\
				ft_strnew					\
				ft_strnstr					\
				ft_strrchr					\
				ft_strreplace				\
				ft_strsplit					\
				ft_strstr					\
				ft_strsub					\
				ft_strtolow					\
				ft_strtoup					\
				ft_strtrim					\
				ft_tolower					\
				ft_toupper					\
				ft_uitoa					\
				ft_uitoa_base				\
				ft_uintmaxtoa				\
				ft_uintmaxtoa_base			\
				ft_ultoa					\
				ft_ultoa_base				\
				ft_ulltoa					\
				ft_ulltoa_base				\
				ft_wstrlen					\
				ft_xstring					\
				$(VSNPRINTF)

UTIL		=	ft_digitcount				\
				ft_digitcount_base			\
				ft_free_2d_array			\
				ft_power					\
				ft_swap						\
				get_next_line

FILES		= $(LIST) $(LOGIC) $(MEM) $(PRINTING) $(STR) $(UTIL)

SRCS		=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS		=	$(addprefix src/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(OBJS): $(SRCS)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.SILENT: $(OBJS)
