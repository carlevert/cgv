#include "Object.hpp"

Object::Object()
{
  num_vertices = 0;
  num_edges = 0;
  num_faces = 0;
  vertices = nullptr;
  vertex_cursor = 0;
  face_cursor = 0;
}

Object::~Object()
{
}

int Object::GetNumVertices()
{
  return this->num_vertices;
}

void Object::SetNumVertices(int num_vertices)
{
  if (vertices != nullptr)
    delete vertices;
  this->num_vertices = num_vertices;
  vertices = new vertex[num_vertices];
}

Object::vertex* Object::GetVertices()
{
  return vertices;
}

int Object::GetNumFaces()
{
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

void Object::Print() {
  std::cout << "OFF" << std::endl;
  std::cout << num_vertices << " " << num_faces << " " << num_edges << std::endl;
  for (int i = 0; i < num_vertices; i++) {
    std::cout << std::fixed << std::setw(4) << i + 1 << ": ";
    std::cout << std::fixed << std::setw(7) << std::setprecision(4)
	      << vertices[i].x;
    std::cout << std::fixed << std::setw(7) << std::setprecision(4)
	      << vertices[i].y;
    std::cout << std::fixed << std::setw(7) << std::setprecision(4)
	      << vertices[i].z << std::endl;
  }
  std::cout << std::endl;
  for (int i = 0; i < faces.size(); i++) {
    std::cout << std::fixed << std::setw(4) << i + 1 << ": ";
    faces.at(i)->Print();
  }
}

void Object::Normalize()
{
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

void Object::Triangulate()
{

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
