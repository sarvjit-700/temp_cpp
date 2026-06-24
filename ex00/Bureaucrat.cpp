/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:07:48 by ssukhija          #+#    #+#             */
/*   Updated: 2026/06/17 16:07:48 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) 
{
    std::cout << GREEN << this->getName() << ", bureaucrat grade "
         << this->getGrade() << "." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();

    this->_grade = grade;
    std::cout << BLUE << this->getName() << ", bureaucrat grade " 
        << this->getGrade() << "." <<  RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : 
    _name(copy._name), _grade(copy._grade)
{
    std::cout << GREEN << "Copy created\n" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if (this != &copy)
    {
        this->_grade = copy._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string     Bureaucrat::getName() const
{
    return (this->_name);
}

unsigned int    Bureaucrat::getGrade() const
{
    return (this->_grade);
}


void Bureaucrat::incrementGrade() // grade must be higher than 2 and <= than 150 before inc
{
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat exception: Grade is too high to increment";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat exception: Grade is too low to decrement";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << BLUE << b.getName() << ", bureaucrat grade " 
        << b.getGrade() << "." << RESET << std::endl;
    return os;
}
