#include "ve_pipeline.hpp"
#include "fstream"
#include "stdexcept"
#include "iostream"

using namespace std;

namespace ve {
    VePipeline::VePipeline(const string &vertFilePath, const string &fragFilePath)
    {
        createGraphicsPipeline(vertFilePath,fragFilePath);
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
    void VePipeline::createGraphicsPipeline(const string &vertFilePath, const string &fragFilePath) {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        cout << "Vertex size: " << vertCode.size() << endl;
        cout << "Fragment size: " << fragCode.size() << endl;
    }
}
