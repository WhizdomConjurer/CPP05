/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:37:44 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:37:47 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
#include "color.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                  R o b o t o m y   R e q u e s t   F o r m                 */
/*                                                                            */
/*   Diese Form versucht eine Robotomie am Target durchzuführen.              */
/*   Erfolgschance: 50% (rand % 2)                                            */
/*                                                                            */
/* ************************************************************************** */

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

protected:
    virtual void executeAction() const;

public:
    // ======================
    //   Canonical Form
    // ======================
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(RobotomyRequestForm const& other);
    RobotomyRequestForm& operator=(RobotomyRequestForm const& other);
    virtual ~RobotomyRequestForm();

    // ======================
    //      Exception
    // ======================
    class RobotizationFailed : public std::exception {
    public:
        const char* what() const throw();
    };
};
