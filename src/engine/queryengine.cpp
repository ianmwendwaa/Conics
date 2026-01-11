#include "queryengine.h"
#include <algorithm>
#include <string>
#include <iostream>

QueryEngine::QueryEngine() {
    circle = new Circle;
    parabola = new Parabola;
    hyperbola = new Hyperbola;
}



bool QueryEngine::parseUserQuery(const std::string& query) {
    // Clean and normalize the query
    std::string cleanQuery = query;
    cleanQuery.erase(std::ranges::remove(cleanQuery, ' ').begin(), cleanQuery.end());
    std::ranges::transform(cleanQuery, cleanQuery.begin(), ::tolower);
    const bool takeCircleRoadMap = cleanQuery.find("circle") != std::string::npos;
    const bool takeParabolaRoadMap = cleanQuery.find("parabola") != std::string::npos;
    const bool takeHyperbolaRoadMap = cleanQuery.find("hyperbola") != std::string::npos;
    const bool takeEllipseRoadMap = cleanQuery.find("ellipse") != std::string::npos;

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
    return operationFound;
}

QueryEngine::~QueryEngine()
{
    delete circle;
    delete parabola;
    delete hyperbola;
}
