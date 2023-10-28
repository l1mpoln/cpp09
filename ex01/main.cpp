/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:46:33 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/28 05:01:25 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return 1;
    }

    std::string expression(argv[1]);
    RPNCalculator calculator;
    double result = calculator.evaluate(expression);

    if (result != 2) 
    {
        std::cout << result << std::endl;
    }

    return 0;
}
