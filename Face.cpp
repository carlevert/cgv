#include "Face.hpp"

Face::Face()
{
	vertex_indicies = nullptr;
	num_vertex_indicies = 0;
}

Face::~Face()
{
	delete[] vertex_indicies;
}

void Face::SetNumVertices(unsigned int num_vertices)
{

	this->num_vertex_indicies = num_vertices;
	if (vertex_indicies != nullptr)
		delete[] vertex_indicies;
	vertex_indicies = new unsigned int[num_vertices];
}

unsigned int Face::GetNumVertices() const
{
	return  num_vertex_indicies;
}

void Face::SetVertexIndicies(unsigned int* vertices)
{
	this->vertex_indicies = vertices;
}

unsigned int* Face::GetVertexIndicies() const
{
	return vertex_indicies;
}

Face* Face::RemoveEar()
{
	unsigned int* new_vertices = new unsigned int[3];
	new_vertices[0] = vertex_indicies[0];
	new_vertices[1] = vertex_indicies[1];
	new_vertices[2] = vertex_indicies[2];

	Face* new_face = new Face();
	new_face->SetNumVertices(3);
	new_face->SetVertexIndicies(new_vertices);

	unsigned int* tmp_vertices = new unsigned int[num_vertex_indicies - 1];
	tmp_vertices[0] = vertex_indicies[0];
	tmp_vertices[1] = vertex_indicies[2];
	for (int i = 3; i < num_vertex_indicies; i++)
		tmp_vertices[i - 1] = vertex_indicies[i];

	num_vertex_indicies--;
	vertex_indicies = tmp_vertices;

	return new_face;
}

void Face::Print() const
{
	for (unsigned int i = 0; i < num_vertex_indicies; i++)
		std::cout << vertex_indicies[i] << " ";
	std::cout << "(" << num_vertex_indicies << ")" << std::endl;
}
