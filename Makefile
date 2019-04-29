##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

SRC_DIR	=	src/
LIB_DIR	=	lib/my/
INC_DIR	=	include/
TESTS_DIR	=	tests/

TARGET	=	navy

CFLAGS	=	-g -Wall -Wextra -I $(INC_DIR)

LDFLAGS	=	-L $(LIB_DIR) -lmy

SRC	=	$(SRC_DIR)map_handler.c \
		$(SRC_DIR)file_handler.c \
		$(SRC_DIR)attack.c \
		$(SRC_DIR)defense.c \
		$(SRC_DIR)heyfun_h.c \
		$(SRC_DIR)file_error.c \
		$(SRC_DIR)end_and_turn.c

SRC_TESTS	=	$(TESTS_DIR)boat_lenght.c \
				$(TESTS_DIR)diagonal.c \
				$(TESTS_DIR)norm_boat.c

SRCS	=	$(SRC) $(SRC_DIR)main.c
SRCS_TESTS	=	$(SRC) $(SRC_TESTS)

OBJ	=	$(SRCS:.c=.o)
OBJ_TESTS	=	$(SRCS_TESTS:.c=.o)

RM	=	rm -f

all:	$(TARGET)

# `make` normal
$(TARGET): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

# `make clean` clean lib/*.o + projet
clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OBJ)
	$(RM) $(OBJ_TESTS)

# `make clean` clean + binary/library
fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(TARGET)
	$(RM) unit_tests

# `make tests_run` criterion
tests_run: $(OBJ_TESTS)
	make -C $(LIB_DIR)
	$(CC) -o unit_tests $(OBJ_TESTS) $(LDFLAGS) -lcriterion

re:	fclean all

.PHONY: all clean fclean re
