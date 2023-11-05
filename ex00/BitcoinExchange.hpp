/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:07:00 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/11/05 10:51:12 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <string>


class Changer
{
    private:
       void fill_data(std::ifstream& file);
    public:
        Changer(std::string filename);
        ~Changer();

        std::map<std::string, double> data;
        double get_price(std::string &date);
};

#endif