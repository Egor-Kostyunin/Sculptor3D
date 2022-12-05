/**@file geometry_util.hpp - этот файл содержит вспомогательные функции для работы с геометрией
 *@author Kostyunin Egor, kostyunin.eg@yandex.ru
 *@version 0.1
 *@date 2022
 *@copyright MIT-License
 */
#ifndef GEOMETRY_UTIL_HPP
#define GEOMETRY_UTIL_HPP
#include "mesh_object.hpp"
/**@breief calculate_normal - функция расчета нормали
 *@details расчитывает нормали для полигональной сетки
 *@param mesh - указатель на полигональную сетку
 */
void calculate_normal(trmesh* mesh);
/**@breief calculate_vertex_normal - функция расчета нормали
 *@details расчитывает нормали для вершины как среднее значение нормалей смежных полигонов
 *@param faces - указатель на массив смежных полигонов
 *@param count - кол-во полигонов
 */
point3f calculate_vertex_normal(trface* faces,int count);
/**@breief get_vector3f_length - функция расчета длины вектора
 *@param vec - координаты вектора
 */
float get_vector3f_length(point3f vec);
/**@breief normalize_vector - функция нормализации вектора
 *@param vec - указатель на координаты вектора
 */
void normalize_vector(point3f* vec);
#endif