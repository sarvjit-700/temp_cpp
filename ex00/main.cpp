#include "Bureaucrat.hpp"
#include <iostream>


int main()
{

    std::cout << GREEN << "\n--- Test 1: Create valid Bureaucrat and increment grade --- " << RESET << std::endl;
    Bureaucrat test; //test default 
    std::cout << "Create Boss with grade 2." << std::endl;
    Bureaucrat boss("Boss", 2);
    try
    {
        std::cout << "Increment grade." << std::endl;
        boss.incrementGrade();
        std::cout << BLUE << boss << RESET << std::endl;
        std::cout << "Try to increment again..(should throw exeception)" << std::endl;
        boss.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << boss << RESET << std::endl;

    std::cout << GREEN << "\n--- Test 2: Create valid Bureaucrat and decrement grade --- " << RESET << std::endl;
    std::cout << "Create Pleb with grade 149." << std::endl;
    Bureaucrat pleb("Pleb", 149);
    try
    {
        std::cout << "Decrement grade." << std::endl;
        pleb.decrementGrade();
        std::cout << BLUE << pleb << RESET << std::endl;
        std::cout << "Decrement grade again (should throw exeception)." << std::endl;
        pleb.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << pleb << RESET << std::endl;

    std::cout << GREEN << "\n--- Test 3: Invalid Grade Test --- " << RESET << std::endl;
    try
    {
        std::cout << "Create Invalid with grade 151 (should throw exception)." << std::endl;
        Bureaucrat invalid("invalid", 151);
        invalid.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    
    std::cout << GREEN << "\n--- Test 4: Orthodox Canonical Form Test --- " << RESET << std::endl;
    std::cout << "Create bureaucrat with grade 42." << std::endl;
    Bureaucrat original("Original", 42);
    try
    {
        std::cout << "\nCreating a copy via Copy Constructor..." << std::endl;
        Bureaucrat copy(original);
        std::cout << "Copy status:\n" << copy << std::endl;

        std::cout << "Creating a new Bureaucrat..." << std::endl;
        Bureaucrat assigned("Assigned", 100);
        std::cout << "Before assignment:\n" << assigned << std::endl;

        std::cout << "Try: assigned = original" << std::endl;
        assigned = original; 
        std::cout << "After assignment (grade changes to 42, name doesn't change!)\n" << assigned << std::endl;

        std::cout << "Increment copy and compare to original" << std::endl;
        copy.incrementGrade();
        std::cout << "Original: " << original;
        std::cout << "Copy: " << copy << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    return (0);
}