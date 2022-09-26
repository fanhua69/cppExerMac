#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>

void constarray()
{
    // read() is often used for binary I/O
    std::string bin = { '\x12', '\x12', '\x12', '\x12' };
    std::istringstream raw(bin);
    std::uint32_t n;
    if ( raw.read(reinterpret_cast<char*>(&n), sizeof n) )
        std::cout << std::hex << std::showbase << n << '\n';


    return;
}