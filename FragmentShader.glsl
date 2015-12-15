#version 330 core

in vec4 color;
out vec4 fColor;

void main() {
	fColor = color;
//	fColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);
}