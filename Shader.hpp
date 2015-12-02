#pragma once
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

class Shader {
private:
	GLenum shader_type;
	GLuint shader_id;
	GLchar* shader_source;
	static GLchar* ReadFile(string filename);
	static streamoff GetFileLength(ifstream & file);
	void CompileShader();
	bool CompiledSuccessfully();
	string GetCompileErrorMessage();
public:
	Shader(GLenum shader_type);
	~Shader();
	GLuint GetId();
	static Shader* CreateFromFile(string filename, GLenum shader_type);
};

class VertexShader : public Shader
{
public:
	static Shader* CreateFromFile(string filename);
};

class FragmentShader : public Shader
{
public:
	static Shader* CreateFromFile(string filename);
};