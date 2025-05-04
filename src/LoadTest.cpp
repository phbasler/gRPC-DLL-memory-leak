#include <iostream>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    auto library = dlopen(LibPath, RTLD_NOW);

    std::cout << "Library " << LibPath << " was ";
    if(library == nullptr)
    {
        std::cout << "not ";
    }
    std::cout << "loaded" << std::endl;

    if(argc == 1)
    {
        std::cout << dlclose(library) << std::endl;
    }
}
