NAME		= libftprintf.a
LIBFT		= libft
INCLUDE    	= include
INCLUDE_BN	= include_bonus
MANDATORYDIR= mandatory/
BONUSDIR	= bonus/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf
AR			= ar rcs

FILES 		= ft_printf.c \
				ft_converter_c.c \
				ft_converter_d.c \
				ft_converter_i.c \
				ft_converter_p.c \
				ft_converter_per.c \
				ft_converter_s.c \
				ft_converter_u.c \
				ft_converter_upX.c \
				ft_converter_utils_di.c \
				ft_converter_utils_xX.c \
				ft_converter_utils.c \
				ft_converter_x.c \
				ft_printf_utils.c \
				ft_check_csset.c \
				parse_csset.c

FILES_BN	= ft_printf_bonus.c \
				ft_converter_c_bonus.c \
				ft_converter_d_bonus.c \
				ft_converter_i_bonus.c \
				ft_converter_p_bonus.c \
				ft_converter_per_bonus.c \
				ft_converter_s_bonus.c \
				ft_converter_u_bonus.c \
				ft_converter_upX_bonus.c \
				ft_converter_utils_di_bonus.c \
				ft_converter_utils_xX_bonus.c \
				ft_converter_utils_bonus.c \
				ft_converter_x_bonus.c \
				ft_printf_utils_bonus.c \
				ft_check_csset_bonus.c \
				parse_csset_bonus.c

SRCS		= $(addprefix $(MANDATORYDIR), $(FILES))
SRCS_BN		= $(addprefix $(BONUSDIR), $(FILES_BN))

OBJS		= $(SRCS:.c=.o)
OBJS_BN		= $(SRCS_BN:.c=.o)

$(MANDATORYDIR)%.o: $(MANDATORYDIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(BONUSDIR)%.o: $(BONUSDIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_BN)

all		: $(NAME)

bonus	: $(NAME)

ifeq ($(MAKECMDGOALS), bonus)
$(NAME) : $(OBJS_BN)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJS_BN)
else
$(NAME) : $(OBJS)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJS)
endif

clean	:
			$(RM) $(OBJS) $(OBJS_BN)
			make clean -C $(LIBFT)

fclean	: clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a

re		: fclean all

rebn	: fclean
			$(MAKE) bonus

.PHONY:		all clean fclean re rebn