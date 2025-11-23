/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:03:07 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/23 15:06:19 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once

// ANSI-Farbcodes (ohne std::string; reine C-Strings)
#define RST   "\033[0m"
#define BOLD  "\033[1m"

#define RED   "\033[31m"
#define GRN   "\033[32m"
#define YEL   "\033[33m"
#define BLU   "\033[34m"
#define MAG   "\033[35m"
#define CYN   "\033[36m"
#define WHT   "\033[37m"

#define BRIGHT_RED   "\033[91m"
#define BRIGHT_GRN   "\033[92m"
#define BRIGHT_YEL   "\033[93m"
#define BRIGHT_BLU   "\033[94m"
#define BRIGHT_MAG   "\033[95m"
#define BRIGHT_CYN   "\033[96m"

// kleine Helfer für hübsche Banner
inline void banner(const char* title)
{
    std::cout << BOLD << BRIGHT_BLU << "\n==========[ "
              << title << " ]==========" << RST << "\n";
}
inline void pass(const char* msg)
{
    std::cout << BRIGHT_GRN << "✔ " << msg << RST << "\n";
}
inline void fail(const std::string& msg)
{
    std::cout << BRIGHT_RED << "✖ " << msg << RST << "\n";
}
