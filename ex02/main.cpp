/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:22:58 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/28 08:11:55 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void print_before(std::vector<int> &first_vector)
{
    std::cout << "Before: ";
    
    for (int num : first_vector)
        std::cout << num << ' ';
    std::cout << std::endl;
}

void print_clock_vector(std::vector<int> &first_vector)
{
    clock_t start = clock();
    mergeSort(first_vector, 0, first_vector.size() - 1);
    clock_t end = clock();

    std::cout << "After: ";
    for (int num : first_vector)
        std::cout << num << ' ';
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
    if (argc != 2)
    {
        std::cout << "Using: ./PmergeMe <string of ints>" << std::endl;
        return (0); 
    }

    std::vector<int> first_vector;
    std::list<int> second_list;
    std::istringstream ss(argv[1]);
    
    int num = 0;
    while (ss >> num)
    {
        if (num < 0)
        {
            std::cout << "Found negative number => " << num << std::endl;
            return (0);
        }
        first_vector.push_back(num);
        second_list.push_back(num);
    }
    if (!ss.eof())
    {
        std::cout << "Error: Invalid input" << std::endl;
        return (0);
    }
    
    print_before(first_vector);
    print_clock_vector(first_vector);
    print_clock_list(second_list);

    return (0);
}