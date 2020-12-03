#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <cstddef>

template <typename T>
void print(T value) {
    std::cout << value << std::endl;
}

void print_ascii(std::string value) {
    for (char& ch : value) {
        std::cout << (int)ch << " ";
    }
    std::cout << std::endl;
}

void findAndReplaceAll(std::string& data, std::string to_search, std::string replace_str) {
    size_t pos = data.find(to_search);

    while (pos != std::string::npos) {
        data.replace(pos, to_search.size(), replace_str);
        pos = data.find(to_search, pos + replace_str.size());
    }
}

std::string morse_to_en(std::string filepath) {
    std::ifstream file(filepath);

    std::unordered_map<std::string, char> morse_to_en({
        // Alphabets
        {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, {"..-.", 'f'}, {"--.", 'g'},
        {"....", 'h'}, {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'},
        {"---", 'o'}, {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'}, {"..-", 'u'},
        {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'}, {"--..", 'z'},

        // Numbers
        {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, {".....", '5'}, {"-....", '6'},
        {"--...", '7'}, {"---..", '8'}, {"----.", '9'}, {"-----", '0'},

        // Space
        {"~", ' '},
        });

    int line_num = 1;
    std::string line;
    std::string en_source = "";
    std::string symbol;

    while (std::getline(file, line)) {
        symbol = "";
        for (char& ch : line) {
            if (ch == ' ') {
                en_source += morse_to_en[symbol];

                symbol = "";
                continue;
            }
            symbol += ch;
        }

        if (symbol.length() > 0)
            en_source += morse_to_en[symbol];

        line_num++;
        en_source += "\n";
    }

    file.close();

    findAndReplaceAll(en_source, "qt ", "' ");
    findAndReplaceAll(en_source, " qt ", "' ");
    findAndReplaceAll(en_source, " qt", "'");

    std::string en_filepath = filepath.substr(0, filepath.find_last_of(".")) + ".en";

    std::ofstream en_source_file(en_filepath);

    en_source_file << en_source;

    en_source_file.close();

    return en_source;
}