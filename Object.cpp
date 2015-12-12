#include "Object.hpp"


#include "PrintMatrix.hpp"

Object::Object() {
	vertices = nullptr;
	vertex_cursor = 0;
}

Object::~Object() {
}

int Object::GetNumVertices() {
	return this->num_vertices;
}

void Object::SetNumVertices(int num_vertices) {
	if (vertices != nullptr)
		delete vertices;
	this->num_vertices = num_vertices;
	vertices = new vertex[num_vertices];
	normals = new float[num_vertices * 3];
	memset(normals, 0, num_vertices * 3 * sizeof(float));
}

Object::vertex* Object::GetVertices() {
	return vertices;
}

int Object::GetNumFaces() {
	return faces.size();
}

void Object::SetNumFaces(int num_faces) {
}

int Object::GetNumEdges() {
	return this->num_edges;
}

void Object::SetNumEdges(int num_edges) {
	this->num_edges = num_edges;
}

void Object::AddVertex(float* vertex) {
	vertices[vertex_cursor].x = vertex[0];
	vertices[vertex_cursor].y = vertex[1];
	vertices[vertex_cursor].z = vertex[2];
	vertex_cursor++;
}

void Object::AddFace(Face* face) {
	faces.push_back(face);
	num_faces++;
}

Face* Object::GetFace(int i) {
	return faces.at(i);
}

void Object::CalculateNormals() {
	for (Face* face : faces) {

		unsigned int* vertex_indicies = face->GetVertexIndicies();
		unsigned int index;

		index = *(vertex_indicies + 0);
		glm::vec3 v0 = glm::vec3();
		v0.x = vertices[index].x;
		v0.y = vertices[index].y;
		v0.z = vertices[index].z;

		index = *(vertex_indicies + 1);
		glm::vec3 v1 = glm::vec3();
		v1.x = vertices[index].x;
		v1.y = vertices[index].y;
		v1.z = vertices[index].z;

		index = *(vertex_indicies + 2);
		glm::vec3 v2 = glm::vec3();
		v2.x = vertices[index].x;
		v2.y = vertices[index].y;
		v2.z = vertices[index].z;

		PrintVector(v0, "v0");
		PrintVector(v1, "v1");
		PrintVector(v2, "v2");

		v1 = v1 - v0;
		v2 = v2 - v0;

		glm::vec3 normal = glm::normalize(glm::cross(v1, v2));

		PrintVector(normal,"cross");

		cout << "--------------"  << endl;



		for (int i = 0; i < face->GetNumVertices(); i++) {
			int idx = *(vertex_indicies + i);
			normals[idx * 3 + 0] += normal.x;
			normals[idx * 3 + 1] += normal.y;
			normals[idx * 3 + 2] += normal.z;

		}
	}

	for (int i = 0; i < GetNumVertices(); i++) {
		float sum_of_squares = 0.0f;
		for (int j = 0; j < 3; j++)
			sum_of_squares += normals[i * 3 + j] * normals[i * 3 + j] ;
		float norm = sqrtf(sum_of_squares);
		for (int j = 0; j < 3; j++)
			normals[i * 3 + j] /= norm;
	}



	for (int i = 0; i < GetNumVertices(); i++) {
		for (int j = 0; j < 3; j++)
			cout << normals[i * 3 + j] << "  ";
		cout << endl<< endl;
	}

}

void Object::Print() {
	std::cout << "OFF" << std::endl;
	std::cout << num_vertices << " " << num_faces << " " << num_edges << std::endl;
	for (int i = 0; i < num_vertices; i++) {
		std::cout << std::fixed << std::setw(4) << i + 1 << ": ";
		std::cout << std::fixed << std::setw(7) << std::setprecision(4) << vertices[i].x;
		std::cout << std::fixed << std::setw(7) << std::setprecision(4) << vertices[i].y;
		std::cout << std::fixed << std::setw(7) << std::setprecision(4) << vertices[i].z
				<< std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < faces.size(); i++) {
		std::cout << std::fixed << std::setw(4) << i + 1 << ": ";
		faces.at(i)->Print();
	}
}

void Object::Normalize() {
	float min_x = 0.0;
	float max_x = 0.0;

	float min_y = 0.0;
	float max_y = 0.0;

	float min_z = 0.0;
	float max_z = 0.0;

	vertex* vertex;

	min_x = max_x = vertices->x;
	min_y = max_y = vertices->y;
	min_z = max_z = vertices->z;

	for (int i = 1; i < num_vertices; i++) {
		vertex = &vertices[i];

		if (vertex->x < min_x)
			min_x = vertex->x;
		else if (vertex->x > max_x)
			max_x = vertex->x;

		if (vertex->y < min_y)
			min_y = vertex->y;
		else if (vertex->y > max_y)
			max_y = vertex->y;

		if (vertex->z < min_z)
			min_z = vertex->z;
		else if (vertex->x > max_z)
			max_z = vertex->z;
	}

	float size_x = max_x - min_x;
	float size_y = max_y - min_y;
	float size_z = max_z - min_z;

	float size_max = size_x;
	if (size_y > size_max)
		size_max = size_y;
	if (size_z > size_max)
		size_max = size_z;

	for (int i = 0; i < num_vertices; i++) {
		vertex = &vertices[i];
		vertex->x = ((vertex->x - min_x) - size_x / 2) / size_max;
		vertex->y = ((vertex->y - min_y) - size_y / 2) / size_max;
		vertex->z = ((vertex->z - min_z) - size_z / 2) / size_max;
	}
}

void Object::Triangulate() {

	for (int i = 0; i < num_faces; i++) {
		Face* face = faces[i];
		while (face->GetNumVertices() > 3) {
			Face* removed_face = face->RemoveEar();
			removed_face->Print();
			AddFace(removed_face);
		}
		face->Print();
	}
}
