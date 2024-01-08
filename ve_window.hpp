#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include "string"
namespace ve {
    class VeWindow {
    public:
        /**
         * @brief Construct a new Ve Window:: Ve Window object
         * @param w
         * @param h
         * @param name
         */
        VeWindow(int w, int h, std::string name);

        /**
         * @brief Destroy the Ve Window:: Ve Window object
         */
        ~VeWindow();

        VeWindow(const VeWindow&) = delete;
        VeWindow& operator=(const VeWindow&) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }

        VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }
        bool wasWindowResized() { return framebufferResized; }
        void resetWindowResizedFlag() { framebufferResized = false; }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

    private:
        static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

        void initWindow();

        int width = 800;
        int height = 600;
        bool framebufferResized = false; //flag to check if the window is resized

        std::string windowName;
        GLFWwindow* window;
    };
} // namespace ve