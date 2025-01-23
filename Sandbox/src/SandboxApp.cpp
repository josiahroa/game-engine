#include <Onyx.h>

class Sandbox : public Onyx::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

void main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}