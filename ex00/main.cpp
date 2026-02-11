#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b("B", -1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    Bureaucrat v("V", 1);
    try {
        checkGrade(v.getGrade());
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << v << std::endl;
    v.setGrade(1000);
    std::cout << v << std::endl;
}