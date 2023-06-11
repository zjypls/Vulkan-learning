//
// Created by 32725 on 2023/6/11.
//
#define SDL_MAIN_HANDLED
#include "zInstance.h"
#include "SDL2/SDL.h"

class App{
public:
	App(){
		initWindow();
		initVulkan();
	}
	~App(){
		cleanup();
	}
	void run(){
		mainLoop();
	}
private:
	void initWindow(){
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("VulkanTest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_VULKAN);
	}
	void initVulkan(){
		instance = Z::Instance{};
	}
	void mainLoop(){
		bool quit = false;
		while (!quit){
			SDL_Event event;
			while (SDL_PollEvent(&event)){
				if (event.type == SDL_QUIT){
					quit = true;
				}
			}
		}
	}
	void cleanup(){
		instance.destroy();
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
private:
	SDL_Window* window{};
	Z::Instance instance;
};

int main(){
	App app;
	app.run();
	return 0;
}