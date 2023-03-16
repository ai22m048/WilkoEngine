#include "wepch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace WilkoEngine {

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			WE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			WE_TRACE(e);
		}

		while (true);
	}

}