#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_color;

uniform mat4 m_model;
uniform mat4 m_view;
uniform mat4 m_projection;


out vec3 color;

void main() {
    color = in_color;
    gl_Position = m_model * m_projection * m_view * vec4(in_position, 1.0);
}
