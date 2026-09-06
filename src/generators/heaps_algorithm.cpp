#include "heaps_algorithm.h"

#include <cstdint>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "vendor/bigint/bigint.h"

void count_permutations(std::size_t list_size, std::ofstream& output)
{   
    bigint result(1);
    bigint big_list_size(std::to_string(list_size));

    for (bigint i = 1; i <= big_list_size; ++i)
    {
        result *= bigint(i);
    }

    output << result;
}

void write_permutation(std::vector<std::string>& items, std::ofstream& output)
{
    output << items[0];

    for (std::size_t i = 1; i < items.size(); i++)
    {
        output << " " << items[i];
    }

    output << "\n";
}

void heap_permutation(std::vector<std::string>& items, std::size_t size, std::ofstream& output)
{
    if (size == 1)
    {
        write_permutation(items, output);
    }

    for (std::size_t i = 0; i < size; i++)
    {
        heap_permutation(items, size - 1, output);

        if (size % 2 == 1)
        {
            std::swap(items[0], items[size - 1]);
        }
        else
        {
            std::swap(items[i], items[size - 1]);
        }
    }
}

void heaps_algorithm(std::vector<std::string>& items, std::ofstream& output)
{
    heap_permutation(items, items.size(), output);
}