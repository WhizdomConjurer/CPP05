/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:03:34 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/23 17:21:42 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// -------- Exceptions what() --------
const char* Form::GradeTooHighException::what() const throw() 
{
    return "Grade too high";
}
const char* Form::GradeTooLowException::what() const throw() 
{
    return "Grade too low";
}

// -------- Konstruktoren --------
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
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

Form::Form(const Form& other)
: _name(other._name),
  _isSigned(other._isSigned),
  _gradeToSign(other._gradeToSign),
  _gradeToExecute(other._gradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
    if (this != &other) {
        // _name, _gradeToSign, _gradeToExecute sind const -> bleiben unverändert
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}

// -------- Getter --------
const std::string& Form::getName() const { return _name; }
bool  Form::isSigned() const { return _isSigned; }
int   Form::getGradeToSign() const { return _gradeToSign; }
int   Form::getGradeToExecute() const { return _gradeToExecute; }

// -------- Logik: beSigned --------
// Ein Bureaucrat darf unterschreiben, wenn sein Grade <= _gradeToSign (1 ist top).
void Form::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() <= _gradeToSign) 
    {
        _isSigned = true;
    } 
    else 
    {
        throw GradeTooLowException();
    }
}

// -------- Stream-Operator --------
std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << MAG << "Form \"" << f.getName() << "\"" << RST
       << " [signed: " << (f.isSigned() ? (std::string(GRN) + "yes" + RST)
                                        : (std::string(RED) + "no" + RST))
       << ", gradeToSign: " << YEL << f.getGradeToSign() << RST
       << ", gradeToExecute: " << YEL << f.getGradeToExecute() << RST
       << "]";
    return os;
}
