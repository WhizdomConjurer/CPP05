/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:27:39 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/23 17:09:21 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

// 42-Modul-Konvention: kleinste Zahl = höchster Rang (1), größte = nidrigster (150).
static const int HIGHEST_GRADE = 1;
static const int LOWEST_GRADE  = 150;

class Form;

class Bureaucrat 
{
public:
    //######################################################
    // -- Canonical Form (ohne öffentlichen Default-Ctor) --
    //######################################################
    Bureaucrat(const std::string& name, int grade);         // Haupt-Konstrktor
    Bureaucrat(Bureaucrat const& other);                   // Copy-Konstruktor
    Bureaucrat& operator=(Bureaucrat const& other);       // Zuweisungsoperator
    ~Bureaucrat();                                       // Destruktor

    // -- Getter: nur Leserechte, Wahrung der Kapselung --
    const std::string& getName() const; // Refeenz → kein Kopieren
    int                getGrade() const;

    // -- Modifikatoren: halten Invariante [1..150] strikt ein --
    // increment: 3 -> 2 (besserer Rang = kleinere Zahl)
    void incrementGrade();
    // decrement: 2 -> 3 (schlechterer Rang = größere Zahl)
    void decrementGrade();

    // -- Exceptions: konkrete Fehlertypen für zu hoch / zu niedrig --
    class GradeTooHighException : public std::exception 
    {
        public:
            virtual const char* what() const throw(); // niemals werfen
    };

    class GradeTooLowException : public std::exception 
    {
        public:
            virtual const char* what() const throw(); // niemals werfen
    };

    // --- ex01: Form unterschreiben versuchen ---
    void signForm(Form& form) const;

private:
    // Default-Konstuktor absichtlich verboten (C++98-Stil):
    // nur deklariert, nicht implementiert
    Bureaucrat();

    const std::string _name;
    int               _grade;

    // zentrale Helferfunktion, hält die Invariante
    static void validateGradeOrThrow(int grade);
};

// Freie Ausgabe-Funktion (kein friend, Regeln des Moduls!)
std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif // BUREAUCRAT_HPP