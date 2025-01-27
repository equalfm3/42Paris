# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 19:16:18 by mofikrat          #+#    #+#              #
#    Updated: 2019/12/08 15:51:37 by mofikrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

GCC			= /usr/bin/gcc
WOPT		= -Wall -Wextra -Werror
OOPT		= -O2
IOPT		= -I $(INCDIR)

SRCNAME =	ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_memccpy.c		\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_strlen.c			\
			ft_strdup.c			\
			ft_strcpy.c			\
			ft_strncpy.c		\
			ft_strcat.c			\
			ft_strncat.c		\
			ft_strlcat.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strstr.c			\
			ft_strnstr.c		\
			ft_strcmp.c			\
			ft_strncmp.c		\
			ft_atoi.c			\
			ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_memalloc.c		\
			ft_memdel.c			\
			ft_strnew.c			\
			ft_strdel.c			\
			ft_strclr.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strequ.c			\
			ft_strnequ.c		\
			ft_strsub.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_strsplit.c		\
			ft_isws1.c			\
			ft_isws2.c			\
			ft_countws1.c		\
			ft_countws2.c		\
			ft_itoa.c			\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_putendl.c		\
			ft_putnbr.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_lstnew.c			\
			ft_lstdelone.c		\
			ft_lstdel.c			\
			ft_lstadd.c			\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_isws1.c			\
			ft_isws2.c			\
			ft_countws1.c		\
			ft_countws2.c		\
			ft_nwords2c.c		\
			ft_strlen2c.c		\
			ft_ndigits.c		\
			ft_abs.c			\
			ft_swapbits.c		\
			ft_reversebits.c	\
			ft_printbits.c		\
			ft_sign.c			\
			ft_printhex.c		\
			ft_ispower2.c		\
			ft_iseven.c			\
			ft_strrev.c			\
			ft_swap.c			\
			ft_sortinttab.c		\


AR			= /usr/bin/ar -rc
RM			= /bin/rm -rf
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p

INCDIR		= ./includes
SRCDIR		= ./sources
OBJDIR		= ./objects

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))

CR			= "\r"$(CLEAR)
CLEAR       = "\\033[0K"
EOC			= "\033[0;0m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
PURPLEBG = "\033[0;45m"
GRAY = "\033[0;37m"
BASENAME	= `basename $(PWD)`


all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)
	@echo $(CR)$(PURPLEBG)"✓✓✓ $(NAME) created successfully ✓✓✓"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(GCC) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@
	@echo $(CR)$(GRAY)    \\t + $@$(EOC)

clean:
		@if [ -d $(OBJDIR) ]; then \
			$(RM) $(OBJDIR) \
			&& echo $(CR)$(RED)"✗✗✗ $(NAME) object files were cleaned successfully ✗✗✗"$(EOC); \
		fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME) \
		&& echo $(CR)$(RED)"✗✗✗ $(NAME) was cleaned successfully ✗✗✗"$(EOC); \
	fi

re: fclean all

norm:
	@$(NORMINETTE) $(INCDIR) $(SRC)

.PHONY: all clean fclean re norm
