#pragma once

namespace Display
{
	void init();
	void clear();
	void display();

	bool isOpen();
	void checkWindowEvents();

	const int HEIGHT = 800;
	const int WIDTH = 600;
}