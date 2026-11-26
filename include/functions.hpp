#pragma once
#include <filesystem>
#include <string_view>
void explain(std::string_view note, std::filesystem::filesystem_error const &e);
void init();
