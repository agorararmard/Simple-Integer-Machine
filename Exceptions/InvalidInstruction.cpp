#include<stdexcept>
#include <string>
class InvalidInstruction : public std::runtime_error
{
    public:
    explicit InvalidInstruction(const std::string& instruction,const std::string& line):std::runtime_error("Invalid instruction "+ instruction+" at line" + line){};
};
