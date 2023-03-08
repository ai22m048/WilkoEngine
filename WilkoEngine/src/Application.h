#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace WilkoEngine {

	class WILKO_API Application
	{
	public:
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}