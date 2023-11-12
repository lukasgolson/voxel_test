#version 330 core

in vec3 fragColor;

out vec4 fragOutputColor;

void main() {
    fragOutputColor = vec4(fragColor, 1);
}
