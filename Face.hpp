#pragma once

#include <iostream>

class Face {
public:
	Face();
	~Face();
	void SetNumVertices(unsigned int num_vertices);
	unsigned int GetNumVertices();
	void SetVertices(unsigned int* vertices);
	unsigned int* GetVertices();
	void Print();
	Face* RemoveEar();

private:
	unsigned int num_vertices;
	unsigned int* vertices;
};

