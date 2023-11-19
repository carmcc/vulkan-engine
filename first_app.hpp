#pragma once

#include "ve_window.hpp"
#include "ve_pipeline.hpp"
#include "ve_device.hpp"
#include "ve_swap_chain.hpp"

#include "memory"
#include "vector"

namespace ve {

    class FirstApp {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        //describe this private member
        FirstApp();
        ~FirstApp();
        FirstApp(const FirstApp&) = delete;
        FirstApp& operator=(const FirstApp&) = delete;
        void run();

    private:
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        VeWindow veWindow{WIDTH, HEIGHT, "Vulkan Window"};
        VeDevice veDevice{veWindow};
        VeSwapChain veSwapChain{veDevice, veWindow.getExtent()};
        std::unique_ptr<VePipeline> vePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
    };
} // namespace ve
