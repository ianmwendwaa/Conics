#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>

class Circle
{
public:
    Circle();

    enum class QueryType {
        FIND_EQUATION, FIND_INTERSECTION, FIND_CENTRE, FIND_RADIUS_LENGTH,
        FIND_AREA_CIRCUMFERENCE, FIND_CONGRUENCE_RATIO, FIND_RADIUS_INNER_OUTER_CIRCLES,
        UNKNOWN
    };
    // static QueryType findUserIntent(const std::string& query);
    // bool parseUserQuery(const std::string& query);
    void AnalyzeCircleEquation(const std::string& query);
private:
    // Variables for the general form:
    double x_g{}, y_g{}, tg_g{}, tf_g{}, c_g{};
};

#endif // CIRCLE_H
