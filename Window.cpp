#include<iostream>
#include"Window.hpp"
#include<glad.h>
#include<GLFW/glfw3.h>

Window::Window(int with, int heith, std::string title)
{
    
    w_data.m_heith = heith;
    w_data.m_with = with;
    w_data.m_title = title;
	int resultCode = init();
    std::cout << resultCode << std::endl;
}
Window::~Window()
{
    shutdown();
}
int Window::init()
{
    if (!glfwInit())
    {
        std::cout << "GLFW INIT ERROR" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    win = glfwCreateWindow(w_data.m_with, w_data.m_heith, w_data.m_title.c_str(), nullptr, nullptr);

    if (win == nullptr)
    {
        std::cout << "Window create ERROR" << std::endl;
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(win);

    if (glfwGetCurrentContext == NULL)
    {
        std::cout << "Context ERROR" << std::endl;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "ProcLoader init fall" << std::endl;
        glfwTerminate();
        return 1;
    }
    glfwSetWindowUserPointer(win, &w_data);

    return 0;
}
void Window::shutdown()
{
    glfwDestroyWindow(win);
    glfwTerminate();
}

void Window::on_update()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}