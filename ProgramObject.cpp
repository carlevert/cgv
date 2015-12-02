#include "ProgramObject.hpp"

ProgramObject::ProgramObject()
{
	program = glCreateProgram();
}

void ProgramObject::AttachShader(Shader * shader)
{
	
	glAttachShader(program, shader->GetId());
}

ProgramObject::~ProgramObject()
{
	glDeleteProgram(program);
}

void ProgramObject::LinkProgram()
{
	glLinkProgram(program);
}

bool ProgramObject::LinkedSuccessfully()
{
	GLint linked_successfully;
	glGetProgramiv(program, GL_LINK_STATUS, &linked_successfully);
	return linked_successfully == GL_TRUE;
}

string ProgramObject::GetLinkingErrorMessage()
{
	GLint log_length;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
	GLchar* info_log = new GLchar[log_length];
	glGetProgramInfoLog(program, log_length, NULL, info_log);
	string error_message(info_log);
	delete[] info_log;
	return error_message;

}

GLuint ProgramObject::GetAttribLocation(const GLchar* name)
{
	return glGetAttribLocation(program, name);
}

GLuint ProgramObject::GetUniformLocation(const GLchar * name)
{
	return glGetUniformLocation(program, name);
}

void ProgramObject::Use()
{
	glUseProgram(program);
}

GLuint ProgramObject::GetProgramId()
{
	return program;
}

ProgramObject * ProgramObject::CreateFromFiles(string vertex_shader_filename, string fragment_shader_filename)
{
	Shader* vertex_shader = VertexShader::CreateFromFile(vertex_shader_filename);
	Shader* fragment_shader = FragmentShader::CreateFromFile(fragment_shader_filename);

	ProgramObject* program_object = new ProgramObject();

	program_object->AttachShader(vertex_shader);
	program_object->AttachShader(fragment_shader);

	program_object->LinkProgram();
	if (!program_object->LinkedSuccessfully()) {
		cerr << "Linking error" << endl;
		cerr << program_object->GetLinkingErrorMessage() << endl;
		getc(stdin);
		exit(EXIT_FAILURE);
	}

	return program_object;
}
