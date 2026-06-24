#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>


int main()
{

    std::cout << GREEN << "\n--- Test 1: Create valid Bureaucrat and Form --- " << RESET << std::endl;
    try
    {
        Form testform; //test default
        std::cout << testform << std::endl;
        std::cout << "Create Boss with grade 2." << std::endl;
        Bureaucrat boss("Boss", 2);
        std::cout << "Check req. sign grade and sign form.\n" << std::endl;
        boss.signForm(testform);
        std::cout << BLUE << testform << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << GREEN << "\n--- Test 2: Bureaucrat unable to sign Form --- " << RESET << std::endl;
    std::cout << "Create a form with Required Sign Grade 1" << std::endl;
    Form important_form("Important Form", 1, 1);
    std::cout << important_form << std::endl;
    try
    {        
        std::cout << "Create Pleb with grade 149." << std::endl;
        Bureaucrat pleb("Pleb", 149);
        std::cout << "Check req. sign grade and sign form.\n" << std::endl;
        pleb.signForm(important_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\nForm Status:" << std::endl;
    std::cout << important_form << std::endl;

    std::cout << GREEN << "\n--- Test 3: Invalid Form Test --- " << RESET << std::endl;
    try
    {
        std::cout << "Sign Grade = 151 (should throw too low exception)." << std::endl;
        Form invalid("invalid", 151, 150);
        std::cout << invalid << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    std::cout << GREEN << "\n--- Test 4: Invalid Form Test --- " << RESET << std::endl;
    try
    {
        std::cout << "Sign Grade = 0 (should throw too high exception)." << std::endl;
        Form invalid("invalid", 0, 150);
        std::cout << invalid << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    std::cout << GREEN << "\n--- Test 5: Invalid Exec Grade Test --- " << RESET << std::endl;
    try
    {
        std::cout << "Exec Grade = 151 (should throw too low exception)." << std::endl;
        Form invalid("invalid_exec", 50, 151); 
        std::cout << invalid << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    
    std::cout << GREEN << "\n--- Test 6: Orthodox Canonical Form Test --- " << RESET << std::endl;
    try
    {
        Form original("Original", 42, 42);
        std::cout << original << std::endl;
        Bureaucrat boss("Boss", 1);
        boss.signForm(original); // Sign the original

        std::cout << "\nCreating a copy via Copy Constructor..." << std::endl;
        Form copy(original);
        std::cout << "Copy status:\n" << copy << std::endl;

        std::cout << "\nCreating a new un-signed form..." << std::endl;
        Form assigned("Assigned", 100, 100);
        std::cout << "Before assignment:\n" << assigned << std::endl;

        std::cout << "\nTry: assigned = original" << std::endl;
        assigned = original; 
        std::cout << "After assignment (Form name and grades don't change only if Signed):\n" << assigned << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }


    std::cout << GREEN << "\n--- Test 7: Copy and Sign Test --- " << RESET << std::endl;
    try
    {
        Form original("Original", 42, 42);
        std::cout << original << std::endl;
        std::cout << "Create Boss with grade 1." << std::endl;
        Bureaucrat boss("Boss", 1);

        std::cout << "\nCreating a copy via Copy Constructor..." << std::endl;
        Form copy(original);
        std::cout << "Copy status:\n" << copy << std::endl;
        std::cout << "Boss signs original" << std::endl;
        boss.signForm(original); // Sign the original
        std::cout << "Original status:\n" << original << std::endl;
        std::cout << "Copy status:\n" << copy << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    return (0);
}