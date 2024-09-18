#include<iostream>
#include<glad.h>
#include<GLFW/glfw3.h>
#include"App.hpp"

App::App(int with, int heith, std::string title)
{
    m_win = new Window(with, heith, title);
}
App::~App()
{

}

int App::Start()
{
    while (!glfwWindowShouldClose(m_win->win))
    {
        glfwPollEvents();
        m_win->on_update();
        Update();
        glfwSwapBuffers(m_win->win);
    }
    return 0;
}
void App::Update() 
{

}
void App::End()
{
    delete(m_win);
}