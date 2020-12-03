#pragma once

template <typename T>
void print(T value);

void print_ascii(std::string value);

void findAndReplaceAll(std::string& data, std::string to_search, std::string replace_str);

std::string morse_to_en(std::string filepath);