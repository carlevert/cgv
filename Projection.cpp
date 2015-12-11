#include "Projection.hpp"
#include "Application.hpp"

Projection::Projection()
{
	SetFovDegrees(80.0f);
	SetViewportDimensions(Application::INITIAL_WINDOW_WIDTH, Application::INITIAL_WINDOW_HEIGHT);
	SetTop(1.0f);
	SetProjectionType(ProjectionType::PERSPECTIVE);
	SetObliqueAngleDegrees(45.0f);
	SetObliqueScale(0.0f);
}

Projection::~Projection()
{
}

void Projection::UpdateHMatrix()
{

	h_matrix[2].x = oblique_scale * cos(oblique_angle);
	h_matrix[2].y = oblique_scale * sin(oblique_angle);
	if (projection_type == ProjectionType::PARALLEL)
		SetInvalidProjectionMatrix();
}

void Projection::SetInvalidProjectionMatrix()
{
	if (invalid_projection_matrix != nullptr)
		*invalid_projection_matrix = true;
}

float Projection::GetFov()
{
	return fov;
}

float Projection::GetFovDegrees()
{
	return fov_degrees;
}

void Projection::SetFov(float fov)
{
	this->fov_degrees = fov * 180.0f / (float)M_PI;
	this->fov = fov;
	if (projection_type == ProjectionType::PERSPECTIVE)
		SetInvalidProjectionMatrix();
}

void Projection::SetFovDegrees(float fov_degrees)
{
	this->fov_degrees = fov_degrees;
	this->fov = fov_degrees / 180.0f * (float)M_PI;
	SetFov(this->fov);
}

void Projection::SetZNear(float z_near)
{
	this->z_near = z_near;
	SetInvalidProjectionMatrix();
}

float Projection::GetZFar()
{
	return z_far;
}

void Projection::SetZFar(float z_far)
{
	this->z_far = z_far;
	SetInvalidProjectionMatrix();
}


float Projection::GetTop()
{
	return top;
}
void Projection::SetTop(float top)
{
	this->top = top;
	bottom = -top;
	left = top * aspect_ratio * -1.0f;
	right = top * aspect_ratio;
	SetInvalidProjectionMatrix();
}

void Projection::SetObliqueScale(float oblique_scale)
{
	if (oblique_scale < OBLIQUE_SCALE_MIN || oblique_scale > OBLIQUE_SCALE_MAX)
		return;
	this->oblique_scale = oblique_scale;
	UpdateHMatrix();
}

float Projection::GetObliqueScale()
{
	return oblique_scale;
}

void Projection::SetObliqueAngle(float oblique_angle)
{
	float angle_degrees = oblique_angle * 180.0f / (float)M_PI;
	if (angle_degrees < OBLIQUE_ANGLE_DEG_MIN || angle_degrees > OBLIQUE_ANGLE_DEG_MAX)
		return;
	this->oblique_angle = oblique_angle;
	UpdateHMatrix();
}

void Projection::SetObliqueAngleDegrees(float oblique_angle_degrees)
{
	SetObliqueAngle(oblique_angle_degrees / 180.0f * (float)M_PI);
}

float Projection::GetObliqueAngleDegrees()
{
	return oblique_angle * 180.0f / (float)M_PI;
}


void Projection::SetProjectionType(ProjectionType projection_type)
{
	this->projection_type = projection_type;
	SetInvalidProjectionMatrix();
}

ProjectionType Projection::GetProjectionType()
{
	return this->projection_type;
}

void Projection::SetViewportDimensions(int width, int height)
{
	viewport_width = width;
	viewport_height = height;
	aspect_ratio = (float)width / height;
	SetInvalidProjectionMatrix();
}

void Projection::SetInvalidProjectionMatrixRef(bool* invalid_projection_matrix)
{
	this->invalid_projection_matrix = invalid_projection_matrix;
}

glm::mat4 Projection::GetProjectionMatrix()
{
	if (projection_type == ProjectionType::PERSPECTIVE) {
		projection_matrix = glm::perspective(fov, aspect_ratio, z_near, z_far);
	}
	else {
		st_matrix = glm::ortho(left, right, bottom, top, z_near, z_far);
		projection_matrix = st_matrix * h_matrix;

		//glm::mat4 st_matrix = glm::mat4(1.0f);
		//st_matrix[0].x = 2.0f / (right - left);
		//st_matrix[1].y = 2.0f / (top - bottom);
		//st_matrix[2].z = -2.0f / (z_far - z_near);
		//st_matrix[3].x = -1.0f * (left + right) / (right - left);
		//st_matrix[3].y = -1.0f * (top + bottom) / (top - bottom);
		//st_matrix[3].z = -1.0f * (z_far + z_near) / (z_far - z_near);
	}
	return projection_matrix;
}
