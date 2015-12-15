#pragma once

#include <vector>
#include <iostream>
#include <cstring>

#include <iomanip>
#include "Face.hpp"
#include <glm/glm.hpp>

using namespace std;

class Object {

public:
	typedef struct vertex {
		float x;
		float y;
		float z;
	} vertex;

	Object();
	~Object();

	static const int DIM = 3;

	int GetNumVertices();
	void SetNumVertices(int num_vertices);

	int GetNumFaces();
	void SetNumFaces(int num_faces);

	int GetNumEdges();
	void SetNumEdges(int num_edges);

	vertex* GetVertices();
	void AddVertex(float* vertex);

	Face* GetFace(int i);
	void AddFace(Face* face);

	void CalculateNormals();
	void Normalize();
	void Triangulate();
	void Print();
	void ToggleFlipNormals();
private:
	int num_vertices = 0;
	int num_faces = 0;
	int num_edges = 0;

	int vertex_cursor = 0;
	vertex* vertices;
	float* normals = nullptr;

	std::vector<Face*> faces;

};
