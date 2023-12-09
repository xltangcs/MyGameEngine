#pragma once

#include "Candy/Core/Core.h"
#include "Candy/Core/Window.h"
#include "Candy/Core/Timestep.h"
#include "Candy/Core/LayerStack.h"

#include "Candy/Events/Event.h"
#include "Candy/Events/ApplicationEvent.h"

#include "Candy/Imgui/ImguiLayer.h"

namespace Candy {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		static Application* s_Instance;

	};


	Application* CreateApplication();
}

