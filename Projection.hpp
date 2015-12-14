#pragma once

#define _USE_MATH_DEFINES
#include <stdexcept>
#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum ProjectionType { PARALLEL, PERSPECTIVE };

class Projection
{
public:
	Projection();
	~Projection();

	static constexpr float OBLIQUE_ANGLE_DEG_MIN = 15.0f;
	static constexpr float OBLIQUE_ANGLE_DEG_MAX = 75.0f;
	static constexpr float OBLIQUE_SCALE_MIN = 0.0f;
	static constexpr float OBLIQUE_SCALE_MAX = 1.0f;

	float GetFov();
	void SetFov(float fov);
	float GetFovDegrees();
	void SetFovDegrees(float fov);
	void SetZNear(float z_near);
	float GetZFar();
	void SetZFar(float z_far);
	float GetTop();
	void SetTop(float top);

	float GetObliqueScale();
	void SetObliqueScale(float oblique_scale);

	void SetObliqueAngle(float oblique_angle);
	float GetObliqueAngleDegrees();
	void SetObliqueAngleDegrees(float oblique_angle_degrees);

	void SetProjectionType(ProjectionType type);
	ProjectionType GetProjectionType();

	void SetViewportDimensions(int width, int height);
	void SetInvalidProjectionMatrixRef(bool* invalid_projection_matrix);
	glm::mat4 GetProjectionMatrix();
private:
	void UpdateHMatrix();
	ProjectionType projection_type;
	bool* invalid_projection_matrix = nullptr;
	glm::mat4 h_matrix;
	glm::mat4 st_matrix;
	glm::mat4 perspective_matrix;
	glm::mat4 projection_matrix;
	float fov;
	float fov_degrees;
	float z_near = 0.1f;
	float z_far = 10.0f;
	float top, left, right, bottom;
	float oblique_angle;
	float oblique_scale;
	float aspect_ratio;

	int viewport_width, viewport_height;
	void SetInvalidProjectionMatrix();
};
