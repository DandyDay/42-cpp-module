/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:39:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/23 17:31:08 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

const int Fixed::fractional_bits_ = 8;

Fixed::Fixed() : raw_bits_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	raw_bits_ = num << 8;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;

	raw_bits_ = roundf(num * 256);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	raw_bits_ = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->raw_bits_ = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->raw_bits_ == other.raw_bits_);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->raw_bits_ != other.raw_bits_);
}


bool Fixed::operator<(const Fixed& other) const
{
	return (this->raw_bits_ < other.raw_bits_);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->raw_bits_ <= other.raw_bits_);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->raw_bits_ > other.raw_bits_);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->raw_bits_ >= other.raw_bits_);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.raw_bits_ = this->raw_bits_ + other.raw_bits_;

	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.raw_bits_ = this->raw_bits_ - other.raw_bits_;

	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.raw_bits_ = this->raw_bits_ * other.raw_bits_ >> 8;

	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.raw_bits_ = this->raw_bits_ / other.raw_bits_ << 8;

	return result;
}

Fixed& Fixed::operator++()
{
	raw_bits_++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}
Fixed& Fixed::operator--()
{
	raw_bits_--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.raw_bits_ > b.raw_bits_ ? a : b;
}
Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
	return a.raw_bits_ < b.raw_bits_ ? a : b;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return raw_bits_;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	raw_bits_ = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();

	return os;
}


float Fixed::toFloat(void) const
{
	float num = raw_bits_ / 256.0;
	return num;
}

int Fixed::toInt(void) const
{
	return raw_bits_ >> 8;
}