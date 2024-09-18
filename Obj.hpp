#pragma once
#include<glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

class Obj3D
{
public:
	Obj3D() {};
	~Obj3D() {};
	virtual void Draw();
};

class Triangle : public Obj3D
{
public:

	GLfloat vertex[9];
	GLfloat color[9];

	Triangle(GLfloat v[9], GLfloat c[9]);
	Triangle() = delete;
	~Triangle();
	void Draw() override;

	GLuint VBO;
	GLuint VBO_C;
	GLuint VAO;

};

class Points : public Obj3D
{
public:
	Points(GLfloat* buf, GLfloat* c_buf, int count, GLint t);
	Points() = delete;
	~Points()
	{
		delete(vertex);
		delete(color);

	}
	void Draw() override;
private:
	GLfloat* vertex;
	GLfloat* color;

	GLuint VBO;
	GLuint VBO_C;
	GLuint VAO;

	GLenum type;

	GLint v_count;
};
