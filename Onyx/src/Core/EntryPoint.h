#pragma once

#ifdef ONYX_PLATFORM_WINDOWS

extern Onyx::Application* Onyx::CreateApplication();

int main(int argc, char** argv) {
	auto app = Onyx::CreateApplication();
	app->Run();
	delete app;
}

#endif