/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:04:17 by ssukhija          #+#    #+#             */
/*   Updated: 2026/06/21 13:04:17 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _formName("default_form"), _isSigned(false), 
    _signGrade(150), _execGrade(150) 
{
    std::cout << GREEN << "Form: [" << this->getFormName() << "] created." 
        << RESET << std::endl;
}

Form::Form(std::string formName, unsigned int reqSG, unsigned int reqEG) :
     _formName(formName), _isSigned(false), _signGrade(reqSG), _execGrade(reqEG)
{
    if (reqSG < 1 || reqEG < 1)
        throw Form::GradeTooHighException();
    if (reqSG > 150 || reqEG > 150)
        throw Form::GradeTooLowException();
    std::cout << GREEN << "Form: [" << this->getFormName() << "] created." 
        << RESET << std::endl;
}

Form::Form(const Form& copy) : 
    _formName(copy._formName), _isSigned(copy._isSigned),
    _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{}

Form &Form::operator=(const Form& copy)
{
    if (this != &copy)
    {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getFormName() const
{
    return (this->_formName);
}

bool    Form::getIsSigned() const
{
    return (this->_isSigned);
}

unsigned int Form::getReqSG() const
{
    return (this->_signGrade);
}

unsigned int Form::getReqEG() const
{
    return (this->_execGrade);
}

const char*    Form::GradeTooHighException::what() const throw()
{
    return ("Form Exception : Grade Too High");
}

const char*     Form::GradeTooLowException::what() const throw()
{
    return ("Form Exception : Grade Too Low");
}

void    Form::beSigned(const Bureaucrat& b)
{
    //if b_g = 2 sign_grade should be 2 or more
    if (this->_signGrade >= b.getGrade())
        this->_isSigned = true;    
    else
        throw Form::GradeTooLowException();    
}

std::ostream&   operator<<(std::ostream& os, const Form& f)
{
    std::string sign;
    if (f.getIsSigned())
        sign = "Yes";
    else
        sign = "No";

    os << YELLOW << "*** FORM: " << f.getFormName() << " ***" 
        << "\nReq Sign Grade : " << f.getReqSG()
        << "\nReq. Execute Grade : " << f.getReqEG()
        << "\nSigned : " << sign << RESET << std::endl;
    return os;
}