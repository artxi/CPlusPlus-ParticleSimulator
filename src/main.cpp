#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace simulator;

int main() {

	srand(time(NULL));

	Screen screen;

	if (!screen.init()) {
		printf("Error initialising SDL");
	}

	Swarm swarm;

	while (true) {

		int elapsed = SDL_GetTicks();

		screen.clear();
		swarm.update();

		unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.update();

		if (!screen.processEvents()) {
			break;
		}

	}

	screen.close();

	return 0;
}
