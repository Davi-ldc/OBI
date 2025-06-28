#version 330 core
out vec4 FragColor;
in vec2 uv;

void main() {
    // define tamanho e posição do quadrado
    vec2 center = vec2(0.5, 0.5); // centro da tela
    vec2 size = vec2(0.5, 0.5);   // largura e altura

    
    if (uv.x > center.x - size.x && uv.x < center.x + size.x &&
        uv.y > center.y - size.y && uv.y < center.y + size.y) {
        FragColor = vec4(0.0, 1.0, 0.0, 1.0); // verde
    } else {
        FragColor = vec4(0.0, 0.0, 0.0, 1.0); // preto
    }
}
