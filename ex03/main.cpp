#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    std::cout << GREEN << "\n--- Setting up the Office --- " << RESET << std::endl;
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1); // Grade 1 can sign and execute everything

    std::cout << GREEN << "\n--- Test 1: Intern creates Shrubbery --- " << RESET << std::endl;
    AForm* rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
    
        delete rrf; 
    }

    std::cout << GREEN << "\n--- Test 2: Intern creates Robotomy --- " << RESET << std::endl;
    AForm* rrf2 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf2)
    {
        std::cout << *rrf2 << std::endl;
        boss.signForm(*rrf2);
        boss.executeForm(*rrf2);
        
        delete rrf2;
    }

    std::cout << GREEN << "\n--- Test 3: Intern creates Presidential Pardon --- " << RESET << std::endl;
    AForm* rrf3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (rrf3)
    {
        std::cout << *rrf3 << std::endl;
        boss.signForm(*rrf3);
        boss.executeForm(*rrf3);
        
        delete rrf3;
    }

    std::cout << GREEN << "\n--- Test 4: Intern tries to create a Fake Form --- " << RESET << std::endl;
    AForm* fake = someRandomIntern.makeForm("coffee making", "Kitchen");
    if (fake)
    {
        // This block should never execute
        boss.signForm(*fake);
        boss.executeForm(*fake);
        delete fake;
    }
    
    std::cout << GREEN << "\n--- End of tests --- " << RESET << std::endl;

    return (0);
}