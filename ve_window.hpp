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
        void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

    private:

        void initWindow();

        const int WIDTH = 800;
        const int HEIGHT = 600;

        std::string windowName;
        GLFWwindow* window;
    };
} // namespace ve