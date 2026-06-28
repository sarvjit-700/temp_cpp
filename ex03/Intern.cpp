/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:33:26 by ssukhija          #+#    #+#             */
/*   Updated: 2026/06/28 16:33:26 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy)
{
    *this = copy;
}

Intern& Intern::operator=(const Intern& copy)
{
    (void)copy;
    return *this;
}

Intern::~Intern() {}

AForm*    Intern::makeForm(std::string formName, std::string target)
{
    int i = 0;

    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    while (i < 3)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            switch (i)
            {
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
            }
        }
        i++;
    }
    std::cout << RED << "Error: Intern cannot create '" 
        << formName << "' because it does not exist." << RESET << std::endl;
    return NULL;
}