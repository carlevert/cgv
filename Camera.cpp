#include "Camera.hpp"

#define TRACE() cout << __func__ << endl;

void Camera::InvalidateViewMatrix()
{
	if (invalid_view_matrix != nullptr)
		*invalid_view_matrix = true;
}

Camera::Camera()
{
	Translate(initial_position);
}

Camera::~Camera()
{
}

void Camera::Translate(glm::vec3 translation)
{
	this->translation += glm::transpose(rotation_matrix) * glm::vec4(translation, 0.0f);
	this->translation_matrix = glm::translate(glm::mat4(1.0f), -1.0f *glm::vec3(this->translation));
	InvalidateViewMatrix();
}

glm::vec3 Camera::GetTranslation()
{
	return glm::vec3(translation);
}

void Camera::SetTranslation(glm::vec3 translation) {
	this->translation = glm::transpose(rotation_matrix) * glm::vec4(translation, 0.0f);
	this->translation_matrix = glm::translate(glm::mat4(1.0f), -1.0f * glm::vec3(this->translation));
	InvalidateViewMatrix();
}

glm::mat4 Camera::GetViewMatrix()
{
	glm::mat4 temp_rotation_matrix = rotation_matrix_x * rotation_matrix_y * rotation_matrix_z * rotation_matrix;
	return temp_rotation_matrix * translation_matrix;
}

void Camera::Commit() {
	rotation_matrix = rotation_matrix_x * rotation_matrix_y * rotation_matrix_z * rotation_matrix;
}

float Camera::GetRotationX()
{
	return rotation_x;
}

glm::vec3 Camera::GetXAxis()
{
	return glm::vec3(GetViewMatrix()[0]);
}

glm::vec3 Camera::GetYAxis()
{
	return glm::vec3(GetViewMatrix()[1]);
}

float Camera::GetRotationY()
{
	return rotation_y;
}

void Camera::SetRotationX(float rotation, glm::vec3 x_axis)
{
	rotation_x = rotation;
	rotation_matrix_x = glm::rotate(identity, rotation_x, x_axis);
	InvalidateViewMatrix();
}

void Camera::SetRotationY(float rotation, glm::vec3 x_axis)
{
	rotation_y = rotation;
	rotation_matrix_y = glm::rotate(identity, rotation_y, y_axis);
	InvalidateViewMatrix();
}

void Camera::SetRotationZ(float rotation)
{
	rotation_z = rotation;
	rotation_matrix_z = glm::rotate(identity, rotation_z, z_axis);
	InvalidateViewMatrix();
}

void Camera::RotateZ(int direction) {
	if (direction == 1)
		rotation_z += 0.1f;
	else
		rotation_z -= 0.1f;
	rotation_matrix_z = glm::rotate(identity, rotation_z, z_axis);
	rotation_matrix = rotation_matrix_x * rotation_matrix_y * rotation_matrix_z;
	InvalidateViewMatrix();
}

void Camera::SetInvalidViewMatrixRef(bool* invalid_view_matrix)
{
	this->invalid_view_matrix = invalid_view_matrix;
}