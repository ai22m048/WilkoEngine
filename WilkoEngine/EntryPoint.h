#pragma once

#ifdef WE_PLATFORM_WINDOWS

extern WilkoEngine::Application* WilkoEngine::CreateApplication();

int main(int argc, char** argv)
{
	// printf("Wilko Engine\n");
	WilkoEngine::Log::Init();
	WE_CORE_WARN("Initialized log!");
	int a = 5;
	WE_INFO("Hello! Var={0}", a);
	auto app = WilkoEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif