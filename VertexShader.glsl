#version 330 core

in vec3 position;
smooth out vec4 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 light_pos;
uniform vec3 light_intensity;

void main() {
	gl_Position = projection * view * model * vec4(position, 1.0);
}