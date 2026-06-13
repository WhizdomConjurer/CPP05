/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:21:58 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:22:38 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "color.hpp"

// Forward declaration (wie in deiner Form.hpp)
class Bureaucrat;

/* ************************************************************************** */
/*                                                                            */
/*                                A F o r m                                   */
/*        Abstrakte Basisklasse für alle konkreten Formulare (ex02)           */
/*                                                                            */
/* ************************************************************************** */

class AForm
{
private:
    const std::string _name;          // Name der Form
    bool              _isSigned;      // unterschrieben?
    const int         _gradeToSign;   // benötigter Grade zum Signen
    const int         _gradeToExecute;// benötigter Grade zum Executen

protected:
    // Jede Unterklasse MUSS diese Aktion implementieren.
    virtual void executeAction() const = 0;

public:
    // ==============================
    //        Exceptions
    // ==============================
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

    // ==============================
    //     Canonical Form (c++98)
    // ==============================
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(AForm const& other);
    AForm& operator=(AForm const& other);
    virtual ~AForm(); // virtuelle Destruktoren bei Basisklassen

    // ==============================
    //           Getter
    // ==============================
    const std::string& getName() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    // ==============================
    //           Logik
    // ==============================
    void beSigned(Bureaucrat const& b);
    void execute(Bureaucrat const& executor) const; // NEU in ex02
};

// Freier Ausgabeoperator
std::ostream& operator<<(std::ostream& os, AForm const& f);
