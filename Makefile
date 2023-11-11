NAME := swap_push

DIR_UTILS := utils/
DIR_SUPPORT := support/
DIR_HANDLERS := handlers/
DIR_VALIDATE := val_exit/
#-------------
#-------------
DIR_TEST := test/
TEST_FILES := 
TESTS := $(addprefix $(DIR_TEST), $(TEST_FILES))
#-------------
#-------------


VALIDATE_FILES = validate.c exiting.c
UTILS_FILES = utils.c utils_support.c
SUPPORT_FILES = support.c
HANDLERS_FILES = \
 pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa_sb.c ss.c create_free.c \
 print_fun.c


OBJECTS = $(UTILS:.c=.o) $(SUPPORT:.c=.o) $(HANDLERS:.c=.o) $(VALIDATES:.c=.o)


UTILS := $(addprefix $(DIR_UTILS), $(UTILS_FILES))
SUPPORT := $(addprefix $(DIR_SUPPORT),  $(SUPPORT_FILES))
HANDLERS := $(addprefix $(DIR_HANDLERS), $(HANDLERS_FILES))
HANDLERS := $(addprefix $(DIR_HANDLERS), $(HANDLERS_FILES))
VALIDATES := $(addprefix $(DIR_VALIDATE), $(VALIDATE_FILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LEAKS = -g

all : $(NAME)

$(NAME):$(OBJECTS)
	$(CC) $(CFLAGS) $(LEAKS) -o $(NAME) main.c $(UTILS) $(HANDLERS) $(SUPPORT) $(VALIDATES)

clean:
	rm -rf  $(NAME) $(OBJECTS)

fclean: clean
	
re: fclean all

.PHONY: all  clean fclean re