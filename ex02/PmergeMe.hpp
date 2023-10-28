/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:23:55 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/28 07:56:10 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGERME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <sstream>
# include <ctime>

void mergeSort(std::vector<int>& arr, int left, int right);
void mergeSortList(std::list<int>& lst);

#endif