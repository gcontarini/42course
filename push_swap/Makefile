################### FILES ###################
FILES		=	ps_args.c			\
				ps_errors.c			\
				ps_checksort.c		\
				ps_insert_sort.c	\
				ps_selection_sort.c	\
				ps_mp_sort.c		\
				ps_mp_sort_a.c		\
				ps_mp_sort_b.c		\
				ps_naive_sort.c		\
				ps_radix_sort.c		\
				ps_push.c			\
				ps_rot.c			\
				ps_rrot.c			\
				ps_stack.c			\
				ps_swap.c			\
				ps_stats.c			\
				ps_stats_depth.c	\
				ps_execute.c		\
				ps_utils.c

################### PATHS ###################
PSRC		= src
POBJ		= obj
SRC			= $(addprefix $(PSRC)/, $(FILES))
OBJ			= $(addprefix $(POBJ)/, $(FILES:.c=.o))
INC			= -I includes/

################## TARGETS ##################
MAIN		= $(PSRC)/ps_main.c
NAME		= push_swap
LFT			= libft.a

################### CC OPT ##################
CC			= gcc -Wall -Wextra -Werror
RM			= rm -f
MKLFT		= -C libft/

#################### RULES ##################
$(POBJ)/%.o	: $(PSRC)/%.c
			@mkdir -p $(@D)
			$(CC) -c $< $(INC) -o $@

$(NAME)		: $(OBJ) $(LFT) $(MAIN)
			$(CC) $(MAIN) $(OBJ) $(LFT) $(INC) -o $@

$(LFT)		:
			@make $(MKLFT)
			@mv libft/$(LFT) .

all			: $(NAME)

dev			: $(OBJ) $(LFT) $(MAIN)
			$(CC) $(MAIN) -g $(OBJ) $(LFT) $(INC) -o $(NAME)

clean		:
			@$(RM) $(OBJ)

fclean		: clean
			$(RM) $(NAME) $(LFT)
			@make clean $(MKLFT)

re			: fclean all

.PHONY		: all clean fclean re dev
