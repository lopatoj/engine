//
// Created by lopatoj on 1/13/24.
//

#include <unistd.h>
#include "shader.h"

GLchar* readFile(const GLchar* path);
void checkSuccess();

Shader::Shader(const GLchar* path, const GLenum type)
{
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    VBO = 0;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    source = readFile(path);

    shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    checkSuccess();
}

Shader::~Shader()
{
    glDeleteShader(shader);
    free(source);
}

GLchar* readFile(const GLchar* path)
{

    FILE* file = fopen(path, "r");
    if (!file)
    {
        std::cerr << "Failed to open file: " << path << std::endl;
        return nullptr;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    GLchar* buffer = (GLchar*)malloc(length + 1);
    if (!buffer)
    {
        std::cerr << "Failed to allocate memory for file: " << path << std::endl;
        return nullptr;
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    fclose(file);

    return buffer;
}

void checkSuccess()
{
    int success;
    char infoLog[512];
    glGetShaderiv(1, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(1, 512, nullptr, infoLog);
        std::cerr << "Failed to compile shader: " << infoLog << std::endl;
    }
}