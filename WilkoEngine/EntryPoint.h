#pragma once

#ifdef WE_PLATFORM_WINDOWS

extern WilkoEngine::Application* WilkoEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Wilko Engine\n");
	auto app = WilkoEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif