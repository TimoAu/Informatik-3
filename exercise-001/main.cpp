#include <fmt/chrono.h>
#include <fmt/format.h>
#include<iostream>    
#include<vector> 
#include<algorithm>
#include "CLI/CLI.hpp"
#include "config.h.in"

auto print_vector(std::vector<int> &vec1, int &counter)
{
    //oder std::cout << fmt::format("[{}]", fmt::join(*vec1, ","))<<std::endl;
    for(int i= 0; i<counter; i++)
    {
        fmt::print("{} , ", vec1[i]);
    }
}

auto sort_vector(std::vector<int> vec1, int &count_var)
{

    std::sort(vec1.begin(),vec1.end());//Sorting the vector
    print_vector(vec1, count_var);
    return 0;
}

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    
    int count = 20;
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Insert Count");        //add option to change count in Terminal
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */
    std::cout<<count;
    std::vector<int> vec;
    for(int i=0;i<count;i++)
    {
        int random = rand()%100;
        vec.push_back(random);
    }
    fmt::print("Vektorelemente sind: ");
    print_vector(vec, count);
    
    fmt::print("\nSortierte Vektorelemente sind: ");
    sort_vector(vec, count);
    return 0; /* exit gracefully*/
}

