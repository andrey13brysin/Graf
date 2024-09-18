#include"Window.hpp"

class App
{
public:
	Window* m_win;

	App(int with, int heith, std::string title);
	virtual ~App();

	int Start();
	virtual void Update();
	void End();
};