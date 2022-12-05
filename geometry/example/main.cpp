#include <iostream>
#include "../geometry.hpp"
using namespace std;

int main(){
	//Создание полигональной сетки
	trmesh mesh;
	
	//Добавление вершин в сетку
	mesh.vertexes[1] = new point3f(0,0,0);
	mesh.vertexes[2] = new point3f(1,0,0);
	mesh.vertexes[3] = new point3f(0,1,0);
	mesh.vertexes[4] = new point3f(1,0,0);
	
	//Добавление полигонов в сетку
	mesh.faces[1] = new trface(1,2,3);
	mesh.faces[2] = new trface(2,4,3);
	
	//Изменение вершин сетки
	delete mesh.vertexes[4];
	mesh.vertexes[4] = new point3f(1,1,0);
	
	//Изменение полигонов сетки
	delete mesh.faces[2]; 
	mesh.faces[2] = new trface(2,3,4);
	
	//Создание трехмерного объекта
	mesh_object obj1(point3f(0,0,0),0);
	
	//Установка полигональной сетки объекта
	obj1.set_mesh(mesh);
	
	//Получение видимой сетки объекта
	trmesh* visible = obj1.get_visible_mesh(point3f(0,0,1));
	
	//Удаление полигона из сетки
	visible->faces[1] = new trface(visible->faces[1]->point1,
								   visible->faces[1]->point1,
								   visible->faces[1]->point1);
	
	//Изменение существующей сетки объекта
	obj1.set_mesh_part(*visible);
	
	//Вывод информации об объекте
	cout<<obj1<<endl;
	
	return 0;
}