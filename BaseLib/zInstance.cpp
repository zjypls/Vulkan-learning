//
// Created by 32725 on 2023/6/11.
//
#include <iostream>
#include "zInstance.h"

namespace Z {
		VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		                                             VkDebugUtilsMessageTypeFlagsEXT messageType,
		                                             const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
		                                             void *pUserData) {
			std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
			return VK_FALSE;
		}
	Instance::Instance(Instance::InstanceInfo info) {
		auto debugCreateInfo = vk::DebugUtilsMessengerCreateInfoEXT({},
		                                                            vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose |
		                                                            vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning |
		                                                            vk::DebugUtilsMessageSeverityFlagBitsEXT::eError,
		                                                            vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral |
		                                                            vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation |
		                                                            vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance,
		                                                            info.debugCallback== nullptr?debugCallback:info.debugCallback);
		if(info.enableValidation) {
			info.extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
			info.layers.push_back("VK_LAYER_KHRONOS_validation");
		}
		vk::InstanceCreateInfo createInfo({}, &info.appInfo, info.layers, info.extensions,info.enableValidation?&debugCreateInfo: nullptr);
		instance = vk::createInstance(createInfo);
		dispatcher = vk::DispatchLoaderDynamic(instance, vkGetInstanceProcAddr);
		if(info.enableValidation){
			debugMessenger = instance.createDebugUtilsMessengerEXT(debugCreateInfo, nullptr,dispatcher);
		}
	}

	Instance::~Instance() {

	}

	void Instance::destroy() {
		if(debugMessenger){
			instance.destroyDebugUtilsMessengerEXT(debugMessenger, nullptr,dispatcher);
		}
		instance.destroy();
	}

}
