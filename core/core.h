/* Created by Ian 2026
 * This file contains utility functions that span across the project. Some of these functions include
 * 1. Query normalization - which cleans the query by remiving whitespaces and transforms the query input
 * to lowercase
 * 2. Parsing equation coefficients - particularly useful if coefficient values haven't been explicitly
 * mapped by the user
 * 3. Data manipulation and recording - writing derived data into textfiles. A minimalistic data pipeline
 * between C++ and Python
 */
#ifndef CORE_H
#define CORE_H
#include <algorithm>
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
        return false;
    }
    return true;
};

namespace Core {
    inline std::string NormalizeQuery(const std::string &query) {
        // This function takes in the query, converts it to lowercase and removes whitespaces to increase predictability
        std::string cleanQuery = query;
        std::ranges::transform(cleanQuery, cleanQuery.begin(), ::tolower);
        auto [ret, back] = std::ranges::remove(cleanQuery, ' ');
        cleanQuery.erase(ret, back);
        return cleanQuery;
    }
    inline auto parse_coefficients(const std::string& s){
        auto is_variable = [&](char s_char){
            constexpr char variables[3] = {'x','y','z'};
            for (const auto& it: variables){
                if (it == s_char)
                    return true;
            }
            return false;
        };
        if (s.empty()) return 1.0;
        const double s_val = std::stod(s);
        return is_variable(reinterpret_cast<char>(s.c_str())) ? 1.0 : s_val;
    }
    template<typename C, typename V, typename ... Args>
    static void WriteDataResults(const std::string& txtFileName, C&& var, V&& val, Args&&... args) {
        const fs::path directory = "C:\\Math\\Conics";
        if (!fs::exists(directory) && is_file_empty(txtFileName)) {
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
