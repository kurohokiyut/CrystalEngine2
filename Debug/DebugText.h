#pragma once

#include <string>

class DebugText
{
public:

    static void Print(const std::string& text);

    static void Warning(const std::string& text);

    static void Error(const std::string& text);
};