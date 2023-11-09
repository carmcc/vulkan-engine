#pragma once

#include "ve_window.hpp"
#include "ve_pipeline.hpp"
#include "ve_device.hpp"

namespace ve {

    class FirstApp {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
        //describe this private member
    private:
        VeWindow veWindow{WIDTH, HEIGHT, "Vulkan Window"};
        VeDevice veDevice{veWindow};
        VePipeline vePipeline {veDevice,
                               "shaders/easy_shader.vert",
                               "shaders/easy_shader.frag",
                               VePipeline::defaultPipelineConfigInfo(WIDTH,HEIGHT)};
    };
} // namespace ve
