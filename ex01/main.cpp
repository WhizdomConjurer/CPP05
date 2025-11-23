/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:27:36 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/23 17:17:24 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "color.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    banner("ex01 — Form sign workflow");

    try {
        Bureaucrat alice("Alice", 30);
        Bureaucrat john ("John", 120);
        std::cout << alice << "\n" << john << "\n";

        Form tax("TaxForm", 50, 20);         // Braucht 50 zum Sign, 20 zum Execute
        Form rent("RentIncrease", 130, 100); // Sehr leicht zu signen
        std::cout << tax  << "\n";
        std::cout << rent << "\n";

        banner("Try sining with John (120)");
        john.signForm(tax);   // sollte scheitern (120 > 50)
        john.signForm(rent);  // sollte klappen (120 <= 130)

        banner("Try signing with Alice (30)");
        alice.signForm(tax);  // sollte klappen (30 <= 50)q

        std::cout << "\nFinal state:\n";
        std::cout << tax  << "\n";
        std::cout << rent << "\n";

        pass("All signing scenrios executed.");
    } catch (const std::exception& e) {
        fail(std::string("Unexpected top-level exception: ") + e.what());
        return 1;
    }
    return 0;
}
