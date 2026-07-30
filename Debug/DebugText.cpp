#include "DebugText.h"

#include <iostream>

void DebugText::Print(const std::string& text)
{
    std::cout
        << "[Info] "
        << text
        << std::endl;
}

void DebugText::Warning(const std::string& text)
{
    std::cout
        << "[Warning] "
        << text
        << std::endl;
}

void DebugText::Error(const std::string& text)
{
    std::cerr
        << "[Error] "
        << text
        << std::endl;
}