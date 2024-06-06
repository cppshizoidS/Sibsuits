#include "Hash.hpp"
#include <cstddef>
#include <cstring>

std::size_t directLinking(const std::string &str, std::size_t size_table) {
    HashTable<char, char> table;
    for (char c : str)
        table.addDirectLinking(c, c, size_table);

    return table.get_collisions();
}

std::size_t openAddressingLinearSample(const std::string &str, std::size_t size_table) {
    HashTable<char, char> table;
    for (char c : str)
        table.addOpenAddressingLinearSample(c, c, size_table);

    return table.get_collisions();
}

std::size_t openAddressingQuadraticSample(const std::string &str, std::size_t size_table) {
    HashTable<char, char> table;
    for (char c : str)
        table.addOpenAddressingQuadraticSample(c, c, size_table);

    return table.get_collisions();
}
