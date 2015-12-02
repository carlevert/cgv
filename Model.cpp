#include "Model.hpp"



Model::Model()
{
}


Model::~Model()
{
}

void Model::Translate(glm::vec2 translation)
{
	this->translation += translation;
	translation_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(this->translation, 0.0f));
	InvalidateModelMatrix();
}

void Model::RotateX(float angle)
{
	angle = angle / 180.0f * M_PI;
	rotation_x += angle;
	rotation_matrix_x = glm::rotate(identity, rotation_x, x_axis);
	InvalidateModelMatrix();
}

void Model::RotateY(float angle)
{
	angle = angle / 180.0f * M_PI;
	rotation_y += angle;
	rotation_matrix_y = glm::rotate(identity, rotation_y, y_axis);
	InvalidateModelMatrix();
}

void Model::RotateZ(float angle)
{
	angle = angle / 180.0f * M_PI;
	rotation_z += angle;
	rotation_matrix_z = glm::rotate(identity, rotation_z, z_axis);
	InvalidateModelMatrix();
}

void Model::Scale(float scale_factor)
{
	this->scale_factor *= scale_factor;
	scale_matrix = glm::scale(identity, glm::vec3(this->scale_factor));
	InvalidateModelMatrix();
}

glm::mat4 Model::GetModelMatrix()
{
	rotation_matrix = rotation_matrix_x * rotation_matrix_y * rotation_matrix_z;
	model_matrix = translation_matrix * rotation_matrix * scale_matrix;
	return model_matrix;
}

void Model::SetInvalidModelMatrixRef(bool* invalid_model_matrix)
{
	this->invalid_model_matrix = invalid_model_matrix;
}

void Model::InvalidateModelMatrix()
{
	if (invalid_model_matrix != nullptr)
		*invalid_model_matrix = true;
	
}
