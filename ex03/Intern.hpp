#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
class AForm;

class Intern {
public:
    Intern();
    Intern(const Intern& src);
    Intern& operator=(const Intern& src);
    ~Intern();
    AForm* makeForm(const std::string& nameForm, const std::string& targetForm);
};

#endif
