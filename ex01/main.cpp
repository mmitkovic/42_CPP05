#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form b;
    b.setGrade(1000);
    try {
        b.getGrade();
    } catch (std::exception &e) {
        std::cerr << "----" << e.what() << std::endl;
    }
}