//
// Created by lopatoj on 1/13/24.
//

#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include "glad/glad.h"
#include <string>
#include <iostream>

class Shader
{
public:
    Shader(const GLchar* path, const GLenum type);
    ~Shader();

    unsigned int getShader() const { return shader; }
protected:
private:
    Shader(const Shader& other);
    void operator=(const Shader& other);

    GLchar* source;
    unsigned int VBO;
    unsigned int shader;
};


#endif //ENGINE_SHADER_H
