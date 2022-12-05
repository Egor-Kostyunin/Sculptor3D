/**@file mesh_object.hpp - этот файл содержит класс трехмеронго объекта mesh_object и определение структуры trmesh
 *@author Kostyunin Egor, kostyunin.eg@yandex.ru
 *@version 0.1
 *@date 2022
 *@copyright MIT-License
 */
#ifndef MESH_OBJECT_HPP
#define MESH_OBJECT_HPP
#include <iostream>
#include <map>
#include "point3f.hpp"
#include "trface.hpp"

using namespace std;
/**@brief trmesh - Полигональная сетка
 *@details Состоит из треугольных полигонов. Каждый полигон и вершина сетки имеют свой индекс.
 */
typedef struct {
	///Набор вершин
	map<int,point3f*> vertexes;
	///Набор граней
	map<int,trface*> faces;
} trmesh;
/**@brief mesh_object - Трехмерный объект
 *@details Состоит из треугольных полигонов. Каждый полигон и вершина сетки имеют свой индекс.
 * Так-же у объект имеет позицию и тип(не используется в текущей версии) 
 */
class mesh_object{
	///Полигональная сетка объекта
	trmesh mesh;
	///Тип объекта(Не используется в текущей версии)
	int type;
	///Позиция объекта
	point3f pos;
public:
	/**@brief Конструктор
	 *@param _pos - Позиция объекта 
	 *@param _type - Тип объекта(Не используется в текущей версии)
	 */
	mesh_object(point3f _pos,int _type);
	/**@brief - Функция установки полигональной сетки
	 *@param _mesh - Полигональная сетка
	 */
	void set_mesh(trmesh _mesh);
	/**@brief - Функция установки позиции объекта
	 *@param _pos - Позиция объекта
	 */
	void set_pos(point3f _pos);
	/**@brief - Функция установки части полигональной сетки
	 *@details Функция изменяет полигональную сетку 
	 * в соответствии индексами полигонов,
	 * полигоны имеющие хотя бы 2 вершины  
	 * с одинаковыми индексами считаются удаленными
	 *@param _mesh - Полигональная сетка
	 */
	void set_mesh_part(trmesh _mesh);
	/**@brief - Функция получения полигональной сетки
	 *@return trmesh - Полигональная сетка
	 */
	trmesh get_mesh();
	/**@brief - Функция получения позиции объекта
	 *@return point3f - Позиция объекта
	 */
	point3f get_pos();
	/**@brief - Функция проверки наличия инцедентных граней
	 *@details Функция проверяет наличие инцедентных вершине,
	 * с указанным индексом, граней
	 *@param index - Индекс вершины
	 *@return bool
	 */
	bool has_incedent_faces(int index);
	/**@brief - Функция получения видимой полигональной сетки
	 *@details Предполагается что камера направленна в центр объекта
	 *@param camera_pos - Позиция камеры
	 *@return *trmesh - Указатель на полигональную сетку 
	 */
	trmesh* get_visible_mesh(point3f camera_pos);
	friend std::ostream& operator<< (std::ostream& out,mesh_object mobj);
};
#endif		