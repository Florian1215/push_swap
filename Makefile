
# VAR ---------------------------------------------------------------
OBJS_DIR		=	.OBJS/
SRCS			=	INSTRUCTIONS/push.c INSTRUCTIONS/reverse.c INSTRUCTIONS/rotate.c INSTRUCTIONS/swap.c \
					UTILS/parsing.c UTILS/sort_index.c UTILS/split.c UTILS/utils1.c UTILS/utils2.c
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

NAME			=	push_swap
SRCS_MAND		=	SOLVE/push_swap.c SOLVE/radix.c SOLVE/smart_sort.c SOLVE/utils_solve1.c SOLVE/utils_solve2.c SOLVE/utils_solve3.c
OBJS_MAND		=	$(addprefix $(OBJS_DIR), $(SRCS_MAND:.c=.o))

NAME_BONUS		=	checker
SRCS_BONUS		=	BONUS/checker.c BONUS/get_next_line.c
OBJS_BONUS		=	$(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

HEAD_DIR		=	INCLUDES/
HEAD			=	$(HEAD_DIR)$(NAME).h

CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror

# RULES -------------------------------------------------------------
all:				$(NAME)

$(NAME):			$(OBJS) $(OBJS_MAND)
					$(CC) $(FLAGS) $(OBJS) $(OBJS_MAND) -o $(NAME)

bonus:				$(OBJS) $(OBJS_BONUS)
					$(CC) $(FLAGS) $(OBJS) $(OBJS_BONUS) -o $(NAME_BONUS)

$(OBJS_DIR)%.o:		%.c $(HEAD) Makefile | dir
					$(CC) $(FLAGS) -I $(HEAD_DIR) -c $< -o $@

dir:
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)BONUS
					@mkdir -p $(OBJS_DIR)INSTRUCTIONS
					@mkdir -p $(OBJS_DIR)SOLVE
					@mkdir -p $(OBJS_DIR)UTILS

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.PHONY:				all dir clean fclean re bonus
