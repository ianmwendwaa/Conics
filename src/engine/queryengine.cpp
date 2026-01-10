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
    cleanQuery.erase(std::remove(cleanQuery.begin(), cleanQuery.end(), ' '), cleanQuery.end());
    std::transform(cleanQuery.begin(), cleanQuery.end(), cleanQuery.begin(), ::tolower);
    bool takeCircleRoadMap = cleanQuery.find("circle") != std::string::npos;
    bool takeParabolaRoadMap = cleanQuery.find("parabola") != std::string::npos;
    bool takeHyperbolaRoadMap = cleanQuery.find("hyperbola") != std::string::npos;
    bool takeEllipseRoadMap = cleanQuery.find("ellipse") != std::string::npos;

    // Invoke the respective engine parsers to help ascertain the operation to be done, and expected results
    if(takeCircleRoadMap){
        // Load circle parser

        operationFound = true;
    }
    if(takeParabolaRoadMap){
        // Load Parabola parser
        operationFound = true;
    }
    if(takeHyperbolaRoadMap){
        // Load Hyperbola parser
        operationFound = true;
    }
    if(takeEllipseRoadMap){
        // Load Hyperbola parser
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
