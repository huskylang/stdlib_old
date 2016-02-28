#include <string>

#include "../src/parser/inc/parser.hpp"
#include "../src/parser/datatypes/inc/abstract.hpp"
#include "console/console.hpp"

#include "inc/router.hpp"

using namespace husky;

/*
 * Runs function from the stdlib
 *
 * @param len, length of the arglist
 *
 */
datatypes::AbstractDataType *stdlib::run(
    Parser *parser, std::string funexpr, datatypes::AbstractDataType **arglist, int len
)
{
    int delimiter = funexpr.find(":"); // find an index of ':' delimiter in function expression

    datatypes::AbstractDataType *retval; // trick with a compiler

    std::string modname = funexpr.substr(0, delimiter); // take substring from start to delimiter

    if (modname == "cs") { // console module
        return stdlib::console::router(
            parser, funexpr.substr(delimiter + 1, funexpr.length()), modname, arglist, len
        );
    } else {
        // throw module not found error

        parser->outhandler->error(
            "(stdlib, module finder)", "module '" + modname + "' not found",
            parser->line, parser->linen, parser->linei
        );

        return retval;
    }
}