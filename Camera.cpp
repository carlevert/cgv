#include "Camera.hpp"
#include <string>
#include <iostream>
#define TRACE() cout << __func__ << endl;

using namespace std;

void PrintVector(glm::vec3 v, string s) {
	cout << s << ":" << endl;
	cout << v.x << endl;
	cout << v.y << endl;
	cout << v.z << endl;
}

Camera::Camera() {
	Translate(initial_position);
}

Camera::~Camera() {
}

void Camera::Translate(glm::vec3 translation) {
//	this->translation += glm::transpose(rotation_matrix) * glm::vec4(translation, 0.0f);
//	this->translation_matrix = glm::translate(glm::mat4(1.0f),
//			-1.0f * glm::vec3(this->translation)); //

	glm::mat4 view = GetViewMatrix();

	/*glm::vec3 u = glm::vec3(view[0]);
	glm::vec3 v = glm::vec3(view[1]);
	glm::vec3 n = glm::vec3(view[2]);

	PrintVector(u, "u");
	PrintVector(v, "v");
	PrintVector(n, "n");
	cout << endl;

	translation_matrix = glm::translate(translation_matrix, u * translation.x);
	translation_matrix = glm::translate(translation_matrix, v * translation.y);
	translation_matrix = glm::translate(translation_matrix, n * translation.z);*/

	auto t = glm::transpose(view) * glm::vec4(-translation, 0);
	translation_matrix = glm::translate(translation_matrix, glm::vec3(t));

	InvalidateViewMatrix();
}

glm::vec3 Camera::GetTranslation() {
	return glm::vec3(translation);
}

void Camera::SetTranslation(glm::vec3 translation) {
	this->translation = glm::transpose(rotation_matrix) * glm::vec4(translation, 0.0f);
	this->translation_matrix = glm::translate(glm::mat4(1.0f),
			-1.0f * glm::vec3(this->translation));
	InvalidateViewMatrix();
}

glm::mat4 Camera::GetViewMatrix() {
	glm::mat4 temp_rotation_matrix = rotation_matrix_u * rotation_matrix_v * rotation_matrix;
	return temp_rotation_matrix * translation_matrix;
}

void Camera::Commit() {
	glm::mat4 temp_rotation_matrix = rotation_matrix_u * rotation_matrix_v * rotation_matrix;
	rotation_matrix = temp_rotation_matrix;
	InvalidateViewMatrix();
	rotation_matrix_u = identity;
	rotation_matrix_v = identity;
}

void Camera::SetRotationU(float angle) {
	rotation_matrix_u = glm::rotate(identity, angle, glm::vec3(1,0,0));
	InvalidateViewMatrix();
}

void Camera::SetRotationV(float angle) {
	rotation_matrix_v = glm::rotate(identity, angle, glm::vec3(0,1,0));
	InvalidateViewMatrix();
}

void Camera::InvalidateViewMatrix() {
	if (invalid_view_matrix != nullptr)
		*invalid_view_matrix = true;
}

void Camera::SetInvalidViewMatrixRef(bool* invalid_view_matrix) {
	this->invalid_view_matrix = invalid_view_matrix;
}
