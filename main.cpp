#include<iostream>
#include<glad.h>
#include<GLFW/glfw3.h>
#include"Shader.hpp"
#include"Obj.hpp"
#include<math.h>
#include"App.hpp"
#include<list>

GLFWwindow* win;

class MyApp : public App
{
public:

	MyApp(int w, int h, std::string t) : App(w,h,t)
	{
		MainShader = new Shader("Vert.glsl", "Frag.glsl");
		kf = w / h;
	}
	~MyApp()
	{
		delete(MainShader);
	}

	virtual void Update() override
	{
		MainShader->Use();
		it = objs.begin();

		if (!objs.empty())
		{
			do
			{
				(*it)->Draw();
				it++;
			} while (it != objs.end());
		}
	}

	void Add_Object(Obj3D* o)
	{
		objs.push_front(o);
	}

	GLfloat Get_Kf()
	{
		return kf;
	}

private:
	std::list<Obj3D*> objs;
	std::list<Obj3D*>::iterator it;
	Shader* MainShader;

	GLfloat kf;
};

int Init(int with, int heith)
{
	if (!glfwInit())
	{
		std::cout << "GLFW INIT ERROR" << std::endl;
		return 1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	win = glfwCreateWindow(with, heith, "learn", NULL, NULL);
	if (!win)
	{
		std::cout << "WIN OPEN ERROR" << std::endl;
		return 2;
	}

	glfwMakeContextCurrent(win);

	if (glfwGetCurrentContext == NULL)
	{
		std::cout << "Context ERROR" << std::endl;
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{

		std::cout << "ProcLoader init fall " << std::endl;
		glfwTerminate();
		return 1;
	}
	return 0;
}


int main()
{
	MyApp* app = new MyApp(900, 450, "test");

	GLfloat v1[21];
	GLfloat c1[21];

	int i = 0;

	for (i = 0; i < 7; i++)
	{
		v1[i * 3] = GLfloat(std::cos(i * 0.89)) / (2 * app->Get_Kf());
		v1[(i * 3) + 1] = GLfloat(std::sin(i * 0.89)) / 2;
		v1[(i * 3) + 2] = 1.0f;
		c1[(i * 3)] = 1.0f;
		c1[(i * 3) + 1] = c1[(i * 3) + 2] = 0.0f;
	}

	glPointSize(10);
	Points polygon(v1, c1, 7, GL_POINTS);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	app->Add_Object(&polygon);

	app->Start();

	delete(app);
}