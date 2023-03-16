#include <WilkoEngine.h>

class ExampleLayer : public WilkoEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		WE_INFO("ExampleLayer::Update");
	}

	void OnEvent(WilkoEngine::Event& event) override
	{
		WE_TRACE("{0}", event);
	}

};

class Sandbox : public WilkoEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

WilkoEngine::Application* WilkoEngine::CreateApplication()
{
	return new Sandbox();
}
