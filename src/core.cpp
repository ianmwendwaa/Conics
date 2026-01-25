//
// Created by Owner on 1/25/2026.
//

#include "core.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

Core::Core() = default;

std::string Core::NormalizeQuery(const std::string &query) {
    // This function takes in the query, converts it to lowercase and removes whitespaces to increase predictability
    std::string cleanQuery = query;
    std::ranges::transform(cleanQuery, cleanQuery.begin(), ::tolower);
    cleanQuery.erase(std::ranges::remove(cleanQuery, ' ').begin(), cleanQuery.end());
    return cleanQuery;
}

Core::~Core() = default;