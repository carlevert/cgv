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
	glm::mat4 rotation_matrix_u;
	glm::mat4 rotation_matrix_v;
	glm::mat4 rotation_matrix_z = glm::mat4(1.0f);
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

	void SetTranslation(glm::vec3 translation);

	void RotateU(float rotation);
	void RotateV(float rotation);

	glm::mat4 GetViewMatrix();

	void Commit();

//	glm::vec3 GetCameraPosition();
//	void SetCameraPosition(vec3 position);

//	glm::vec3 GetReferencePoint();
//	void SetReferencePoint(vec3 position);

//	glm::vec3 GetUpVector();
//	void SetUpVector(vec3 position);

};
