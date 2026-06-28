#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main()
{
    // Seed the random number generator for RobotomyRequestForm
    srand(time(NULL));

    std::cout << GREEN << "\n--- Test 1: Create ShrubberyForm, Sign and Execute  --- " << RESET << std::endl;
    std::cout << "Create Boss with grade 1" << std::endl;
    Bureaucrat boss("Boss", 1);
    std::cout << "Create Shrubbery form 'home' req. grades : sign 145, exec 137" << std::endl;
    ShrubberyCreationForm home("home");
    std::cout << home << std::endl;
    try
    {
        std::cout << "Check Boss can sign form, and sign." << std::endl;
        boss.signForm(home);
        std::cout << "Check Boss can execute form, and execute." << std::endl;
        boss.executeForm(home);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << home << std::endl;

    std::cout << GREEN << "\n--- Test 2: Create ShrubberyForm, fail signing  --- " << RESET << std::endl;
    std::cout << "Create Pleb with grade 150" << std::endl;
    Bureaucrat pleb("Pleb", 150);
    std::cout << "Create Shrubbery form 'shop' req. grades : sign 145, exec 137" << std::endl;
    ShrubberyCreationForm shop("shop");
    std::cout << shop << std::endl;
    try
    {
        std::cout << "Check Pleb can sign form (should fail)." << std::endl;
        pleb.signForm(shop);
        std::cout << "Check Pleb can execute form, and execute." << std::endl;
        pleb.executeForm(shop);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << shop << std::endl;

    std::cout << GREEN << "\n--- Test 3: Create ShrubberyForm, fail execute  --- " << RESET << std::endl;
    std::cout << "Create Middling with grade 140" << std::endl;
    Bureaucrat middling("Middling", 140);
    std::cout << shop << std::endl;
    try
    {
        std::cout << "Check Middling can sign form and then sign." << std::endl;
        middling.signForm(shop);
        std::cout << "Check Middling can execute form (should fail)." << std::endl;
        middling.executeForm(shop);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << shop << std::endl;

    std::cout << GREEN << "\n--- Test 4: Create RobotomyForm, Sign and Execute --- " << RESET << std::endl;
    std::cout << "Create Mechanic with grade 40" << std::endl;
    Bureaucrat mechanic("Mechanic", 40);
    std::cout << "Create Robotomy form 'Bender' req. grades : sign 72, exec 45" << std::endl;
    RobotomyRequestForm bender("Bender");
    std::cout << bender << std::endl;
    try
    {
        std::cout << "Check Mechanic can sign form, and sign." << std::endl;
        mechanic.signForm(bender);
        std::cout << "Check Mechanic can execute form, and execute (50% chance of success)." << std::endl;
        mechanic.executeForm(bender);
        
        // Optional: Run it a second time to show the randomness!
        std::cout << "\nExecuting a second time to test the 50/50 randomness..." << std::endl;
        mechanic.executeForm(bender);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << bender << std::endl;

    std::cout << GREEN << "\n--- Test 5: Create RobotomyForm, fail execute --- " << RESET << std::endl;
    std::cout << "Create Intern with grade 60" << std::endl;
    Bureaucrat intern("Intern", 60);
    std::cout << "Create Robotomy form 'Claptrap' req. grades : sign 72, exec 45" << std::endl;
    RobotomyRequestForm claptrap("Claptrap");
    std::cout << claptrap << std::endl;
    try
    {
        std::cout << "Check Intern can sign form and then sign." << std::endl;
        intern.signForm(claptrap);
        std::cout << "Check Intern can execute form (should fail)." << std::endl;
        intern.executeForm(claptrap);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << claptrap << std::endl;

    std::cout << GREEN << "\n--- Test 6: Create PresidentialForm, Sign and Execute --- " << RESET << std::endl;
    std::cout << "Create President with grade 1" << std::endl;
    Bureaucrat president("President", 1);
    std::cout << "Create Presidential form 'Arthur Dent' req. grades : sign 25, exec 5" << std::endl;
    PresidentialPardonForm arthur("Arthur Dent");
    std::cout << arthur << std::endl;
    try
    {
        std::cout << "Check President can sign form, and sign." << std::endl;
        president.signForm(arthur);
        std::cout << "Check President can execute form, and execute." << std::endl;
        president.executeForm(arthur);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << arthur << std::endl;

    std::cout << GREEN << "\n--- Test 7: Create PresidentialForm, fail sign --- " << RESET << std::endl;
    std::cout << "Create Manager with grade 26" << std::endl;
    Bureaucrat manager("Manager", 26);
    std::cout << "Create Presidential form 'Marvin' req. grades : sign 25, exec 5" << std::endl;
    PresidentialPardonForm marvin("Marvin");
    std::cout << marvin << std::endl;
    try
    {
        std::cout << "Check Manager can sign form (should fail)." << std::endl;
        manager.signForm(marvin);
        std::cout << "Check Manager can execute form (will not reach here)." << std::endl;
        manager.executeForm(marvin);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << marvin << std::endl;

    return (0);
}