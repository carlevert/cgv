#pragma once

#include <iostream>

class Face {
public:
	Face();
	~Face();
	void SetNumVertices(unsigned int num_vertices);
	unsigned int GetNumVertices() const;
	void SetVertexIndicies(unsigned int* vertices);
	unsigned int* GetVertexIndicies() const;
	void Print() const;
	Face* RemoveEar();
	float* GetNormal() const;

private:
	unsigned int num_vertex_indicies;
	unsigned int* vertex_indicies;
};

