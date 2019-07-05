#include <Noctis.h>
#include "imgui.h"

class ExampleLayer : public Noctis::Layer {
public:
	ExampleLayer()
		:Layer("Example") {};

	void OnUpdate() override {
		//NT_CLIENT_INFO("updated layer");
		if (Noctis::Input::IsKeyPressed(NT_KEY_TAB))
			NT_CLIENT_INFO("TAB KEY PRESSED");
	}
	void OnImGuiRender() override {
		ImGui::Begin("test");
		ImGui::Text("HELLO WORLD!");
		ImGui::End();
	}

	void OnEvent(Noctis::Event & e) override {
		if (e.GetEventType() == Noctis::EventType::KeyTyped)
		{
			Noctis::KeyTypedEvent& ev = (Noctis::KeyTypedEvent&) e;
			NT_CORE_TRACE("{0}", (char)ev.GetKeyCode());
		}
		//NT_CLIENT_INFO("EVENT! {0}", e);
	}
};

class Sandbox : public Noctis::Application {
public:
	Sandbox(){
		PushLayer(new ExampleLayer());
	}
	~Sandbox(){
	}
};

Noctis::Application* Noctis::CreateApplication() {
	return new Sandbox();
}