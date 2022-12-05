/**@file point3f.hpp - этот файл содержит класс точки point3f
 *@author Kostyunin Egor, kostyunin.eg@yandex.ru
 *@version 0.1
 *@date 2022
 *@copyright MIT-License
 */
#ifndef POINT3F_HPP
#define POINT3F_HPP
#include <iostream>
/**@brief point3f - класс точки
 *@details координаты точки задаются вещественными(дробными) числами
 */
class point3f{
public:
	///x координата точки
	float x,
	///y координата точки
		  y,
	///z координата точки
		  z;
	/**@brief Конструктор
	 *@param _x - x координата точки
	 *@param _y - y координата точки
	 *@param _z - z координата точки
	 */
	point3f(float _x=0,float _y=0,float _z=0);
	/**@brief cos - Функция косинуса
	 *@details Функция находит угол между переданным и текущим вектором
	 *@param vec - координаты вектора
	 *@return float
	 */
	float cos(point3f vec);
	point3f operator+ (point3f& point);
	point3f operator- (point3f& point);
	point3f operator/ (float number);
	point3f operator+= (point3f point);
	point3f operator-= (point3f point);
	point3f operator/= (float number);
	friend std::ostream& operator<< (std::ostream& out,const point3f point);
};
#endif