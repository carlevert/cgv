#pragma once


#define _USE_MATH_DEFINES
#include <cmath>
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

class Camera {
private:
	glm::mat4 identity = glm::mat4(1.0f);
	glm::vec3 x_axis = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 y_axis = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 z_axis = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::mat4 rotation_matrix_x;
	glm::mat4 rotation_matrix_y;
	glm::mat4 rotation_matrix_z;
	float rotation_x = 0.0f;
	float rotation_y = 0.0f;;
	float rotation_z = 0.0f;;
	glm::vec4 translation = glm::vec4(0.0f);

	glm::mat4 translation_matrix = glm::mat4(1.0f);
	glm::mat4 rotation_matrix = glm::mat4(1.0f);

	glm::vec3 initial_position = glm::vec3(0.0f, 0.0f, 2.0f);

	void InvalidateViewMatrix();
	bool* invalid_view_matrix = nullptr;

public:
	Camera();
	~Camera();
	void SetInvalidViewMatrixRef(bool* invalid_view_matrix);


	void Translate(glm::vec3 translation);
	glm::vec3 GetTranslation();
	void SetTranslation(glm::vec3 translation);

	float GetRotationX();
	void SetRotationX(float rotation_x);

	float GetRotationY();
	void SetRotationY(float rotation_y);
	void SetRotationZ(float rotation_z);
	void RotateZ(int direction);

	glm::mat4 GetViewMatrix();

//	glm::vec3 GetCameraPosition();
//	void SetCameraPosition(vec3 position);

//	glm::vec3 GetReferencePoint();
//	void SetReferencePoint(vec3 position);

//	glm::vec3 GetUpVector();
//	void SetUpVector(vec3 position);

};