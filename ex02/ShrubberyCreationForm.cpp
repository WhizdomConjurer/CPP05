/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:35:13 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:35:29 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

// ###############################################################
//   Canonical Form
// ###############################################################
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137),
  _target("default_target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137),
  _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
: AForm(other),
  _target(other._target)
{}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    if (this != &other)
    {
        // AForm::operator= kümmert sich um _isSigned
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


// ###############################################################
//   Exception what()
// ###############################################################
const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "ShrubberyCreationForm: could not create output file";
}


// ###############################################################
//   executeAction (konkrete Aktion)
// ###############################################################
void ShrubberyCreationForm::executeAction() const
{
    std::string fileName = _target + "_shrubbery";
    std::ofstream out(fileName.c_str());

    if (!out.is_open())
        throw FileOpenException();

    // 💥 EPIC ASCII TREE – Premium Bürokratenbaum 💥
    out << "               v .   ._, |_  .,\n";
    out << "           `-._\\/  .  \\ /    |/_\n";
    out << "               \\\\  _\\, y | \\//\n";
    out << "         _\\_.___\\\\, \\\\/ -.\\||\n";
    out << "           `7-,--.`._||  / / ,\n";
    out << "           /'     `-. `./ / |/_.'\n";
    out << "                     |    |//\n";
    out << "                     |_    /\n";
    out << "                     |-   |\n";
    out << "                     |   =|\n";
    out << "                     |    |\n";
    out << "--------------------/ ,  . \\--------._\n";

    out.close();

    std::cout << BRIGHT_GRN 
              << "ShrubberyCreationForm: created file \"" 
              << fileName << "\" with an awesome ASCII tree 🌳"
              << RST << "\n";
}
