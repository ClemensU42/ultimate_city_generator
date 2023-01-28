//
// Created by Clemens on 27/01/2023.
//

#ifndef ULTIMATE_CITY_GENERATOR_VULKANUTILS_H
#define ULTIMATE_CITY_GENERATOR_VULKANUTILS_H

#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif
#include <GLFW/glfw3.h>
#include <vector>

namespace VulkanUtils {
    void initVulkan();

    VkInstance createInstance(const std::vector<const char*>& validationLayers);

    bool checkValidationLayerSupport(const std::vector<const char*>& validationLayers);
};


#endif //ULTIMATE_CITY_GENERATOR_VULKANUTILS_H
