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
#include <optional>

namespace VulkanUtils {
    struct QueueFamilyIndices{
        std::optional<uint32_t> graphicsFamily;

        bool isComplete() const;
    };


    void initVulkan();

    VkInstance createInstance(const std::vector<const char*>& validationLayers);

    bool checkValidationLayerSupport(const std::vector<const char*>& validationLayers);

    // Device related functions
    void pickPhysicalDevice(VkInstance& instance);
    bool isDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice);
};


#endif //ULTIMATE_CITY_GENERATOR_VULKANUTILS_H
