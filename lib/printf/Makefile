##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for myprintf
##

SRC =	src/myprintf.c\
	src/switch_case_my_printf.c\
	src/mod_for_myprintf.c\
	src/my_real_putchar.c\
	src/my_real_putstr.c\
	src/length_nb.c\
	src/compute_pow.c\
	src/my_getnbr.c\
	src/my_put_b.c\
	src/my_putchar.c\
	src/my_put_f.c\
	src/my_put_nbr.c\
	src/my_put_o.c\
	src/my_put_p.c\
	src/my_putstr.c\
	src/my_put_u.c\
	src/flag_e.c\
	src/flag_em.c\
	src/my_put_g.c\
	src/my_put_gm.c\
	src/my_put_x.c\
	src/my_put_xm.c\
	src/my_put_n.c\
	src/length_modifier_h_l.c

SRCTEST =	tests/test_my_printf.c\
		tests/test_no_flag.c\
		tests/test_field_width.c\
		tests/test_c_flag.c\
		tests/test_i_flag.c\
		tests/test_d_flag.c\
		tests/test_o_flag.c\
		tests/test_u_flag.c\
		tests/test_p_flag.c\
		tests/test_f_flag.c\
		tests/test_pourcent_flag.c\
		tests/test_x_flag.c\
		tests/test_e_flag.c\
		tests/test_g_flag.c\
		tests/test_n_flag.c

OBJTEST =	$(SRCTEST:.c=.o)

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

NAMETEST =	unit_tests

CFLAGS	=	-Wall -Wextra

all:	$(NAME)
	cp -r libmy.a ../

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJTEST)

fclean:	clean
	rm -f $(NAME) $(NAMETEST)
	rm -f ../libmy.a
	rm -f ../../include/myprintf.h

re:	fclean
	make all

tests_run:
	make unit_tests
	./$(NAMETEST)

unit_tests:	$(OBJTEST)
	make all
	gcc -o $(NAMETEST) $(OBJTEST) $(NAME) $(CFLAGS) --coverage -lcriterion
