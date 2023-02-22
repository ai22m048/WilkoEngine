#include "WilkoEngine.h"

class Sandbox : public WilkoEngine::Application
{
public:
	Sandbox()
	{

	}

};

WilkoEngine::Application* WilkoEngine::CreateApplication() 
{
	return new Sandbox();
}