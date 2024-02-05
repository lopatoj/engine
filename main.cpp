#include <glad/glad.h>
#include "window.h"
#include "shader.h"

void update();

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
};

int main()
{
    Window window(SCR_WIDTH, SCR_HEIGHT, "engine");

    Shader vertex("shaders/vertex.glsl", GL_VERTEX_SHADER);
    Shader fragment("shaders/fragment.glsl", GL_FRAGMENT_SHADER);

    while (window.isOpen())
    {
        window.input();
        update();
        window.swap();
    }

    return 0;
}

void update()
{

}