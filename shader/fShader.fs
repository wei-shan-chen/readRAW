#version 330 core
out vec4 FragColor;

in VS_OUT{
    vec3 FragPos;
	vec3 Normal;
	// vec2 TexCoords;
} fs_in;

uniform vec3 objectColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform bool blinn;
uniform bool shader;
uniform vec3 color;
// function prototypes
void main()
{
    if(shader){
        // ambient
        vec3 ambient = 0.05 * objectColor;
        // diffuse
        vec3 lightDir = normalize(lightPos - fs_in.FragPos);
        vec3 normal = normalize(fs_in.Normal);
        float diff = max(dot(lightDir, normal), 0.0);
        vec3 diffuse = diff * objectColor;
        // specular
        vec3 viewDir = normalize(viewPos - fs_in.FragPos);
        vec3 reflectDir = reflect(-lightDir, normal);
        float spec = 0.0;
        if(blinn)
        {
            vec3 halfwayDir = normalize(lightDir + viewDir);  
            spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
        }
        else
        {
            vec3 reflectDir = reflect(-lightDir, normal);
            spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0);
        }
        vec3 specular = vec3(0.3) * spec; // assuming bright white light color
        FragColor = vec4(ambient + diffuse + specular, 1.0);
    }else{
        FragColor = vec4(color, 1.0);
    }
    
} 
