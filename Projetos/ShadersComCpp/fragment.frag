#version 330 core
out vec4 FragColor;
in vec2 uv;
uniform float time;
uniform vec2 resolution;

void main(){
    // Turbulence parameters
    float amplitude = 0.7;      
    float speed = 0.3;
    float freq = 2.0;    
    float multi = 1.4;      

    // uv [0,1] [1,-1] 
    vec2 pos = (uv - 0.5) * 2.0;

    // Turbulence rotation matrix
    mat2 rot = mat2(0.6, -0.8, 0.8, 0.6);

    // Loop through turbulence octaves
    float octaves = 100;
    for(float i = 0.0; i < octaves; i += 1.0)
    {
        // Scroll along the rotated y coordinate
        float phase = freq * (pos * rot).y + speed * time + i;

        // Add a perpendicular sine wave offset
        pos += amplitude * rot[0] * sin(phase) / freq;

        // Rotate for the next octave
        rot *= mat2(0.6, -0.8, 0.8, 0.6);
        // Scale down for the next octave
        freq *= multi;
    }

    // Quanto maior o multiplicador dentro da função maior vai ser o contraste
    //Isso por que ao multiplicar estamos esticando o intervalo, deixando
    //os valores mias distantes
    float contraste = 10.0;
    float r = tanh(pos.y*contraste)*0.5+0.5;
    float g = tanh(pos.x*contraste)*0.5+0.5; 
    float b = -1*(r+g)+2;//Onde r+g for 2->0 onde for 0->2
    vec3 color = vec3(r,g,b);

    FragColor = vec4(color, 1.0); 
}