#pragma once

#include <vector>
#include <iostream>

#include <iomanip>
#include "Face.hpp"

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

	void Normalize();
	void Triangulate();
	void Print();
private:
	int num_vertices;
	int num_faces;
	int num_edges;

	int vertex_cursor;
	int face_cursor;

	vertex* vertices;

	std::vector<Face*> faces;

};