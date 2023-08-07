#include "vk_engine.h"

#include <SDL.h>
#include <SDL_vulkan.h>

#include <vk_types.h>
#include <vk_initializers.h>

#include <iostream>

void VulkanEngine::WindowDeleter::operator()(struct SDL_Window* window) {
	SDL_DestroyWindow(window);
}

VulkanEngine::VulkanEngine()
	: sdl_window(nullptr, WindowDeleter()) {
	init();
}

VulkanEngine::~VulkanEngine() {
	cleanup();
}

void VulkanEngine::init() {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
	
	sdl_window.reset(SDL_CreateWindow(
		"Vulkan Engine",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		_windowExtent.width,
		_windowExtent.height,
		window_flags
	));
}

void VulkanEngine::cleanup() {	

}

void VulkanEngine::draw() {
	
}

void VulkanEngine::run() {
	std::cout << "[INFO] RUN\n";
	SDL_Event e;
	bool bQuit{ false };

	//main loop
	while (!bQuit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//close the window when user alt-f4s or clicks the X button			
			if (e.type == SDL_QUIT) bQuit = true;
		}

		draw();
	}
}
