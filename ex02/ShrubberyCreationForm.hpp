/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:35:06 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:35:09 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>
#include <string>
#include "AForm.hpp"
#include "color.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                    S h r u b b e r y   C r e a t i o n                     */
/*                                                                            */
/*   Dieses Formular pflanzt Bäume (ASCII-Art) in der Arbeitsumgebung.        */
/*   Ausgabedatei: "<target>_shrubbery"                                       */
/*                                                                            */
/* ************************************************************************** */

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

protected:
    // konkrete Aktion der Form
    virtual void executeAction() const;

public:
    // ======================
    //   Canonical Form
    // ======================
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(ShrubberyCreationForm const& other);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
    virtual ~ShrubberyCreationForm();

    // ======================
    //      Exception
    // ======================
    class FileOpenException : public std::exception {
    public:
        const char* what() const throw();
    };
};
