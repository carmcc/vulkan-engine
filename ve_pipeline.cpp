#include "ve_pipeline.hpp"
#include "fstream"
#include "stdexcept"
#include "iostream"

using namespace std;

namespace ve {
    VePipeline::VePipeline(VeDevice &device,
                           const std::string &vertFilePath,
                           const std::string &fragFilePath,
                           const PipelineConfigInfo &configInfo) : veDevice{device}
    {
        createGraphicsPipeline(vertFilePath,fragFilePath, configInfo);
    }
    vector<char> VePipeline::readFile(const string &filePath)
    {
        ifstream file{filePath,ios::ate | ios::binary};
        if (!file.is_open()) {
            throw runtime_error("failed to open file: " + filePath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(),fileSize);

        file.close();
        return buffer;
    }
    void VePipeline::createGraphicsPipeline(const string &vertFilePath, const string &fragFilePath, const PipelineConfigInfo &configInfo){
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        cout << "Vertex size: " << vertCode.size() << endl;
        cout << "Fragment size: " << fragCode.size() << endl;
    }

    void VePipeline::createShaderModule(const vector<char> &code, VkShaderModule *shaderModule)
    {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

        if (vkCreateShaderModule(veDevice.device(),&createInfo,nullptr,shaderModule) != VK_SUCCESS) {
            throw runtime_error("failed to create shader module!");
        }
    }

    PipelineConfigInfo VePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
    {
        PipelineConfigInfo configInfo{};
        return configInfo;
    }

}
