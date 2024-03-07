##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for secured
##

SRC =	src/add_hash_table.c\
		src/delete_hash_table.c\
		src/hash_function.c\
		src/ht_delete.c\
		src/ht_dump.c\
		src/ht_insert.c\
		src/ht_search.c\
		src/my_strcpy.c\
		src/my_strdup.c\
		src/my_strcmp.c

OBJTEST =	$(SRCTEST:.c=.o)

OBJ =	$(SRC:.c=.o)

NAME =	libhashtable.a

CFLAGS	=	-Wall -Wextra -L lib/ -lmy

all:	$(NAME)

$(NAME):	makelib $(OBJ)
	ar rcs libhash.a $(OBJ)
	ar crsT $(NAME) libhash.a lib/libmy.a

clean:
	rm -f $(OBJ) $(OBJTEST)

fclean:	clean
	rm -f $(NAME)
	rm -f libhash.a
	make -C lib/printf/ fclean

re:	fclean
	make all

makelib:
	make -C lib/printf/
