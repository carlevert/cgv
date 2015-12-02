#include "main.hpp"

float scale = 0.005f;
bool rotating_camera_x_y = false;
double start_x, start_y, end_x, end_y;
float start_rot_x, start_rot_y;

int main(int argc, char** argv) {

	GLFWwindow* window = SetupGlfw();

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "glewInit() failed" << std::endl;
	}

	application = new Application();
	app = (void*)application;



#ifdef __unix__
	guiInit(&argc, argv);
	initGuiWindow("ass2gui.glade");

	Projection* projection = application->GetProjection();

	gui_set_option_far(projection->GetZFar());
	gui_set_option_top(projection->GetTop());
	gui_set_option_oblique_angle(projection->GetObliqueAngleDegrees());
	gui_set_option_oblique_scale(projection->GetObliqueScale());
	if (projection->GetProjectionType() == ProjectionType::PERSPECTIVE)
		gui_set_projection_perspective();
	else
		gui_set_projection_parallel();
	gui_set_option_fov(projection->GetFovDegrees());
#endif // __unix__

#ifndef __unix__
	application->OpenOffFile("off/cube.off");
#endif


	while (!glfwWindowShouldClose(window)) {
		if (rotating_camera_x_y) {
			glfwGetCursorPos(window, &end_x, &end_y);
			float dx = (float)(end_x - start_x);
			float dy = (float)(end_y - start_y);
			application->GetCamera()->SetRotationX(start_rot_x + dy * scale);
			application->GetCamera()->SetRotationY(start_rot_y + dx * scale);
		}
		application->Display();
		glfwSwapBuffers(window);
		glfwPollEvents();
#ifdef __unix__
		guiMainIteration();
#endif // __unix__
	}

	delete application;

	return 0;
}

GLFWwindow* SetupGlfw()
{
	if (!glfwInit()) {
		std::cerr << "Could not initialize GLFW" << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(Application::INITIAL_WINDOW_WIDTH,
		Application::INITIAL_WINDOW_HEIGHT, "Assignment 2", NULL, NULL);

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(GlfwErrorCallback);
	glfwSetMouseButtonCallback(window, GlfwMouseButtonCallback);
	glfwSetKeyCallback(window, GlfwKeyCallback);
	glfwSetWindowCloseCallback(window, GlfwWindowCloseCallback);
	glfwSetFramebufferSizeCallback(window, GlfwFramebufferSizeCallback);
	glfwSetScrollCallback(window, GlfwScrollCallback);
	return window;
}

void GlfwErrorCallback(int error, const char* description)
{
	cerr << error << ": " << description << endl;
}

void GlfwWindowCloseCallback(GLFWwindow* window)
{
	glfwSetWindowShouldClose(window, GL_TRUE);
}

void GlfwFramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	application->SetViewportSize(width, height);
}

void GlfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	Camera* camera = application->GetCamera();
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		if (action == GLFW_PRESS) {
			glfwGetCursorPos(window, &start_x, &start_y);
			end_x = start_x;
			end_y = start_y;
			rotating_camera_x_y = true;
			start_rot_x = camera->GetRotationX();
			start_rot_y = camera->GetRotationY();
		}
		else if (action == GLFW_RELEASE) {
			rotating_camera_x_y = false;
		}
	}
}

void GlfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	application->GetCamera()->RotateZ((int)yoffset);
}

void GlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	float delta = 0.1f;
	float angle = 10.0f;

	Model* model = application->GetModel();
	Camera* camera = application->GetCamera();
	Projection* projection = application->GetProjection();

	if (action != GLFW_PRESS)
		return;

	switch (key) {

		// Model transformations
	case GLFW_KEY_LEFT:
		model->RotateY(-10.0f);
		break;
	case GLFW_KEY_RIGHT:
		model->RotateY(10.0f);
		break;
	case GLFW_KEY_UP:
		model->RotateX(-10.0f);
		break;
	case GLFW_KEY_DOWN:
		model->RotateX(10.0f);
		break;
	case GLFW_KEY_J:
		model->Translate(glm::vec2(-delta, 0.0f));
		break;
	case GLFW_KEY_L:
		model->Translate(glm::vec2(delta, 0.0f));
		break;
	case GLFW_KEY_I:
		model->Translate(glm::vec2(0.0f, delta));
		break;
	case GLFW_KEY_K:
		model->Translate(glm::vec2(0.0f, -delta));
		break;
	case GLFW_KEY_KP_ADD:
		model->Scale(1.2f);
		break;
	case GLFW_KEY_KP_SUBTRACT:
		model->Scale(1.0f / 1.2f);
		break;

		// Projection transformations
	case GLFW_KEY_COMMA:
		projection->SetFovDegrees(projection->GetFovDegrees() + 3.0f);
		break;
	case GLFW_KEY_PERIOD:
		projection->SetFovDegrees(projection->GetFovDegrees() - 3.0f);
		break;
	case GLFW_KEY_P:
		if (projection->GetProjectionType() == ProjectionType::PERSPECTIVE)
			projection->SetProjectionType(ProjectionType::PARALLEL);
		else
			projection->SetProjectionType(ProjectionType::PERSPECTIVE);
		break;
	case GLFW_KEY_V:
		projection->SetObliqueAngleDegrees(projection->GetObliqueAngleDegrees() - 5.0f);
		break;
	case GLFW_KEY_B:
		projection->SetObliqueAngleDegrees(projection->GetObliqueAngleDegrees() + 5.0f);
		break;
	case GLFW_KEY_N:
		projection->SetObliqueScale(projection->GetObliqueScale() - 0.1f);
		break;
	case GLFW_KEY_M:
		projection->SetObliqueScale(projection->GetObliqueScale() + 0.1f);
		break;


		// View (Camera transformations)
	case GLFW_KEY_W:
		// Up,  move p_0 and p_ref relative the cameras positive y-axis
		camera->Translate(glm::vec3(0.0f, delta, 0.0f));
		break;
	case GLFW_KEY_S:
		// Down, move p_0 and p_ref relative the cameras negative y-axis
		camera->Translate(glm::vec3(0.0f, -delta, 0.0f));
		break;
	case GLFW_KEY_A:
		// Right,  move p_0 and p_ref relative the cameras positive x-axis
		camera->Translate(glm::vec3(-delta, 0.0f, 0.0f));
		break;
	case GLFW_KEY_D:
		// Left, move p_0 and p_ref relative the cameras negative x-axis
		camera->Translate(glm::vec3(delta, 0.0f, 0.0f));
		break;
	case GLFW_KEY_Z:
		// Forward, move p_0 and p_ref relative the cameras negative z-axis
		camera->Translate(glm::vec3(0.0f, 0.0f, -delta));
		break;
	case GLFW_KEY_X:
		// Backward, move p_0 and p_ref relative the cameras positive z-axis
		camera->Translate(glm::vec3(0.0f, 0.0f, delta));
		break;


	case GLFW_KEY_Q:
		glfwSetWindowShouldClose(window, GL_TRUE);
		break;


	}
}
