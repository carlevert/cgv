#include "Shader.hpp"


void Shader::CompileShader()
{
	GLuint shader = glCreateShader(shader_type);
	glShaderSource(shader_id, 1, (const GLchar**)&shader_source, NULL);
	glCompileShader(shader_id);
}

bool Shader::CompiledSuccessfully()
{
	GLint compiled_successfully;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compiled_successfully);
	return compiled_successfully != 0;
}

string Shader::GetCompileErrorMessage()
{
	GLint  log_length;
	glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &log_length);
	GLchar* info_log = new GLchar[log_length];
	glGetShaderInfoLog(shader_id, log_length, NULL, info_log);
	string error_message(info_log);
	delete[] info_log;
	return error_message;
}

Shader::Shader(GLenum shader_type)
{
	this->shader_type = shader_type;
	shader_id = glCreateShader(shader_type);
}

Shader::~Shader()
{
	glDeleteShader(shader_id);
}

GLuint Shader::GetId()
{
	return shader_id;
}

Shader * Shader::CreateFromFile(string filename, GLenum shader_type)
{
	Shader* shader = new Shader(shader_type);
	shader->shader_source = ReadFile(filename);
	shader->shader_type = shader_type;
	shader->CompileShader();
	if (!shader->CompiledSuccessfully()) {
		cerr << "Compile error: " << filename << endl;
		cerr << shader->GetCompileErrorMessage() << endl;
		getc(stdin);

		exit(EXIT_FAILURE);
	}
	return shader;
}

streamoff Shader::GetFileLength(ifstream & file)
{
	if (!file.good())
		return 0;
	streamoff initial_offset = file.tellg();
	file.seekg(0, ios::beg);
	streamoff start = file.tellg();
	file.seekg(0, ios::end);
	streamoff end = file.tellg();
	file.seekg(initial_offset, ios::beg);
	return end - start;
}

GLchar * Shader::ReadFile(string filename)
{
	ifstream file;
	file.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		file.open(filename);
		string contents((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
		unsigned int length = contents.length();
		GLchar* shader_source = new GLchar[length + 1];
		memcpy(shader_source, contents.c_str(), length);
		shader_source[length] = 0;
		return shader_source;
	}
	catch (ifstream::failure) {
		cerr << "ifstream::failure" << endl;
		return nullptr;
	}
}

Shader * VertexShader::CreateFromFile(string filename)
{
	return Shader::CreateFromFile(filename, GL_VERTEX_SHADER);
}

Shader * FragmentShader::CreateFromFile(string filename)
{
	return Shader::CreateFromFile(filename, GL_FRAGMENT_SHADER);
}
