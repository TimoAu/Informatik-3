#include <fmt/chrono.h>
#include <fmt/format.h>
#include<iostream>    
#include<vector> 
#include<algorithm>
#include "CLI/CLI.hpp"
#include "config.h.in"
// .bss Segment (nicht intialisierte globale Variable)
int foo;
int foo2;
// .data segment (initialisierte globale Variable)
int bar=100;
int bar2 = 42;
// .rodata Segment (read only Variable)
const int rodata = 4711;
const int rodata2 = 4712;

void myFunction(){
    static int value = 100;
    fmt::println("The value of variable value {} the adress{}",value, fmt::ptr(&value));
    value = value+1;
}

void myFunctionStack(int a, int b){
    int d = 65;
    fmt::println("The value of variable a:{} and the adress {}", a, fmt::ptr(&a));
    fmt::println("The value of variable b:{} and the adress {}", b, fmt::ptr(&b));
    
}

void indirectCall(){
    int value = 34;
    fmt::println("indirectCall: the value of {} address of value: {}", value, fmt::ptr(&value));
    myFunctionStack(22,22);
}

auto main(int argc, char **argv) -> int
{
    int local_Variable;
    int local_Variable2;
    int local_Variable3 =100;
    static int local_Variable4=47;
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
    fmt::println("Exercise 2");
    //Variablen liegen in einem anderen Speicherbereich
    fmt::println("The value of variable foo2:{} and the adress {}", foo2, fmt::ptr(&foo2));
    fmt::println("The value of variable foo:{} and the adress {}", foo, fmt::ptr(&foo));

    fmt::println("The value of variable bar:{} and the adress {}", bar, fmt::ptr(&bar));
    fmt::println("The value of variable bar2:{} and the adress {}", bar2, fmt::ptr(&bar2));

    fmt::println("The value of variable rodata:{} and the adress {}", rodata, fmt::ptr(&rodata));
    fmt::println("The value of variable rodata2:{} and the adress {}", rodata2, fmt::ptr(&rodata2));
    //Adressbereich immer gleich; Adressen gehen von hohen zu niedrigen Adressen
    fmt::println("The value of variable local:{} and the adress {}", local_Variable, fmt::ptr(&local_Variable));
    fmt::println("The value of variable local2:{} and the adress {}", local_Variable2, fmt::ptr(&local_Variable2));
    fmt::println("The value of variable local3:{} and the adress {}", local_Variable3, fmt::ptr(&local_Variable3));
    //static Variablen werden in einem anderen Bereich gespeichert
    fmt::println("The value of variable local4:{} and the adress {}", local_Variable4, fmt::ptr(&local_Variable4));

    myFunction();
    myFunction();

    myFunctionStack(1,4);
    myFunctionStack(bar, bar2);
    indirectCall();


    return 0; /* exit gracefully*/
}

