#pragma once

#include "ve_window.hpp"

namespace ve {

    class FirstApp {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
        //describe this private member
    private:
        VeWindow veWindow{WIDTH, HEIGHT, "Vulkan Window"};
    };
} // namespace ve
