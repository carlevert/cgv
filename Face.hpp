#pragma once

#include <iostream>

class Face {
public:
	Face();
	~Face();
	void SetNumVertices(unsigned int num_vertices);
	unsigned int GetNumVertices() const;
	void SetVertices(unsigned int* vertices);
	unsigned int* GetVertices() const;
	void Print() const;
	Face* RemoveEar();

private:
	unsigned int num_vertices;
	unsigned int* vertices;
};

