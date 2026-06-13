/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:37:53 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:38:42 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

// ###############################################################
//   Canonical Form
// ###############################################################
RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45),
  _target("default_target")
{
    std::srand(std::time(NULL)); // Seed einmalig setzen
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45),
  _target(target)
{
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
: AForm(other),
  _target(other._target)
{}

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


// ###############################################################
//   Excetion what()
// ###############################################################
const char* RobotomyRequestForm::RobotizationFailed::what() const throw()
{
    return "RobotomyRequestForm: robotization failed (50% chance).";
}


// ###############################################################
//   executeAction
// ###############################################################
void RobotomyRequestForm::executeAction() const
{
    //  geiler „Dril-Soud“
    std::cout << CYN
              << "* BZZZZZT *  * VRRRRRRRT *  —  high-energy drilling noises echo through the room... * "
              << RST << "\n";

    int roll = std::rand() % 2;

    if (roll == 1)
    {
        std::cout << BRIGHT_GRN
                  << _target << " has been successfully robotomized 🤖✨"
                  << RST << "\n";
    }
    else
    {
        std::cout << BRIGHT_RED
                  << "Robotomy failed on " << _target << "…"
                  << RST << "\n";
        throw RobotizationFailed();
    }
}
