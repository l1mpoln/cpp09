/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:34:19 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/28 08:13:52 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <vector>

const int INSERTION_THRESHOLD = 10; // Порог для переключения на сортировку вставкой

void insertionSort(std::vector<int>& arr, int left, int right) 
{
    for (int i = left + 1; i <= right; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);
 
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = arr[mid + 1 + i];
 
    int i = 0, j = 0, k = left;
 
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) 
        {
            arr[k] = leftArray[i];
            i++;
        } 
        else 
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}
 
void mergeSort(std::vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        if (right - left <= INSERTION_THRESHOLD) 
        {
            insertionSort(arr, left, right);
        } 
        else 
        {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}


//for list


void insertionSort(std::list<int>& lst) 
{
    for (std::list<int>::iterator it = ++lst.begin(); it != lst.end(); ++it) 
    {
        int key = *it;  // Запоминаем текущий элемент, который нужно вставить в отсортированную часть
        std::list<int>::iterator jt = it;  // jt - итератор, смотрящий на элемент перед it
        --jt;  // Переходим к предыдущему элементу

        // Пока не достигли начала списка и предыдущий элемент больше key
        while (jt != lst.begin() && *jt > key) 
        {
            std::list<int>::iterator next_jt = jt;  // next_jt - итератор, смотрящий на предыдущий элемент перед jt
            --next_jt;  // Переходим к элементу перед jt
            *std::next(jt) = *jt;  // Перемещаем элемент на следующую позицию
            jt = next_jt;  // Переходим к предыдущему элементу
        }

        *std::next(jt) = key;  // Вставляем key в правильную позицию в отсортированной части
    }
}


void mergelist(std::list<int>& lst, std::list<int>& left, std::list<int>& right) 
{
    std::list<int>::iterator leftIt = left.begin();  // Итератор для левого списка
    std::list<int>::iterator rightIt = right.begin();  // Итератор для правого списка

    while (leftIt != left.end() && rightIt != right.end()) 
    {
        if (*leftIt <= *rightIt) 
        {
            lst.push_back(*leftIt);  // Если элемент из левого списка меньше или равен, добавляем его в конец результирующего списка
            ++leftIt;
        } 
        else 
        {
            lst.push_back(*rightIt);  // Если элемент из правого списка меньше, добавляем его в конец результирующего списка
            ++rightIt;
        }
    }

    while (leftIt != left.end()) 
    {
        lst.push_back(*leftIt);  // Добавляем оставшиеся элементы из левого списка
        ++leftIt;
    }

    while (rightIt != right.end()) 
    {
        lst.push_back(*rightIt);  // Добавляем оставшиеся элементы из правого списка
        ++rightIt;
    }
}


void mergeSortList(std::list<int>& lst) 
{
    if (lst.size() <= 1) 
        return;

    if (lst.size() <= INSERTION_THRESHOLD) 
    {
        insertionSort(lst);  // Если размер списка меньше порогового значения, используем сортировку вставкой
    } 
    else 
    {
        std::list<int> left, right;

        std::list<int>::iterator middle = lst.begin();
        std::advance(middle, lst.size() / 2);

        left.splice(left.begin(), lst, lst.begin(), middle);  // Разделяем список на две половины и передаем их в left и right
        right.splice(right.begin(), lst, middle, lst.end());

        mergeSortList(left);  // Рекурсивно сортируем каждую половину
        mergeSortList(right);

        mergelist(lst, left, right);  // Сливаем два отсортированных списка обратно в основной список
    }
}
