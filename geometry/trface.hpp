/**@file trface.hpp - этот файл содержит класс треугольного полигона trface
 *@author Kostyunin Egor, kostyunin.eg@yandex.ru
 *@version 0.1
 *@date 2022
 *@copyright MIT-License
 */
#ifndef TRFACE_HPP
#define TRFACE_HPP
#include <iostream>
#include "point3f.hpp"
/**@brief trface - класс треугольного полигона
 *@details точки полигона задаются их индексами
 * так же trface хранит координаты вектора нормали полигона
 */
class trface{
public:
	///Первая Точка
	int point1,
	///Вторая Точка
		point2,
	///Третья Точка
		point3;
	///Координаты вектора нормали
	point3f normal;
	/**@brief Конструктор
	 *@details координаты вектора нормали расчитываются специальной функцией позже
	 *при создании полигона устанавливаются как (0,0,0)
	 *@param p1 - индекс первой точки
	 *@param p2 - индекс второй точки
	 *@param p3 - индекс третьей точки
	 */
	trface(int p1,int p2,int p3);
	friend std::ostream& operator<< (std::ostream& out,const trface face);
};
#endif