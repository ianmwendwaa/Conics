#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>

#include "../../types/types.h"
#include "src/engine/queryengine.h"
namespace Circle
{
    struct CircleData {
        double x_g, y_g, tg_g, tf_g, c_g;
    };
    enum class Intent {
        FIND_EQUATION, FIND_INTERSECTION, FIND_CENTRE, FIND_RADIUS_LENGTH,
        FIND_AREA_CIRCUMFERENCE, FIND_CONGRUENCE_RATIO, FIND_RADIUS_INNER_OUTER_CIRCLES,
        UNKNOWN
    };
    void ParseQuery(const std::string& query, const std::regex& pattern, EquationForm format);
    void GeneralForm(const std::string& query, const std::regex& pattern);
    void StandardForm(const std::string& query, const std::regex& pattern);
    void PolarForm(const std::string& query, const std::regex& pattern);
    void ParametricForm(const std::string& query, const std::regex& pattern);
    // Variables for the general form:
};

#endif // CIRCLE_H
