#version 450

layout (location = 0) in vec2 position;
//executed for each vertex of the input primitives
void main () {
    gl_Position = vec4(position, 0.0, 1.0);
}
