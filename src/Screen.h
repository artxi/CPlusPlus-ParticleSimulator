#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace simulator {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	Screen();
	bool init();
	void setPixel(int, int, Uint8, Uint8, Uint8);
	bool processEvents();
	void update();
	void close();
	void clear();
};

}

#endif
