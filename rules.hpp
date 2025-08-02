#ifndef RULES_HPP
#define RULES_HPP

#include <regex>

const std::regex RULE_FUNC_DEF(R"DELIM((String|Num|Decimal|Char)\s+(\w+)\s*\s*\{)DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_RETURN(R"DELIM(return\s+(.*);)DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_FUNC_END(R"DELIM(\})DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_SAY(R"DELIM(say\s+"(.*)";)DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_SAY_INTERPOLATED(R"DELIM(say\s+\$\s*"(.*)";)DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_STRING(R"DELIM(String\s+(\w+)\s*=\s*"(.*)";)DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_CHAR(R"DELIM(Char\s+(\w+)\s*=\s*'(.)';)DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_NUM(R"DELIM(Num\s+(\w+)\s*=\s*(-?\d+);)DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_DECIMAL(R"DELIM(Decimal\s+(\w+)\s*=\s*(-?\d+\.\d+);)DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_ARRAY(R"DELIM(Array\s+(\w+)\s*=\s*\{(.*)\};)DELIM", std::regex::ECMAScript | std::regex::optimize);
const std::regex RULE_LIST(R"DELIM(List\s+(\w+)\s*=\s*\{(.*)\};)DELIM", std::regex::ECMAScript | std::regex::optimize);

#endif