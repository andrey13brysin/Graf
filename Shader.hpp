#pragma once
#include<iostream>
#include<glad.h>
#include<GLFW/glfw3.h>
#include<fstream>
#include<sstream>

class Shader
{
public:
	GLint program;

	Shader(const GLchar* Vpath, const GLchar* Fpath);

	void Use();
};