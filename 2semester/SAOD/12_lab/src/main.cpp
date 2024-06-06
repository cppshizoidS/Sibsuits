#include "../include/Hash.hpp"
#include "../include/Lists.hpp"
#include "../include/Sorts.hpp"

#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

bool is_simple(int num) {
    bool res = true;
    for (int k = 2; k <= static_cast<int>(std::sqrt(num) + 1); k++)  {
        if (num % k == 0) {
            res = false;
            break;
        }
    }
    return res;
}

int main() {
    // DIGITAL SORT
    std::cout << " N  | Teor | Dec  | Rand | Inc" << std::endl;

    for (int len = 100; len <= 500; len += 100) {
        list<int> up;
        list<int> down;
        list<int> rand;

        up.fill_inc(len);
        down.fill_dec(len);
        rand.fill_rand(len, 0, 100);

        std::cout << len << " | " << sizeof(int) * (len + 256) << " | " << digitalSort(down)
                  << " | " << digitalSort(rand) << " | " << digitalSort(up) << std::endl;
    }

    // HASH
    // DIRECT LINKING
    std::cout << std::endl << " Size table | Number of chars | Number of collisions" << std::endl;

    std::string str = "hgcgh,jkl/h.gmcfgvhjkgjhchbjkh.gmchb,jk.hghmchb,jk.hgfhgjkjygufhgchmjkuiygfhgrbkjso[jphigbjlwrnbfjos[bjosnigjw fbos fjoxgbje nlfbgjsr nbjlfj]]";
    int i = 0;
    for (int len = 11; len <= 101; len++) {
        if (is_simple(len)) {
            std::cout << "         " << len << " | " << std::setw(15) << str.length() << " | " << std::setw(20)
                      << directLinking(str, len) << std::endl;
            i++;
        }
        if (i >= 10)
            break;
    }

    std::cout << std::endl << " Size table | Number of chars | Number of collisions" << std::endl
              << "------------|-----------------| Линейка | Квадрат" << std::endl;

    str = "hgcgh,jkl/h.gmcfgvhjkgjhchbjkh.gmchb,jk.hghmchb,jk.hgfhgjkjygufhgchmjkuiygfhgrbkjso[jphigbjlwrnbfjos[bjosnigjw fbos fjoxgbje nlfbgjsr nbjlfj]]";
    i = 0;
    for (int len = 11; len <= 101; len++) {
        if (is_simple(len)) {
            std::cout << "         " << len << " | " << std::setw(15) << str.length() << " | " << std::setw(7)
                      << openAddressingLinearSample(str, len) << " | " << std::setw(7) << openAddressingQuadraticSample(str, len) << std::endl;
            i++;
        }
        if (i >= 10)
            break;
    }

    return 0;
}