#include <regex>
#include <string>
#include <iostream>

using namespace std::string_literals;

bool is_valid_email(const std::string& email) {
    auto pattern = R"(^[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,}$)"s;
    auto rx = std::regex{pattern, std::regex_constants::icase};
    return std::regex_match(email, rx);
};

int main() {
    auto test_email = [](const std::string& email) {
        std::cout << email
                  << " : is "
                  << (is_valid_email(email) ? "valid." : "not valid")
                  << "\n";
    };

    test_email("hans.muster@gmail.com"s);
    test_email("HANS.Muster@gmail.com"s);
    test_email("HANS.Muster@gmail.co.uk"s);
    test_email("Hans@Muster@gmail.c"s);
    test_email("HANS.Muster@gmail"s);
    return 0;
}
