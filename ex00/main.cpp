/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:27:36 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/11 19:08:18 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

// ANSI-Farben
#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YEL "\033[33m"
#define BLU "\033[34m"
#define MAG "\033[35m"
#define CYA "\033[36m"

static void banner(const char* title) {
    std::cout << "\n" << BLU << "========== " << title << " ==========" << RST << "\n";
}

static void pass(const std::string& msg) {
    std::cout << GRN << "[PASS] " << RST << msg << "\n";
}

static void fail(const std::string& msg) {
    std::cout << RED << "[FAIL] " << RST << msg << "\n";
}

int main() 
{
    banner("ex00 — Bureaucrat basic construction & printing");

    // 1) Valide Konstruktion
    try {
        Bureaucrat john("John", 172);
        std::cout << CYA << john << RST << "\n"; // nutzt operator<<
        pass("Constructed John with grade 42");
    } catch (std::exception& e) {
        fail(std::string("Unexpected exception: ") + e.what());
    }

    // 2) Ungültige Konstruktion (zu hoch)
    banner("construction: too high / too low");
    try {
        Bureaucrat a("Alice", 0);
        fail("Alice(0) should have thrown GradeTooHighException");
    } catch (std::exception& e) {
        std::cout << YEL << "Caught: " << e.what() << RST << "\n";
        pass("Alice(0) threw as expected");
    }

    // 3) Ungültige Konstruktion (zu niedrig)
    try {
        Bureaucrat b("Bob", 151);
        fail("Bob(151) should have thrown GradeTooLowException");
    } catch (std::exception& e) {
        std::cout << YEL << "Caught: " << e.what() << RST << "\n";
        pass("Bob(151) threw as expected");
    }

    // 4) increment/decrement
    banner("increment / decrement");
    Bureaucrat x("Xenia", 2);
    std::cout << MAG << x << RST << "\n";
    try {
        x.incrementGrade(); // 2 -> 1
        pass("Xenia increment: 2 -> 1");
        std::cout << MAG << x << RST << "\n";
        x.incrementGrade(); // 1 -> throw
        fail("increment at grade 1 should throw");
    } catch (std::exception& e) {
        std::cout << YEL << "Caught: " << e.what() << RST << "\n";
        pass("increment at grade 1 threw as expected");
    }

    Bureaucrat y("Yann", 149);
    std::cout << MAG << y << RST << "\n";
    try {
        y.decrementGrade(); // 149 -> 150
        pass("Yann decrement: 149 -> 150");
        std::cout << MAG << y << RST << "\n";
        y.decrementGrade(); // 150 -> throw
        fail("decrement at grade 150 should throw");
    } catch (std::exception& e) {
        std::cout << YEL << "Caught: " << e.what() << RST << "\n";
        pass("decrement at grade 150 threw as expected");
    }

    // 5) Copy & Assignment
    banner("copy & assignment (const name is not reassigned)");
    Bureaucrat c1("Carol", 10);
    Bureaucrat c2 = c1;       // Copy-Ctor
    std::cout << CYA << c1 << RST << "\n";
    std::cout << CYA << c2 << RST << "\n";
    pass("Copy constructor kept same name & grade");

    Bureaucrat c3("OtherName", 120);
    std::cout << "Before assign: " << c3 << "\n";
    c3 = c1;                  // operator=
    std::cout << "After  assign: " << c3 << "\n";
    pass("Assignment copied grade only (name is const)");

    banner("done");
    return 0;
}
