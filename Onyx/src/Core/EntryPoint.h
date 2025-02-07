#pragma once

#ifdef ONYX_PLATFORM_WINDOWS

extern Onyx::Application* Onyx::CreateApplication();

int main(int argc, char** argv) {

	Onyx::Log::Init();
	NX_CORE_WARN("Initialized Log!");
	NX_INFO("Hello!");


	auto app = Onyx::CreateApplication();
	app->Run();
	delete app;
}

#endif