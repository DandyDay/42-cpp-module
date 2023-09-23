/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:35:47 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/23 18:08:22 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{

}

Point::Point(float x, float y) : x_(x), y_(y)
{

}

Point::Point(const Point &other)
{
	x_ = other.x_;
	y_ = other.y_;
}

Point &Point::operator=(const Point &other)
{
	x_ = other.x_;
	y_ = other.y_;

	return (*this);
}

Point::~Point()
{

}

Point Point::operator-(const Point &other) const
{
	Point result((x_ - other.x_).toFloat(), (y_ - other.y_).toFloat());

	return result;
}

Fixed Point::cross(const Point &other) const
{
	Fixed result(this->x_ * other.y_ - this->y_ * other.x_);
	return result;
}
