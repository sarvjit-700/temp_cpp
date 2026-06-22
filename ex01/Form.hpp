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
#include <iostream>
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
        Form(std::string formName, unsigned int reqSG, unsigned int reqEG);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        std::string     getFormName() const;
        bool            getIsSigned()const;
        unsigned int    getReqSG()const;
        unsigned int    getReqEG()const;

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

        void    beSigned(const Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif