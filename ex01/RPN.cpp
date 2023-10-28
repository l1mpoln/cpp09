/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:48:12 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/28 05:15:49 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>

double RPNCalculator::evaluate(std::string expression) {
    std::stack<double> stack;

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) 
    {
        if (isdigit(token[0])) 
            stack.push(std::stod(token));
        
        else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) 
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: Insufficient operands for operation." << std::endl;
                return 0;
            }

            double op2 = stack.top();
            stack.pop();
            double op1 = stack.top();
            stack.pop();

            switch (token[0]) 
            {
                case '+':
                    stack.push(op1 + op2);
                    break;
                case '-':
                    stack.push(op1 - op2);
                    break;
                case '*':
                    stack.push(op1 * op2);
                    break;
                case '/':
                    if (op2 == 0) 
                    {
                        std::cerr << "Error: Division by zero." << std::endl;
                        return 2;
                    }
                    stack.push(op1 / op2);
                    break;
                default:
                    std::cerr << "Error: Invalid operator." << std::endl;
                    return 2;
            }
        } 
        else 
        {
            std::cerr << "Error: Invalid token." << std::endl;
            return 2;
        }
    }

    if (stack.size() != 1) 
    {
        std::cerr << "Error: Invalid expression." << std::endl;
        return 2;
    }

    return stack.top();
}
