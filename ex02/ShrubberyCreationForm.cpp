#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class AForm;

ShrubberyCreationForm::ShrubberyCreationForm() {
    std::cout << "[c]Shrubbery" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", target, 145, 137) {
    std::cout << "[p][c]Shrubbery" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {
    std::cout << "[c][c]Shrubbery" << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    std::cout << "[c][a][o]Shrubbery" << std::endl;
    if (this != &src) {
        // this->setIsSigned(src.getIsSigned());
        AForm::operator=(src);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "~Shrubbery" << std::endl;
}

// exec
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSigned();
    if (executor.getGrade() > 137)
        throw ShrubberyCreationForm::GradeTooLowException();
    std::ofstream file;
    const std::string filename = this->getTarget() + "_shrubbery.txt";
    file.open(filename.c_str());
    if (!file.is_open()) {
        throw ShrubberyCreationForm::FileOpenException();
    }
    file << "     *     " << std::endl;
    file << "    ###    " << std::endl;
    file << "   #####   " << std::endl;
    file << "  #######  " << std::endl;
    file << " ######### " << std::endl;
    file << "     |     " << std::endl;
    file << "    ---    " << std::endl;
    file.close();
}
