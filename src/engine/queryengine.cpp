#include "queryengine.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

QueryEngine::QueryEngine() {
    circle = std::make_unique<Circle>();
    parabola = std::make_unique<Parabola>();
    hyperbola = std::make_unique<Hyperbola>();
}

QueryEngine::QueryType QueryEngine::parseUserQuery(const std::string& query) {
    // Clean and normalize the query
    std::string cleanQuery = query;
    cleanQuery.erase(std::ranges::remove(cleanQuery, ' ').begin(), cleanQuery.end());
    std::ranges::transform(cleanQuery, cleanQuery.begin(), ::tolower);
    const bool takeCircleRoadMap = cleanQuery.find("circle") != std::string::npos;
    const bool takeParabolaRoadMap = cleanQuery.find("parabola") != std::string::npos;
    const bool takeHyperbolaRoadMap = cleanQuery.find("hyperbola") != std::string::npos;
    const bool takeEllipseRoadMap = cleanQuery.find("ellipse");

    // Map each keyword with its respective engine
    static std::map<std::string, QueryType> queryTypes = {
        {"circle",QueryType::CIRCLE_ENGINE},
            {"parabola", QueryType::PARABOLA_ENGINE},
            {"hyperbola", QueryType::HYPERBOLA_ENGINE}
        };

    // Invoke the respective engine parsers to help ascertain the operation to be done, and expected results
    if(takeCircleRoadMap){
        // Load circle parser
        std::cout << "Circle data found!";
        operationFound = true;
    }
    if(takeParabolaRoadMap){
        // Load Parabola parser
        std::cout << "Parabola data found!";
        operationFound = true;
    }
    if(takeHyperbolaRoadMap){
        // Load Hyperbola parser
        std::cout << "Hyperbola data found!";
        operationFound = true;
    }
    if(takeEllipseRoadMap){
        // Load Hyperbola parser
        std::cout << "Ellipse data found!";
        operationFound = true;
    }
    if(!operationFound){
        std::cerr << "Could not ascertain the query intent!";
        exit(-1);
    }
    return QueryType::UNKNOWN;
}

QueryEngine::QueryType QueryEngine::ascertainQueryType(const std::string& query) {
    static std::map<std::string, QueryType> queryTypes = {{"circle", QueryType::CIRCLE_ENGINE},
    {"parabola", QueryType::PARABOLA_ENGINE},
    {"hyperbola", QueryType::HYPERBOLA_ENGINE}};

    auto cmd = queryTypes.find(query);
    if (cmd == queryTypes.end()) {
        std::cerr << "Query type not found!";
        // }
        // switch (cmd) {
        //     case QueryType::CIRCLE_ENGINE:
        //
        //
        //     default: ;
        // }
        return QueryType::UNKNOWN;
    }
}


QueryEngine::~QueryEngine()
= default;
