/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:02:12 by ssukhija          #+#    #+#             */
/*   Updated: 2026/06/24 19:02:12 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _formName("default_form"), _isSigned(false), 
    _signGrade(150), _execGrade(150) 
{
    std::cout << GREEN << "AForm: [" << this->getAFormName() << "] created." 
        << RESET << std::endl;
}

AForm::AForm(std::string formName, unsigned int reqSG, unsigned int reqEG) :
     _formName(formName), _isSigned(false), _signGrade(reqSG), _execGrade(reqEG)
{
    if (reqSG < 1 || reqEG < 1)
        throw AForm::GradeTooHighException();
    if (reqSG > 150 || reqEG > 150)
        throw AForm::GradeTooLowException();
    std::cout << GREEN << "AForm: [" << this->getAFormName() << "] created." 
        << RESET << std::endl;
}

AForm::AForm(const AForm& copy) : 
    _formName(copy._formName), _isSigned(copy._isSigned),
    _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{}

AForm &AForm::operator=(const AForm& copy)
{
    if (this != &copy)
    {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getAFormName() const
{
    return (this->_formName);
}

bool    AForm::getIsSigned() const
{
    return (this->_isSigned);
}

unsigned int AForm::getReqSG() const
{
    return (this->_signGrade);
}

unsigned int AForm::getReqEG() const
{
    return (this->_execGrade);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm Exception : Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm Exception : Grade Too Low");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("AForm Exception : This form has not been signed!");
}

void    AForm::beSigned(const Bureaucrat& b)
{
    //if b_g = 2 sign_grade should be 2 or more
    if (this->_signGrade >= b.getGrade())
        this->_isSigned = true;    
    else
        throw AForm::GradeTooLowException();    
}

std::ostream&   operator<<(std::ostream& os, const AForm& f)
{
    std::string sign;
    if (f.getIsSigned())
        sign = "Yes";
    else
        sign = "No";

    os << YELLOW << "*** AForm: " << f.getAFormName() << " ***" 
        << "\nReq Sign Grade : " << f.getReqSG()
        << "\nReq. Execute Grade : " << f.getReqEG()
        << "\nSigned : " << sign << RESET << std::endl;
    return os;
}