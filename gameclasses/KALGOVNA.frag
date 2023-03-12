uniform float time;


mat2 rotate(float angle) {
    return mat2(
        cos(angle), sin(angle),
        -sin(angle), cos(angle)
    );
}

void main() {
    //float time = 1.0;
    vec2 coord = gl_FragCoord.xy;
    coord = rotate(time) * coord;
    coord = coord * sin(time * 0.44 + 12.0);
    gl_FragColor = vec4(sin(coord.x * 0.01), cos(coord.y * 0.03), pow(sin(time * 0.5), 2.0), 1.0);
}