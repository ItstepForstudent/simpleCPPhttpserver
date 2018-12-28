//
// Created by arturmamedov on 28.12.18.
//

#include "string.h"
bool util::string::startsWith(const std::string &str, const std::string &needle){
    return str.length()>=needle.length() && str.substr(0,needle.length())==needle;
}
bool util::string::endsWith(const std::string &str, const std::string &needle){
    return str.length()>=needle.length() && str.substr(str.length()-needle.length())==needle;
}