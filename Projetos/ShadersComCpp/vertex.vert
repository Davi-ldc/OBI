#version 330 core
layout(location = 0) in vec2 position;
out vec2 uv;

void main() {
    //converte a posição de [-1, 1] para [0, 1]
    uv = position * 0.5 + 0.5;
    gl_Position = vec4(position, 0.0, 1.0);
}