#include "Face.hpp"

Face::Face()
{
	vertices = nullptr;
	num_vertices = 0;
}

Face::~Face()
{
	delete[] vertices;
}

void Face::SetNumVertices(unsigned int num_vertices)
{
	this->num_vertices = num_vertices;
	if (vertices != nullptr)
		delete[] vertices;
	vertices = new unsigned int[num_vertices];
}

unsigned int Face::GetNumVertices() const
{
	return num_vertices;
}

void Face::SetVertices(unsigned int* vertices)
{
	this->vertices = vertices;
}

unsigned int* Face::GetVertices() const
{
	return vertices;
}

Face* Face::RemoveEar()
{
	unsigned int* new_vertices = new unsigned int[3];
	new_vertices[0] = vertices[0];
	new_vertices[1] = vertices[1];
	new_vertices[2] = vertices[2];

	Face* new_face = new Face();
	new_face->SetNumVertices(3);
	new_face->SetVertices(new_vertices);

	unsigned int* tmp_vertices = new unsigned int[num_vertices - 1];
	tmp_vertices[0] = vertices[0];
	tmp_vertices[1] = vertices[2];
	for (int i = 3; i < num_vertices; i++)
		tmp_vertices[i - 1] = vertices[i];

	num_vertices--;
	vertices = tmp_vertices;

	return new_face;
}

void Face::Print() const
{
	for (unsigned int i = 0; i < num_vertices; i++)
		std::cout << vertices[i] << " ";
	std::cout << "(" << num_vertices << ")" << std::endl;
}
