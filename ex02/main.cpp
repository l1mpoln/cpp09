/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:22:58 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/11/05 11:03:11 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void print_before(std::vector<int> &first_vector)
{
    std::cout << "Before: ";
    
    for (std::vector<int>::const_iterator it = first_vector.begin(); it != first_vector.end(); ++it) 
        std::cout << *it << ' ';
    std::cout << std::endl;
}

void print_clock_vector(std::vector<int> &first_vector)
{
    clock_t start = clock();
    mergeSort(first_vector, 0, first_vector.size() - 1);
    clock_t end = clock();

    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = first_vector.begin(); it != first_vector.end(); ++it) 
        std::cout << *it << ' ';
    std::cout << std::endl;

    double microseconds = ((double) (end - start) / CLOCKS_PER_SEC) * 1e6; 
    std::cout << "Time to process a range of " << first_vector.size() << " elements with std::vector : " << microseconds << " us" << std::endl;
}

void print_clock_list(std::list<int> &list)
{
    clock_t start = clock();
    mergeSortList(list);
    clock_t end = clock();
    double microseconds = ((double) (end - start) / CLOCKS_PER_SEC) * 1e6; 
    std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << microseconds << " us" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Using: ./PmergeMe <ints>" << std::endl;
        return (0); 
    }

    std::vector<int> first_vector;
    std::list<int> second_list;
    
    for (int i = 1; i < argc; ++i) 
    {
		std::stringstream ss(argv[i]);
		int num;
		if (!(ss >> num) || !ss.eof()) 
        {
			std::cerr << "Error: Invalid input.\n";
			return 1;
		}
		if (num < 0) 
        {
			std::cerr << "Error: Negative numbers are not allowed.\n";
			return 1;
		}
		first_vector.push_back(num);
		second_list.push_back(num);
	}
    
    print_before(first_vector);
    print_clock_vector(first_vector);
    print_clock_list(second_list);

    return (0);
}