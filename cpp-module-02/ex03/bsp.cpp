/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:35:43 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/01 16:39:18 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	typedef Point Vector;

	Vector pa = point - a;
	Vector pb = point - b;
	Vector pc = point - c;

	Fixed ab = pa.cross(pb);
	Fixed bc = pb.cross(pc);
	Fixed ca = pc.cross(pa);

	if ((ab > 0 && bc > 0 && ca > 0) ||
		(ab < 0 && bc < 0 && ca < 0))
		return true;
	else
		return false;
}
