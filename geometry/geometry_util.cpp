/**@file geometry_util.сpp - этот файл содержит реализацию вспомогательных функций для работы с геометрией
 *@author Kostyunin Egor, kostyunin.eg@yandex.ru
 *@version 0.1
 *@date 2022
 *@copyright MIT-License
 */
#include "geometry_util.hpp"
#include "point3f.hpp"
#include <cmath>
void calculate_normal(trmesh* mesh){
	for(auto& face_ptr : mesh->faces){
		point3f base_vector0 =  *(mesh->vertexes[face_ptr.second->point2])
								-
								*(mesh->vertexes[face_ptr.second->point1]);

		point3f base_vector1 =  *(mesh->vertexes[face_ptr.second->point3])
								-
								*(mesh->vertexes[face_ptr.second->point1]);

		face_ptr.second->normal = point3f(base_vector0.y*base_vector1.z - base_vector1.y*base_vector0.z,
								  base_vector0.x*base_vector1.z - base_vector1.x*base_vector0.z,
								  base_vector0.x*base_vector1.y - base_vector1.x*base_vector0.y);

		normalize_vector(&face_ptr.second->normal);
		if(abs(face_ptr.second->normal.x) < 0.00001) face_ptr.second->normal.x = 0; 
		if(abs(face_ptr.second->normal.y) < 0.00001) face_ptr.second->normal.y = 0; 
		if(abs(face_ptr.second->normal.z) < 0.00001) face_ptr.second->normal.z = 0; 
	}
}

point3f calculate_vertex_normal(trface* faces,int count){
	point3f normal;
	for(int i = 0;i < count;i++)
		normal += faces[i].normal;
	normal /= count;
	normalize_vector(&normal);
	return normal;
}

float get_vector3f_length(point3f vec){
	return sqrt(vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);	
}

void normalize_vector(point3f* vec){
	float len = get_vector3f_length(*vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}