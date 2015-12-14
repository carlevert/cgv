#pragma once

#include <cmath>
#include <iomanip>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ProgramObject.hpp"
#include "Object.hpp"
#include "OffParser.hpp"
#include "Projection.hpp"
#include "Camera.hpp"
#include "Model.hpp"
#include "Light.hpp"

class Application {
private:
	// OpenGL stuff
	GLuint buffers[2];
	GLuint model_location;
	GLuint view_location;
	GLuint projection_location;

	GLuint light_pos_location;
	GLuint light_intensity_location;

	GLuint position_location;

	ProgramObject* program_object;

	Object* current_object;

	Camera camera;
	Projection projection;
	Model model;
	Light light;

	bool invalid_view_matrix = true;
	bool invalid_model_matrix = true;
	bool invalid_projection_matrix = true;
	bool invalid_light_properties = true;

	void UpdateModelMatrix();
	void UpdateProjectionMatrix();
	void UpdateViewMatrix();
	void UpdateLightProperties();

	void SetupOpenGl();
	void CreateBuffers();
public:
	static const unsigned int INITIAL_WINDOW_WIDTH = 640;
	static const unsigned int INITIAL_WINDOW_HEIGHT = 480;
	Application();
	~Application();
	void Display();
	void OpenOffFile(string filename);
	void SetViewportSize(int width, int height);

	Model* GetModel();
	Camera* GetCamera();
	Projection* GetProjection();
	Light* GetLight();
};

