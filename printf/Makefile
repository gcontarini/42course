########## SOURCE FILES ##########
FILES 	=	ft_printf.c			\
			ftptf_args.c		\
			ftptf_char.c		\
			ftptf_flush.c		\
			ftptf_int.c			\
			ftptf_jptab.c		\
			ftptf_lowhex.c		\
			ftptf_memerror.c	\
			ftptf_perc.c		\
			ftptf_ptr.c			\
			ftptf_queue.c		\
			ftptf_str.c			\
			ftptf_uint.c		\
			ftptf_uphex.c
SRC		=	$(addprefix src/, $(FILES))
OBJS 	= 	$(SRC:.c=.o)
INCS	=	includes/

############ TARGETS #############
NAME 	= 	libftprintf.a
LFT 	= 	libft.a

########## COMPILER OPTS #########
CC 		= 	gcc 
CFLAGS	= 	-Wall -Werror -Wextra
RM		= 	rm -f
AR		=	ar rcs
LFT_MK	=	-C libft/

############## RULES #############
%.o		: %.c
		$(CC) $(CFLAGS) -I$(INCS) -c $< -o $@

$(NAME)	: $(OBJS) $(LFT)
		@cp $(LFT) $(NAME)
		$(AR) $@ $^

$(LFT)	:	
		@make $(LFT_MK)
		@mv libft/$(LFT) .

all		: $(NAME)

bonus	: $(NAME)

clean	:
		@$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME) $(LFT)
		@make clean $(LFT_MK)

re		: fclean all

.PHONY	: all clean fclean re 
