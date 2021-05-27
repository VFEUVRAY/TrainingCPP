#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

/* ** ETNA PROJECT, 16/03/2021 by feuvra_v ** my_putnbr_base ** File description: **      Display number in base given as parameter */ void my_putchar(char c); int my_strlen(const char *str) {     int len = 0;     while (str[len])         len = len + 1;     return (len); } void recurs_nbr(int nbr, const char *base, int div) {     int to_print;     int n_adjust = nbr < 0 ? -1 : 1;     if (nbr < 0)         my_putchar('-');     to_print = (nbr % div) * n_adjust;     if (nbr < 0 && nbr <= (div * n_adjust))         recurs_nbr((nbr / div) * n_adjust, base, div);     if (nbr >= div)         recurs_nbr(nbr / div, base, div);     my_putchar(base[to_print]); } void print_base1(int nbr, const char *base) {   if (nbr < 0) {     my_putchar('-');     my_putchar(base[0]);     nbr = nbr + 1;     nbr = nbr * (-1);   }   while (nbr > 0) {     my_putchar(base[0]);     nbr = nbr - 1;   } } void my_putnbr_base(int nbr, const char *base) {     int base_len = my_strlen(base);     if (base_len == 1)       print_base1(nbr, base);     if (base_len > 1)       recurs_nbr(nbr, base, base_len); }

int main()
{
    my_putnbr_base(19,"012345678");
    return (0);
}