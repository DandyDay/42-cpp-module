/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:53:19 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/01 16:39:19 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point p1(0, 0), p2(1, 0), p3(0, 1);
	Point pi(0.5, 0.3), po(0.5, 0.5);

	std::cout << bsp(p1, p2, p3, pi) << std::endl;
	std::cout << bsp(p1, p2, p3, po) << std::endl;

	return 0;
}
