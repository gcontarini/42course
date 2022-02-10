####### SOURCE FILES ######
SFILES	=	mtalk_utils.c
CFILES	=	mtalk_utils.c
SSRC	= $(addprefix src/, $(SFILES))
CSRC	= $(addprefix src/, $(CFILES))
SOBJ	= $(addprefix obj/, $(SFILES:.c=.o))
COBJ	= $(addprefix obj/, $(CFILES:.c=.o))
INC		= inc/

###### TARGETS ######
SRV		= server
CLT		= client
NAME	= $(SRV) $(CLT)
LIBFT	= libft.a

###### COMPILER ######
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		: $(NAME)

$(SRV)	: $(SOBJ) $(LIBFT) src/mtalk_server.c
	$(CC) $(CFLAGS) $^ -I$(INC) -o $@

$(CLT)	: $(COBJ) $(LIBFT) src/mtalk_client.c
	$(CC) $(CFLAGS) $^ -I$(INC) -o $@

obj/%.o	: src/%.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(LIBFT) : 
	@make -C libft/
	@cp libft/$@ .

clean	:
	$(RM) $(OBJ)
	@make fclean -C libft/

fclean	: clean
	$(RM) $(NAME) $(LIBFT)

re		: fclean all

.PHONY	: all clean fclean re 
