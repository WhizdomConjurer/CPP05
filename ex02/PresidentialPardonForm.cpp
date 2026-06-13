/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:41:27 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:41:30 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

// ###############################################################
//   Canonical Form
// ###############################################################
PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5),
  _target("default_target")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5),
  _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
: AForm(other),
  _target(other._target)
{}

PresidentialPardonForm&
PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}


// ###############################################################
//   Konkrete Aktion (executeAction)
// ###############################################################
void PresidentialPardonForm::executeAction() const
{
    std::cout << BRIGHT_CYN
              << "✨ Presidential Pardon Issued ✨\n"
              << RST;

    std::cout << BRIGHT_GRN
              << _target 
              << " has been officially pardoned by "
              << BRIGHT_MAG << "Zaphod Beeblebrox" << RST 
              << " — Galactic President, Keeper of Sass & Chaos.\n";
}
