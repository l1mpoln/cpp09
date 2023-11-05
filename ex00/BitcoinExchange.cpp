/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:06:52 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/11/05 10:53:53 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Changer::Changer(std::string filename)
{
    std::ifstream file(filename.c_str()); 
    if (!file.is_open())
    {
        std::cerr << "Cant open a file" << std::endl;
        exit(1);
    }
    fill_data(file); 
}

Changer::~Changer() {};

void Changer::fill_data(std::ifstream& file)
{
    std::string line;

    getline(file, line);
    while (getline(file, line))
    {
        std::istringstream ss(line);
        std::string part1, part2;

        if (std::getline(ss, part1, ',') && std::getline(ss, part2))
        {
            int counter = 0;
            for (size_t j = 0; j < part2.size(); j++)
            {   
                if (part2[j] == '.')
                {
                    counter++;
                    if (counter > 1)
                        std::cerr << "Error: Invalid price in data => " << line << std::endl;
                }
                else if (!isdigit(part2[j]))
                     std::cerr << "Error: Invalid price in data => " << line << std::endl;
                const char *cstr = part2.c_str();
                double price = std::strtod(cstr, NULL);
                if (price < 0)
                    std::cerr << "Error: Invalid price in data => " << line << std::endl;
                data[part1] = price;
            }            
        }
        else
        {
            std::cerr << "Error: Invalid format of line in data => " << line << std::endl;
        }
    }
}

double Changer::get_price(std::string &date)
{
    std::map<std::string, double>::iterator it = data.find(date);

    if (it != data.end())
        return static_cast<double>(it->second);
    else
        return (0.0);
}