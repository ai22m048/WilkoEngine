#pragma once

#include "Core.h"

namespace WilkoEngine {

	class WILKO_API Application
	{
	public:
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}