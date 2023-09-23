/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:39:33 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/23 17:29:01 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed max(const Fixed& a, const Fixed& b);
	static Fixed min(const Fixed& a, const Fixed& b);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt(void) const;
private:
	static const int fractional_bits_;
	int raw_bits_;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
