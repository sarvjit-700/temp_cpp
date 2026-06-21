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

Form::Form() : _formName("default_form"), _isSigned(0), 
    _signGrade(150), _execGrade(150) 
{
    std::cout << GREEN << this->getFormName() << " created." 
        << RESET << std::endl;
}

Form::Form(std::string formName, unsigned int reqSG, unsigned int reqEG) :
     _formName(formName), _isSigned(0), _signGrade(reqSG), _execGrade(reqEG)
{
    if (reqSG < 1 || reqEG < 1)
        throw Form::GradeTooHighException();
    if (reqSG > 150 || req > 150)
        throw Form::GradeTooLowException();

    // this->_signGrade = reqSG;
    // this->_execGrade = reqEG;
}

Form::Form(const Form& copy)
{
    *this = copy;
}

Form &Form::operator=(const Form& copy)
{
    if (this != &copy)
    {
        this->_isSigned = copy._isSigned;
        this->_signGrade = copy._signGrade;
        this->_execGrade = copy._execGrade;
    }
    return *this;
}


std::string Form::getFormName() const
{
    return (this->_formName);
}

bool    Form::getIsSigned()
{
    return (this->_isSigned);
}

int Form::getReqSG()
{
    return (this->_signGrade);
}

int Form::getReqEG()
{
    return (this->_execGrade);
}

const char*    Form::GradeTooHighException::what() const throw
{
    return ("Form Exception : Grade Too High");
}

const char*     Form::GradeTooLowException::what() const throw
{
    return ("Form Exception : Grade Too Low");
}

Form    Form::Bureaucrat::beSigned(Bureaucrat& b)
{
    if (this->_signGrade > b->_grade) //if req_sign_grade is lower than b_grade (signGrade is higher)
        throw Form::GradeTooLowException();
    else
        this->_isSigned = 1;
}

std::ostream&   operator<<(std::ostream& os, const Form& f)
{
    os << f.getFormName() << ", required Sign Grade : " << f.getReqSG()
        << ", required Execute Grade : " << f.getReqEG();
    return os;
}