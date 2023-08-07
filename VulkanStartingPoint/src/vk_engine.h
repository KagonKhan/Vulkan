// vulkan_guide.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vk_types.h>
#include <memory>

class VulkanEngine {
public:
	VulkanEngine();
	~VulkanEngine();

	void draw();
	void run();

private:
	void init();
	void cleanup();

	struct WindowDeleter {
		void operator()(struct SDL_Window* window);
	};
	std::unique_ptr<SDL_Window, WindowDeleter> sdl_window{ nullptr };
	VkExtent2D _windowExtent{ 1700 , 900 };
	int frame_number{ 0 };
};
