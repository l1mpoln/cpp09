/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:50:05 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/11/05 10:50:46 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool ValidateDate(const std::string& date) {
	std::string::size_type del1 = date.find('-');
	std::string::size_type del2 = date.rfind('-');

	if (del1 == std::string::npos || del1 == del2)
		return false;

	std::string year_str = date.substr(0, del1);
	std::string month_str = date.substr(del1 + 1, del2 - del1 - 1);
	std::string day_str = date.substr(del2 + 1);

	int year, month, day;
	std::istringstream year_ss(year_str), month_ss(month_str), day_ss(day_str);

	if (!(year_ss >> year) || !(month_ss >> month) || !(day_ss >> day))
		return false;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return false;
	}

	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
			return false;
		}
	}

	return true;
}

bool ValidateValue(const double &value) 
{
	if (value < 0 || value > 1000) 
	{
		std::cerr << "Error: Value " << value << " is not a positive number between 0 and 2147483647.\n";
		return false;
	}
	return true;
}

void get_input(std::string filename, Changer &BitcoinChanger)
{
	std::map<std::string, int> input_data;
	
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Cant open a file" << std::endl;
		exit(0) ;
	}
	
	std::string line;
	getline(file, line);
	while (getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		char		delim;
		double		value;
		
		if (!(ss >> date >> delim >> value))
			std::cerr << "Error: bad input => " << line << std::endl;
		
		if (delim != '|')
			std::cerr << "Error: Need '|' delimeter in line => " << line << std::endl;

		if (!ValidateDate(date))
			std::cerr << "Error: Invalid date format in line => " << line << std::endl; 

		if (!ValidateValue(value))
			continue;

		double exchange_price = BitcoinChanger.get_price(date);
		
		if (exchange_price == 0.0)
        {
            std::map<std::string, double>::const_iterator it = BitcoinChanger.data.lower_bound(date);
            
            if (it != BitcoinChanger.data.begin())
            {
                --it;
                exchange_price = (it->second);
            }
            else
            {
                std::cerr << "Error: No lower date found." << std::endl;
            }
        }

		std::cout << date << " => " << value << " => " << value * exchange_price << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./exch input.txt" << std::endl;
		return (0);
	}
	Changer BitcoinChanger("data.csv");
	get_input(argv[1], BitcoinChanger);
}