/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:04:20 by ssukhija          #+#    #+#             */
/*   Updated: 2026/06/21 13:04:20 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   _formName;
        bool                _isSigned;
        const unsigned int  _signGrade; //required Sign Grade
        const unsigned int  _execGrade; //required Exec Grade
    public:
        Form();
        Form(std::string formName, bool isSigned, unsigned int reqSG, unsigned int reqEG);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        std::string getFormName() const;
        bool        getIsSigned();
        int         getReqSG();
        int         getReqEG();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        Form    beSigned(Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif