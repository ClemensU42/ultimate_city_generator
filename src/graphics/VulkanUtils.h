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
        std::optional<uint32_t> presentFamily;

        bool isComplete() const;
    };


    void initVulkan();

    VkInstance createInstance(const std::vector<const char*>& validationLayers);

    bool checkValidationLayerSupport(const std::vector<const char*>& validationLayers);

    // Device related functions
    VkPhysicalDevice pickPhysicalDevice(VkInstance& instance, VkSurfaceKHR& surface);
    bool isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR& surface);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice, VkSurfaceKHR& surface);
    VkDevice createLogicalDevice(VkPhysicalDevice physicalDevice, const std::vector<const char*>& validationLayers, VkQueue* graphicsQueue, VkSurfaceKHR& surface);
};


#endif //ULTIMATE_CITY_GENERATOR_VULKANUTILS_H
