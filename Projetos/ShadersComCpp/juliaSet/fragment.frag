#version 330 core
out vec4 FragColor;
in vec2 uv;
uniform float time;
uniform vec2 resolution;

void main() {
    // Coordenadas complexas
    vec2 z = (uv-0.5)*2.5*cos(time/10)+0.2;//meio que da um zoom
    vec2 c = vec2(0, mix(0.635,0.667,(sin(time)+1)*0.5));
    
    int maxIter = 100;
    int iter = 0;
    
    // Iteração do Julia Set: z = z² + c
    for(int i = 0; i < maxIter; i++) {
        if(length(z) > (sin(time)+2)*10) break;//limite de dominio (gera as linhas verdes)
        
        // z² para números complexos: (a+bi)² = (a²-b²) + 2abi
        float x = z.x * z.x - z.y * z.y + c.x;
        float y = 2.0 * z.x * z.y + c.y;
        z = vec2(x, y);
        
        iter++;
    }

    float sm = iter - log(length(z));

    vec3 color = vec3(sm/150,log(iter)*tanh(sm)/8,sm/10);
    
    FragColor = vec4(color, 1.0);
}