#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Model
{
public:
	Model();
	~Model();
	void Translate(glm::vec2 translation);
	void RotateX(float angle);
	void RotateY(float angle);
	void RotateZ(float angle);
	void Scale(float scale_factor);
	glm::mat4 GetModelMatrix();
	void SetInvalidModelMatrixRef(bool* invalid_view_matrix);
private:
	glm::mat4 identity = glm::mat4(1.0f);
	glm::vec3 x_axis = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 y_axis = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 z_axis = glm::vec3(0.0f, 0.0f, 1.0f);

	glm::mat4 model_matrix = glm::mat4(1.0f);
	glm::mat4 translation_matrix = glm::mat4(1.0f);
	glm::mat4 rotation_matrix = glm::mat4(1.0f);
	glm::mat4 scale_matrix = glm::mat4(1.0f);

	glm::mat4 rotation_matrix_x = glm::mat4(1.0f);
	glm::mat4 rotation_matrix_y = glm::mat4(1.0f);
	glm::mat4 rotation_matrix_z = glm::mat4(1.0f);
	float rotation_x = 0.0f;
	float rotation_y = 0.0f;
	float rotation_z = 0.0f;
	float scale_factor = 1.0f;
	glm::vec2 translation = glm::vec2(0.0f);

	void InvalidateModelMatrix();
	bool* invalid_model_matrix = nullptr;
};