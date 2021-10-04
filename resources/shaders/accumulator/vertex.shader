#version 410 core

layout(location = 0) in vec2 a_position;
out vec2 uv;

void main( void ) {
	uv = (a_position.xy + 1) / 2;
	gl_Position = vec4(a_position.xy, 1.0, 1.0);
}
