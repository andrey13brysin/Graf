#include<iostream>
#include<string>
#include<functional>

struct GLFWwindow;

class Window
{
private:
	struct m_data 
	{
		unsigned int m_with;
		unsigned int m_heith;
		std::string m_title;
	};
	m_data w_data;
	
	int init();
	void shutdown();


public:
	Window(int with, int heith, std::string titel);
	~Window();

	int GetWith() { return w_data.m_with; }
	int GetHeit() { return w_data.m_heith; }

	void on_update();
	GLFWwindow* win;


};