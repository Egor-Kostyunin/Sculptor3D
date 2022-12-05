/**@file point3f.сpp - этот файл содержит реализацию класса точки point3f
 *@author Kostyunin Egor, kostyunin.eg@yandex.ru
 *@version 0.1
 *@date 2022
 *@copyright MIT-License
 */
#include "point3f.hpp"
#include <cmath>

point3f::point3f(float _x,float _y,float _z){
	x = _x;
	y = _y;
	z = _z;
}

float point3f::cos(point3f vec){
	float result =  vec.x * x +
					vec.y * y +
					vec.z * z;
	float lenSq = (x*x +
				   y*y +
				   z*z)*
				  (vec.x*vec.x+
				   vec.y*vec.y+
				   vec.z*vec.z);
	return result/sqrt(lenSq);
}

point3f point3f::operator+ (point3f& point){
	point3f result = point3f(x + point.x,
							 y + point.y,
							 z + point.z);
	if(abs(result.x) < 0.00001) result.x = 0;
	if(abs(result.y) < 0.00001) result.y = 0;
	if(abs(result.z) < 0.00001) result.z = 0;
	return result;
}

point3f point3f::operator- (point3f& point){
	point3f result = point3f(x - point.x,
							 y - point.y,
							 z - point.z);
	if(abs(result.x) < 0.00001) result.x = 0;
	if(abs(result.y) < 0.00001) result.y = 0;
	if(abs(result.z) < 0.00001) result.z = 0;
	return result;
}

point3f point3f::operator/ (float number){
	point3f result = point3f(x /= number,
							 y /= number,
							 z /= number);
	if(abs(result.x) < 0.00001) result.x = 0;
	if(abs(result.y) < 0.00001) result.y = 0;
	if(abs(result.z) < 0.00001) result.z = 0;
	return result;
}

point3f point3f::operator+= (point3f point){
	return *this + point;
}

point3f point3f::operator-= (point3f point){
	return *this - point;
}

point3f point3f::operator/= (float number){
	return *this / number;
}

std::ostream& operator<< (std::ostream& out,const point3f point){
	out<<"x:"<<point.x<<" y:"<<point.y<<" z:"<<point.z;
	return out;
}