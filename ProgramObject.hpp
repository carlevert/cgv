#pragma once
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <GL/glew.h>
#include "Shader.hpp"

using namespace std;

class ProgramObject
{
private:
	GLuint program;
	ProgramObject();
	void AttachShader(Shader * shader);
	void LinkProgram();
	bool LinkedSuccessfully();
	string GetLinkingErrorMessage();

public:
	~ProgramObject();
	GLuint GetAttribLocation(const GLchar* name);
	GLuint GetUniformLocation(const GLchar* name);
	void Use();
	GLuint GetProgramId();
	static ProgramObject* CreateFromFiles(string vertex_shader, string fragment_shader);
};

