//
// Created by 32725 on 2023/6/11.
//

#ifndef VULKANLEARNING_INSTANCE_H
#define VULKANLEARNING_ZINSTANCE_H
#define VK_USE_PLATFORM_WIN32_KHR
#include "vulkan/vulkan.hpp"
namespace Z {
	class Instance {
	public:
		struct InstanceInfo{
			std::vector<const char*> layers;
			std::vector<const char*> extensions;
			vk::ApplicationInfo appInfo;
			bool enableValidation= true;
			PFN_vkDebugUtilsMessengerCallbackEXT debugCallback;
			InstanceInfo():layers(),extensions({VK_KHR_WIN32_SURFACE_EXTENSION_NAME}),enableValidation(false),
			               appInfo{
					               "Vulkan", VK_MAKE_VERSION(1,0,0),
					               "No Engine", VK_MAKE_VERSION(1,0,0),
					               VK_API_VERSION_1_3}{
				debugCallback= nullptr;
			}
		};
		explicit Instance(InstanceInfo info=InstanceInfo{});
		void destroy();
		~Instance();
	private:
		vk::Instance instance;
		vk::DebugUtilsMessengerEXT debugMessenger;
		vk::DispatchLoaderDynamic dispatcher;
	};

}


#endif //VULKANLEARNING_INSTANCE_H
