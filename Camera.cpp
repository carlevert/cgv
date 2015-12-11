#include "Camera.hpp"

#define TRACE() cout << __func__ << endl;

using namespace std;

Camera::Camera() {
	Translate(initial_position);
}

Camera::~Camera() {
}

void Camera::Translate(glm::vec3 translation) {
	glm::mat4 view = GetViewMatrix();
	auto t = glm::transpose(view) * glm::vec4(-translation, 0);
	translation_matrix = glm::translate(translation_matrix, glm::vec3(t));
	InvalidateViewMatrix();
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

void Camera::RotateU(float angle) {
	rotation_matrix_u = glm::rotate(identity, angle, glm::vec3(1,0,0));
	InvalidateViewMatrix();
}

void Camera::RotateV(float angle) {
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
