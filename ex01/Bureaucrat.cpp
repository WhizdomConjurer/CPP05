/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:27:44 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/23 17:08:36 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//#####################################################################
// ---- zentrale Validierung des Ranges 
//#####################################################################
void Bureaucrat::validateGradeOrThrow(int grade) 
{
    if (grade < 1)   throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

//####################################################################
// ---- Konstruktoren / Canonical Form 
//####################################################################

// Haupt-Konstruktor: Name+Grade setzen und sofort validieren
Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name), _grade(grade)
{
    validateGradeOrThrow(_grade);
}

// Copy-Konstruktor: 1:1 übernehmen (und sicherheitshalber validieren)
Bureaucrat::Bureaucrat(Bureaucrat const& other)
: _name(other._name), _grade(other._grade)
{
    validateGradeOrThrow(_grade);
}

// Zuweisungsoperator: _name ist const → NICHT zuweisbar, nur _grade
Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) 
{
    if (this != &other) 
    {
        _grade = other._grade;
        validateGradeOrThrow(_grade);
    }
    return *this;
}

// Destruktor: nichts Dynamisches → leer
Bureaucrat::~Bureaucrat() {}

//#####################################################################
// ---- Getter 
//#####################################################################

const std::string& Bureaucrat::getName() const { return _name; }
int                Bureaucrat::getGrade() const { return _grade; }

//#####################################################################
// ---- Modifikatoren 
//#####################################################################

// increment: bessere Note = kleinere Zahl
void Bureaucrat::incrementGrade() 
{
    validateGradeOrThrow(_grade - 1); // erst prüfen…
    _grade -= 1;                      // …dann ändern
}

// decrement: schlechtere Note = größere Zahl
void Bureaucrat::decrementGrade() 
{
    validateGradeOrThrow(_grade + 1);
    _grade += 1;
}

// ---- Exceptions: what() -------------------------------------------
const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Bureaucrat: grade too high (must be >= 1).";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Bureaucrat: grade too low (must be <= 150).";
}

//#####################################################################
// -------- ex01: signForm 
//#####################################################################
void Bureaucrat::signForm(Form& form) const
{
    try {
        form.beSigned(*this);
        std::cout << BRIGHT_GRN << _name << " signed " << form.getName() << RST << "\n";
    } catch (const std::exception& e) {
        std::cout << BRIGHT_RED << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << RST << "\n";
    }
}

//#####################################################################
// ---- Ausgabeoperator --------
//#####################################################################

// Kein std::endl hier → Aufrufer entscheidet über Zeilenumbruch.
std::ostream& operator<<(std::ostream& os, Bureaucrat const& b) 
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

