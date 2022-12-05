/**@file mesh_object.cpp - этот файл содержит реализацию класса трехмеронго объекта mesh_object
 *@author Kostyunin Egor, kostyunin.eg@yandex.ru
 *@version 0.1
 *@date 2022
 *@copyright MIT-License
 */
#include "geometry_util.hpp"
mesh_object::mesh_object(point3f _pos,int _type){
	pos = _pos;
	type = _type;
}

trmesh mesh_object::get_mesh(){
	return mesh;
}

point3f mesh_object::get_pos(){
	return pos;
}

void mesh_object::set_mesh(trmesh _mesh){
	mesh = _mesh;
	calculate_normal(&mesh);
}

void mesh_object::set_pos(point3f _pos){
	pos = _pos;
}

void mesh_object::set_mesh_part(trmesh _mesh){
	for(auto& face :_mesh.faces)
		mesh.faces[face.first] = face.second;
	for(auto face = mesh.faces.begin();face != mesh.faces.end();)
		if(face->second->point1 == face->second->point2 ||
		   face->second->point2 == face->second->point3 ||
		   face->second->point1 == face->second->point3){
			   delete mesh.faces[(*face).first];
			   mesh.faces.erase(face++);
		   }
		else
			++face;	   
	for(auto& v :_mesh.vertexes)
		if(has_incedent_faces(v.first))
			mesh.vertexes[v.first] = v.second;
	for(auto v = mesh.vertexes.begin();v != mesh.vertexes.end();)
		if(!has_incedent_faces((*v).first) &&
			mesh.vertexes.find((*v).first) != mesh.vertexes.end()){
			delete mesh.vertexes[(*v).first];
			mesh.vertexes.erase(v++);
		}
		else
			++v;
	calculate_normal(&mesh);
}

bool mesh_object::has_incedent_faces(int index){
	bool flag = false;
	for(const auto& face : mesh.faces){
		if(face.second->point1 == index||
		   face.second->point2 == index||
		   face.second->point3 == index){
			   flag = true;
			   break;
		   }
	}
	return flag;
}

trmesh* mesh_object::get_visible_mesh(point3f camera_pos){
	point3f direction = pos - camera_pos;
	trmesh* visible = new trmesh;
	for(auto& face : mesh.faces){
		float c = face.second->normal.cos(direction);
		if(c < 0 && -1 >= c){
			visible->faces[face.first] = face.second;
			visible->vertexes[face.second->point1] = mesh.vertexes[face.second->point1];
			visible->vertexes[face.second->point2] = mesh.vertexes[face.second->point2];
			visible->vertexes[face.second->point3] = mesh.vertexes[face.second->point3];
		}
	}
	return visible;
}

std::ostream& operator<< (std::ostream& out,mesh_object mobj){
		out<<"mesh_object:"<<endl;
		out<<"pos:"<<mobj.pos<<endl;
		out<<"type:"<<mobj.type<<endl;
		for(const auto& v : mobj.mesh.vertexes)
			out<<"v"<<v.first<<": "<<*v.second<<endl;
		for(auto& face : mobj.mesh.faces)
			out<<face.first<<*face.second<<endl;
		return out;
}