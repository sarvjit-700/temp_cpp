/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:08:58 by ssukhija          #+#    #+#             */
/*   Updated: 2026/06/24 19:08:58 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string   _formName;
        bool                _isSigned;
        const unsigned int  _signGrade; //required Sign Grade
        const unsigned int  _execGrade; //required Exec Grade

    public:
        AForm();
        AForm(std::string formName, unsigned int reqSG, unsigned int reqEG);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();

        std::string     getAFormName() const;
        bool            getIsSigned()const;
        unsigned int    getReqSG()const;
        unsigned int    getReqEG()const;
        void            beSigned(const Bureaucrat& b);
        virtual void    execute(Bureaucrat const & executor) const = 0;
        
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

        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif