#pragma once

#include "ve_window.hpp"
#include "ve_pipeline.hpp"

namespace ve {

    class FirstApp {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
        //describe this private member
    private:
        VeWindow veWindow{WIDTH, HEIGHT, "Vulkan Window"};
        VePipeline vePipeline {"shaders/easy_shader.vert", "shaders/easy_shader.frag"};
    };
} // namespace ve
