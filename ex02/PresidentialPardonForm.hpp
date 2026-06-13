/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:41:08 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:41:12 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "AForm.hpp"
#include "color.hpp"

/* ************************************************************************** */
/*                                                                            */
/*               P r e s i d e n t i a l   P a r d o n   F o r m             */
/*                                                                            */
/*   Dieses Formular gewährt dem Target eine präsidentielle Begnadigung.     */
/*   Offiziell von: Zaphod Beeblebrox (Galactic President).                   */
/*                                                                            */
/* ************************************************************************** */

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

protected:
    virtual void executeAction() const;

public:
    // ======================
    //   Canonical Form
    // ======================
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(PresidentialPardonForm const& other);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
    virtual ~PresidentialPardonForm();
};
