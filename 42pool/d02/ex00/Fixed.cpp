/*
** ETNA PROJECT, 12/06/2021 by feuvra_v
** Fixed
** File description:
**      functions for fixed class
*/

#include "Fixed.hpp"

int const Fixed::_frationalBits = 8;

Fixed::Fixed() : _value(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int value)// : _value(value)
{
    this->_value = value << _frationalBits;
    std::cout<<"Constructor with given value called"<<std::endl;
}

Fixed::Fixed(const Fixed& copy) : _value(copy.getRawBits())
{
    std::cout<<"Copy contructor called"<<std::endl;
    //this = copy;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed &Fixed::operator=(const Fixed& copy)
{
    //return (Fixed(copy.getRawBits()));
    std::cout<<"Assignement operator called"<<std::endl;
    this->_value = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called"<<std::endl;
    this->_value = raw << _frationalBits;
}