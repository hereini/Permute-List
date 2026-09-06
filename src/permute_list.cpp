#include <iostream>

#include <vector>
#include <string>
#include "vendor/cli11/CLI11.hpp"
#include "src/generators/heaps_algorithm.h"

void select_generator(CLI::App& app, std::vector<std::string>& items, bool only_count_permutations, const std::string& output_file)
{
    if (app.count("--input") == 0 || items.size() == 0)
    {
        std::cout << "No items provided. Use --input item1 item2 item3... to add items.\n";
        exit(0);
    }

    if (app.count("--output") == 0 || output_file.empty())
    {
        std::cout << "No output file provided. Use --output filename.txt to specify an output file.\n";
        exit(0);
    }

    std::ofstream output(output_file);
    if (!output.is_open())
    {
        std::cerr << "Error: Could not open file \"" << output_file << "\"" << std::endl;
    }

    if (only_count_permutations)
    {
        count_permutations(items.size(), output);
    }
    else
    {
        heaps_algorithm(items, output);
    }

    output.close();
}

int main(int argc, char* argv[])
{
    // Create CLI11 app
    CLI::App app("A program that generates all permutations of a list.", "Permutator");

    // Add Flags
    std::vector<std::string> items;
    bool only_count_permutations = false;
    std::string output_file = " ";

    app.add_option("--input",     items,                   "The items to find the permutations of");
    app.add_option("--output",    output_file,             "The file where results are written");
    app.add_flag  ("--count",     only_count_permutations, "Get the count of permutations");
    CLI11_PARSE(app, argc, argv);

    // Select the permutation generator
    select_generator(app, items, only_count_permutations, output_file);
}