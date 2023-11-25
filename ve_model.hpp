#pragma once
#include "ve_device.hpp"
namespace ve_model{
    class VeModel {
    public:
        VeModel(VeDevice& device);
        ~VeModel();
        VeModel(const VeModel&) = delete;
        VeModel& operator=(const VeModel&) = delete;

        void bind(VkCommandBuffer commandBuffer);
        void draw(VkCommandBuffer commandBuffer);
    private:
        VeDevice& veDevice;
        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        uint32_t vertexCount;
    };
} // namespace ve_model