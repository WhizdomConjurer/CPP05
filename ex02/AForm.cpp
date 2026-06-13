/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:22:41 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:31:55 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ========= Exceptions what() ==========
const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm: form is not signed";
}

// ========== Konstruktor ==========
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
: _name(name),
  _isSigned(false),
  _gradeToSign(gradeToSign),
  _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
        throw GradeTooLowException();
}

// ========== Copy ==========
AForm::AForm(AForm const& other)
: _name(other._name),
  _isSigned(other._isSigned),
  _gradeToSign(other._gradeToSign),
  _gradeToExecute(other._gradeToExecute)
{}

// ========== Assignment ==========
AForm& AForm::operator=(AForm const& other)
{
    if (this != &other)
        _isSigned = other._isSigned; // const-Attribute bleiben wie sie sind
    return *this;
}

// ========== Destructor ==========
AForm::~AForm() {}

// ========== Getter ==========
const std::string& AForm::getName() const { return _name; }
bool               AForm::isSigned() const { return _isSigned; }
int                AForm::getGradeToSign() const { return _gradeToSign; }
int                AForm::getGradeToExecute() const { return _gradeToExecute; }

// ========== beSigned ==========
void AForm::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

// ========== execute ==========
void AForm::execute(Bureaucrat const& executor) const
{
    if (_isSigned == false)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();

    // eigentliche Aktion der Unterklasse
    executeAction();
}

// ========== Stream Operator ==========
std::ostream& operator<<(std::ostream& os, AForm const& f)
{
    os << MAG << "AForm \"" << f.getName() << "\"" << RST
       << " [signed: " << (f.isSigned() ? (std::string(GRN) + "yes" + RST)
                                        : (std::string(RED) + "no" + RST))
       << ", gradeToSign: " << YEL << f.getGradeToSign() << RST
       << ", gradeToExecute: " << YEL << f.getGradeToExecute() << RST
       << "]";
    return os;
}
