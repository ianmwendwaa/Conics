#ifndef CORE_H
#define CORE_H
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

// Helper function to check if the file is empty
inline static auto is_file_empty = [](const fs::path& filePath) {
    if (fs::exists(filePath) && fs::file_size(filePath) > 0) {
        std::cerr << "File is not empty. Erasing data...\n";
        std::ofstream ofstream(filePath, std::ios::trunc);
    }
    return true;
};
class Core {
public:
    Core();
    ~Core();
    static std::string NormalizeQuery(const std::string& query);



    void WriteDataResults(const std::string& txtFileName){};

    template<typename C, typename V, typename ... Args>
    void WriteDataResults(const std::string& txtFileName, C&& var, V&& val, Args&&... args) {
        const fs::path directory = "C:\\Math\\Conics";
        if (!fs::exists(directory)) {
            std::cerr << directory << " does not exist. Creating it...";
            fs::create_directories(directory);
        }
        // Define the file name to write the obtained data into
        const fs::path fileName = directory / txtFileName;

        // if (is_file_empty(fileName)) is_file_empty(fileName);

        // if (fs::file_size(fileName) > 0) fs::resize_file(fileName, 0);
        std::ofstream file(fileName, std::ios::app);

        if (!file.is_open()) {
            std::cerr << "Error opening file " << fileName;
            return;
        }
        (file << std::forward<C>(var) << std::forward<V>(val)) << "\n";// Append each piece of data on a new line for simpler splitting by Python
        std::cout << "Text file created and saved successfully!\n";
        file.close();
        WriteDataResults(txtFileName, std::forward<Args>(args)...);
    }

};
#endif //CORE_H
