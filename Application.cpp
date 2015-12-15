#include "Application.hpp"

#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

Application::Application()
{
	SetupOpenGl();
	current_object = nullptr;
	program_object = nullptr;
	camera.SetInvalidViewMatrixRef(&invalid_view_matrix);
	projection.SetInvalidProjectionMatrixRef(&invalid_projection_matrix);
	model.SetInvalidModelMatrixRef(&invalid_model_matrix);

}

Application::~Application()
{
	if (current_object != nullptr)
		delete current_object;

	delete program_object;
}

void Application::SetupOpenGl()
{
	// Set graphics attributes
	glLineWidth(2.0);
	glPointSize(2.0);
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glViewport(0, 0, INITIAL_WINDOW_WIDTH, INITIAL_WINDOW_HEIGHT);

	program_object = ProgramObject::CreateFromFiles("VertexShader.glsl", "FragmentShader.glsl");
	program_object->Use();

	// Get some locations
	position_location = program_object->GetAttribLocation("position");

	model_location = program_object->GetUniformLocation("model");
	view_location = program_object->GetUniformLocation("view");
	projection_location = program_object->GetUniformLocation("projection");
	light_pos_location = program_object->GetUniformLocation("light_pos");
	light_intensity_location = program_object->GetUniformLocation("light_intensity");
}

void Application::OpenOffFile(string filename)
{
	if (current_object != nullptr) {
		delete current_object;
		current_object = nullptr;
	}
	if (program_object != nullptr) {
		delete program_object;
		program_object = nullptr;
	}
	current_object = OffParser::ParseOffFile(filename);
	current_object->CalculateNormals();
	current_object->Normalize();
	current_object->Triangulate();
	CreateBuffers();
}

void Application::CreateBuffers()
{
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(2, buffers);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);

	glEnableVertexAttribArray(position_location);
	glVertexAttribPointer(position_location, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// Vertices
	glBufferData(GL_ARRAY_BUFFER, current_object->GetNumVertices() * sizeof(Object::vertex),
			current_object->GetVertices(), GL_STATIC_DRAW);

	// Indicies for triangles
	GLuint* indicies = new GLuint[current_object->GetNumFaces() * 3];
	for (int i = 0; i < current_object->GetNumFaces(); i++) {
		indicies[i * 3 + 0] = current_object->GetFace(i)->GetVertexIndicies()[0];
		indicies[i * 3 + 1] = current_object->GetFace(i)->GetVertexIndicies()[1];
		indicies[i * 3 + 2] = current_object->GetFace(i)->GetVertexIndicies()[2];
	}
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 3 * current_object->GetNumFaces(),
			indicies, GL_STATIC_DRAW);
	delete[] indicies;
}

void Application::Display()
{
	if (invalid_model_matrix)
		UpdateModelMatrix();
	if (invalid_view_matrix)
		UpdateViewMatrix();
	if (invalid_projection_matrix)
		UpdateProjectionMatrix();
	if (invalid_light_properties)
		UpdateLightProperties();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (current_object != nullptr) {
		glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
		glDrawElements(GL_TRIANGLES, current_object->GetNumFaces() * 3, GL_UNSIGNED_INT, (GLvoid*) 0);
	}
	glFlush();
}

void Application::UpdateModelMatrix()
{
	const float* model_matrix = glm::value_ptr(model.GetModelMatrix());
	glUniformMatrix4fv(model_location, 1, GL_FALSE, model_matrix);
	invalid_model_matrix = false;
	// PrintMatrix(model.GetModelMatrix(), "model:");

}
void Application::UpdateViewMatrix()
{
	const float* view_matrix = glm::value_ptr(camera.GetViewMatrix());
	glUniformMatrix4fv(view_location, 1, GL_FALSE, view_matrix);
	invalid_view_matrix = false;
	// PrintMatrix(camera.GetViewMatrix(), "view:");
}

void Application::UpdateProjectionMatrix()
{
	const float* projection_matrix = glm::value_ptr(projection.GetProjectionMatrix());
	glUniformMatrix4fv(projection_location, 1, GL_FALSE, projection_matrix);
	invalid_projection_matrix = false;
	// PrintMatrix(projection.GetProjectionMatrix(), "projection:");
}

void Application::UpdateLightProperties()
{
	const float* intensity = light.GetIntensity();
	const float* position = light.GetPosition();
	glUniform3fv(light_intensity_location, 1, intensity);
	glUniform3fv(light_pos_location, 1, position);
	invalid_light_properties = false;
}

void Application::SetViewportSize(int width, int height)
{
	projection.SetViewportDimensions(width, height);
	glViewport(0, 0, width, height);
}

Model* Application::GetModel()
{
	return &model;
}

Camera* Application::GetCamera()
{
	return &camera;
}

Projection* Application::GetProjection()
{
	return &projection;
}

Light* Application::GetLight()
{
	return &light;
}

Object* Application::GetObject() {
	return current_object;
}
