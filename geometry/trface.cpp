/**@file trface.сpp - этот файл содержит реализацию класса треугольного полигона trface
 *@author Kostyunin Egor, kostyunin.eg@yandex.ru
 *@version 0.1
 *@date 2022
 *@copyright MIT-License
 */
#include "trface.hpp"
trface::trface(int p1,int p2,int p3){
	point1 = p1;
	point2 = p2;
	point3 = p3;
}

std::ostream& operator<< (std::ostream& out,const trface face){
	out<<"trface:\npoint1: v"
	   <<face.point1
	   <<"\npoint2: v"
	   <<face.point2
	   <<"\npoint3: v"
	   <<face.point3
	   <<"\nnormal:"
	   <<face.normal;
	return out;
}