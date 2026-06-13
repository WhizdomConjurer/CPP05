/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:42:51 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/12/01 10:44:04 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "color.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    banner("ex02 — Advanced Forms & Execution");

    // ========================================================================
    // 🔹 TESTBLOCK 1: ShrubberyCreationForm
    // ========================================================================
    banner("ShrubberyCreationForm — planting ASCII trees");

    {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm tree("Backyard");

        std::cout << tree << "\n";

        bob.signForm(tree);       // Bob (130) → benötigt 145 → sollte klappen
        std::cout << tree << "\n";

        bob.executeForm(tree);    // Bob (130) → benötigt 137 zum Ausführen → klappt
    }

    // ========================================================================
    // 🔹 TESTBLOCK 2: RobotomyRequestForm
    // ========================================================================
    banner("RobotomyRequestForm — drilling with 50% chance");

    {
        RobotomyRequestForm robo("TargetUnit-42");
        Bureaucrat drillGuy("Driller", 45);     // 45 → perfekt zum Ausführen
        Bureaucrat weakGuy("Weakling", 100);    // zu schwach

        std::cout << robo << "\n";

        // Versuch 1: execute ohne signed → sollte fehlschlagen
        weakGuy.executeForm(robo);

        // Signieren: weakGuy kann signieren? (limit 72) → ja
        weakGuy.signForm(robo);
        std::cout << robo << "\n";

        // Versuch 2: execute mit weajGuy → grade 100 > exec 45 → fail
        weakGuy.executeForm(robo);

        drillGuy.executeForm(robo);
        drillGuy.signForm(robo);
        // Versuch 3: execute mit Driler → macht Robotomy
        drillGuy.executeForm(robo);
        drillGuy.executeForm(robo);
        drillGuy.executeForm(robo); // mehrere Durchläufe zeigen 50% Chance
    }


    // ========================================================================
    // 🔹 TESTBLOCK 3: PresidentialPardonForm
    // ========================================================================
    banner("PresidentialPardonForm — Zaphod Beeblebrox pardons!");

    {
        PresidentialPardonForm pardon("Arthur Dent");
        Bureaucrat intern("Intern", 100);      // kann weder signen noch ausführen
        Bureaucrat vp("VicePresident", 20);    // kann signieren, aber nicht ausführen
        Bureaucrat prez("Zaphod", 1);          // kann alles

        std::cout << pardon << "\n";

        // Intern: komplett unfähig
        intern.signForm(pardon);
        intern.executeForm(pardon);

        std::cout << "\n";

        // Vizepräsident signiert erfolgreich (<=25)
        vp.signForm(pardon);
        std::cout << pardon << "\n";

        // Vizepräsident kann NICHT ausführen (20 > exec 5)
        vp.executeForm(pardon);

        std::cout << "\n";

        // Präsident führt aus (Grade 1)
        prez.executeForm(pardon);
    }

    banner("All tests executed");
    pass("ex02 operational ✔");

    return 0;
}
