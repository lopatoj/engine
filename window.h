//
// Created by lopatoj on 1/9/24.
//

#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Window
{
public:
    Window(int width, int height, const std::string& title);
    virtual ~Window();

    bool isOpen();
    void input();
    void swap();
protected:
private:
    Window(const Window& other);
    void operator=(const Window& other);

    GLFWwindow* m_window;
};

#endif //ENGINE_WINDOW_H
