#include "circle.h"
#include "../../core/core.h"

#include <regex>
#include <iostream>
#include <src/engine/queryengine.h>

#include "../../types/types.h"

namespace Circle {
    void ParseQuery(const std::string& query, EquationForm format) {
        std::cout << "It works!";
    }
}
// void Circle::ParseQuery(const std::string& query, EquationForm format) {
//     /* Circle equation can be given in multiple forms like:
//      * 1. General form - x2 + y2 + 2gx + 2fy + c = 0
//      * 2. Standard form - (x−x1)2+(y−y1)2=r2 where (x1,y1) rep. centre
//      * 3. Polar form - (rcosθ)2 + (rsinθ)2 = p2
//      * 4. Parametric form - x2 + y2 + 2hx + 2ky + C = 0 where x = -h + rcosθ and y = -k + rsinθ
//      */
//
//     // Normalize the query for predictability
//     const std::string equation = Core::NormalizeQuery(query);
//     // Part 1: General form
//     const std::regex generalFormRgx(R"(([+-]?\d+)x2([+-]\d+)y2([+-]\d+)x([+-]\d+)y([+-]\d+)=0)");
//     std::smatch m_GF;
//
//     if (std::regex_match(equation, m_GF, generalFormRgx)) {
//         // this->x_g = std::stod(matches[0].str());
//         // this->y_g = std::stod(matches[1].str());
//         // this->tg_g = std::stod(matches[3].str());
//         // this->tf_g = std::stod(matches[4].str());
//         // this->c_g = std::st
//         // od(matches[5].str());
//     }
//     // Part 2: Standard form
//     const std::regex stdFormRgx(R"(\(x[+-]\d+\)2+\(y[+-]\d+)2=\d+)");
//     if (std::smatch m_SF; std::regex_match(query, m_SF, stdFormRgx)) {
//         // Invoke
//     }
//
//
// }

