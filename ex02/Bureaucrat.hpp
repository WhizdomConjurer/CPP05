/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:31:27 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:31:52 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"   // <-- NEU: für executeForm

// 42-Modul-Konvention
static const int HIGHEST_GRADE = 1;
static const int LOWEST_GRADE  = 150;

class AForm; // forward declaration

class Bureaucrat 
{
public:
    //######################################################
    // -- Canonical Form (ohne öffentlichen Default-Ctor) --
    //######################################################
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(Bureaucrat const& other);
    Bureaucrat& operator=(Bureaucrat const& other);
    ~Bureaucrat();

    // Getter
    const std::string& getName() const;
    int                getGrade() const;

    // Grade-Modifikatoren
    void incrementGrade();
    void decrementGrade();

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // --- ex01: Form unterschreiben ---
    void signForm(AForm& form) const;

    // --- ex02: Form ausführen ---
    void executeForm(AForm const& form) const;

private:
    Bureaucrat(); // verboten (C++98-Stil)

    const std::string _name;
    int               _grade;

    static void validateGradeOrThrow(int grade);
};

// Ausgabeoperator
std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif // BUREAUCRAT_HPP