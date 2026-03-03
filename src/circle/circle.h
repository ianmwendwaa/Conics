#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>

#include "../../types/types.h"
#include "src/engine/queryengine.h"
#include <regex>
struct GenCircleData {
    double x_g, y_g, tg_g, tf_g, c_g;
};
struct StdCircleData {
    double x1, x2;
};
enum class Intent {
    FIND_EQUATION, FIND_INTERSECTION, FIND_CENTRE, FIND_RADIUS_LENGTH,
    FIND_AREA_CIRCUMFERENCE, FIND_CONGRUENCE_RATIO, FIND_RADIUS_INNER_OUTER_CIRCLES,
    UNKNOWN
};
class Circle{
public:
    static void ParseQuery(std::string& query, const std::regex& pattern, EquationForm format); // NOLINT(*-redundant-declaration)
    void GeneralForm(std::string& query, const std::regex& pattern);
    void StandardForm(const std::string& query, const std::regex& pattern);
    void PolarForm(const std::string& query, const std::regex& pattern);
    void ParametricForm(const std::string& query, const std::regex& pattern);
private:
    std::string equationQuery;
    // Variables for the general form:
};

#endif // CIRCLE_H
