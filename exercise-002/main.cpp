#include <fmt/chrono.h>
#include <fmt/format.h>
#include<iostream>    
#include<vector> 
#include<algorithm>
#include "CLI/CLI.hpp"
#include "config.h.in"


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
    fmt::println("Exercise 2")

    return 0; /* exit gracefully*/
}

