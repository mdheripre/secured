/*
** EPITECH PROJECT, 2023
** MYPRINTF.H
** File description:
** functions / structures for myprintf
*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#ifndef MYPRINTF_
    #define MYPRINTF_

struct f_a {
    int plus;
    int minus;
    int precision;
    int field;
    int hash;
    int zero;
    int space;
    int nb;
    int h;
    int l;
    int check_dot;
};

struct r_s {
    char const *format;
    char fmt[4096];
    int index;
};

void test_my_printf(char const *, ...);
void switch_case_disc(struct r_s *, int *i, struct f_a *, va_list);
void switch_case_uobx(struct r_s *, int *i, struct f_a *, va_list);
void switch_case_pfn(struct r_s *, int *i, struct f_a *, va_list);
void switch_case_eg(struct r_s *, int *i, struct f_a *, va_list);
int my_vprintf(char const *fmt, va_list va);
int my_printf(char const *, ...);
int my_getnbr(char const *, int *);
int checksign(char const *str);
int count_sign(char const *);
int my_strlen2(char const *);
int length_nb(int nb);
void my_put_nbr(long long nb, struct r_s *, struct f_a *);
void my_put_nbr_e(int, struct r_s *, struct f_a *);
void my_putstr(char *, struct r_s *, struct f_a *);
void my_putchar(char, struct r_s *);
void my_put_e(double, struct r_s *, struct f_a *);
void my_put_em(double, struct r_s *, struct f_a *);
void my_put_g(double, struct r_s *, struct f_a *);
void my_put_gm(double, struct r_s *, struct f_a *);
void my_put_u(unsigned long long nb, struct r_s *, struct f_a *);
void my_put_b(unsigned long long nb, struct r_s *r_s);
void my_put_o(unsigned long long nb, struct r_s *r_s, struct f_a *f_m);
void my_put_x(unsigned long long nb, struct r_s *r_s, struct f_a *f_m);
void my_put_xm(unsigned int, struct r_s *, struct f_a *);
void my_put_p(void *, struct r_s *, struct f_a *);
void my_put_f(double nb, struct r_s *r_s, struct f_a *f_m);
void my_put_n(int *, struct f_a *);
long long h_and_l(unsigned int nb, struct f_a *f_m);
void check_all_mod(struct r_s *r_s, int *i, struct f_a *f_m);
int compute_pow(int, int);
int my_real_putchar(char);
int my_real_putstr(char *);
#endif /* MYPRINTF_ */
