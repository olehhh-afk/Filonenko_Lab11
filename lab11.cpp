#include <iostream>
#include <string>
#include <regex>

struct Employee {
    std::string name;
    std::string position;
    std::string identificationCode;

    Employee(const std::string& n, const std::string& p, const std::string& id) 
        : name(n), position(p), identificationCode(id) {}

    std::string extractBirthDate() const {
        std::regex pattern(R"((\d{2})(\d{2})(\d{2}))");
        std::smatch match;
        if (std::regex_search(identificationCode, match, pattern)) {
            return match[1].str() + "." + match[2].str() + ".19" + match[3].str();
        }
        return "Invalid Code";
    }
};

int main() {
    Employee emp("Oleh", "Manager", "1203987654321");
    std::cout << emp.extractBirthDate() << std::endl;
    return 0;
}
