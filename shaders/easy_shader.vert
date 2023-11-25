#version 450

layout (location = 0) in vec2 vertices[]; //
//executed for each vertex of the input primitives
void main () {
    gl_Position = vec4(vertices[gl_VertexIndex], 0.0, 1.0);
}
