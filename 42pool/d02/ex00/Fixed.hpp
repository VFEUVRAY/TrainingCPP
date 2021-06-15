/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Fixed
** File description:
**      header for fixed number class
*/

#include <string>
#include <iostream>

class Fixed
{
    private:
        int _value;
        static const int _frationalBits;

    public:
        Fixed();
        ~Fixed();
        Fixed(const int value);
        Fixed(const Fixed& copy);
        Fixed &operator=(const Fixed& copy);
        int getRawBits( void ) const;
        void setRawBits(int const raw);
};