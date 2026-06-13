/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:31:47 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:31:49 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "color.hpp"

//#####################################################################
// ---- zentrale Validierung des Ranges 
//#####################################################################
void Bureaucrat::validateGradeOrThrow(int grade) 
{
    if (grade < HIGHEST_GRADE)  throw Bureaucrat::GradeTooHighException();
    if (grade > LOWEST_GRADE)   throw Bureaucrat::GradeTooLowException();
}

//####################################################################
// ---- Konstruktoren / Canonical Form 
//####################################################################
Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name), _grade(grade)
{
    validateGradeOrThrow(_grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const& other)
: _name(other._name), _grade(other._grade)
{
    validateGradeOrThrow(_grade);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
    if (this != &other)
    {
        _grade = other._grade;
        validateGradeOrThrow(_grade);
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

//#####################################################################
// ---- Getter 
//#####################################################################
const std::string& Bureaucrat::getName() const { return _name; }
int                Bureaucrat::getGrade() const { return _grade; }

//#####################################################################
// ---- Grade-Modifikatoren 
//#####################################################################
void Bureaucrat::incrementGrade()
{
    validateGradeOrThrow(_grade - 1);
    _grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    validateGradeOrThrow(_grade + 1);
    _grade += 1;
}

//#####################################################################
// ---- Exceptions 
//#####################################################################
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat: grade too high (must be >= 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat: grade too low (must be <= 150)";
}

//#####################################################################
// -------- ex01: signForm 
//#####################################################################
void Bureaucrat::signForm(AForm& form) const
{
    try {
        form.beSigned(*this);
        std::cout << BRIGHT_GRN << _name << " signed " 
                  << form.getName() << RST << "\n";
    }
    catch (const std::exception& e) {
        std::cout << BRIGHT_RED << _name << " couldn't sign "
                  << form.getName() << " because " << e.what() 
                  << RST << "\n";
    }
}

//#####################################################################
// -------- ex02: executeForm 
//#####################################################################
void Bureaucrat::executeForm(AForm const& form) const
{
    try {
        form.execute(*this);
        std::cout << BRIGHT_GRN << _name << " executed "
                  << form.getName() << RST << "\n";
    }
    catch (const std::exception& e) {
        std::cout << BRIGHT_RED << _name << " couldn't execute "
                  << form.getName() << " because " << e.what()
                  << RST << "\n";
    }
}

//#####################################################################
// ---- Ausgabeoperator 
//#####################################################################
std::ostream& operator<<(std::ostream& os, Bureaucrat const& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}