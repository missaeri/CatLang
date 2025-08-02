#include "parser.hpp"
#include "rules.hpp"
#include <iostream>
#include <unordered_map>
#include <regex>
#include <vector>
#include <functional>

std::unordered_map<std::string, std::string> variables;

std::string interpolate(const std::string& input) {
    std::string output = input;
    static const std::regex interp(R"(&(\w+))", std::regex::ECMAScript | std::regex::optimize);
    std::smatch match;
    while (std::regex_search(output, match, interp)) {
        std::string name = match[1];
        std::string value = variables.count(name) ? variables[name] : "";
        output.replace(match.position(0), match.length(0), value);
    }
    return output;
}

void parseLine(const std::string& line) {
    std::smatch match;

    static const std::vector<std::pair<const std::regex*, std::function<void()>>> handlers = {
        {&RULE_SAY_INTERPOLATED, [&]() {
            std::cout << interpolate(match[1]) << "\n";
        }},
        {&RULE_SAY, [&]() {
            std::cout << match[1] << "\n";
        }},
        {&RULE_STRING, [&]() {
            variables[match[1]] = match[2];
        }},
        {&RULE_CHAR, [&]() {
            variables[match[1]] = match[2];
        }},
        {&RULE_NUM, [&]() {
            variables[match[1]] = match[2];
        }},
        {&RULE_DECIMAL, [&]() {
            variables[match[1]] = match[2];
        }},
        {&RULE_ARRAY, [&]() {
            variables[match[1]] = "[array]";
        }},
        {&RULE_LIST, [&]() {
            variables[match[1]] = "[list]";
        }},
    };

    for (const auto& [regexPtr, handler] : handlers) {
        if (std::regex_match(line, match, *regexPtr)) {
            handler();
            return;
        }
    }

    std::cerr << "Unknown syntax: " << line << "\n";
}