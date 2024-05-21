#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "function.h"

constexpr auto file_name = "ip_filter.tsv";

std::ifstream open_file() {
    std::ifstream file(file_name);
    try {
        file.is_open();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    return file;
}

int main(int, char **) {
    std::vector<std::vector<std::string>> ip_pool;
    ip_pool.reserve(1000);

    std::vector<std::vector<int>> ip_pool_int;
    ip_pool_int.reserve(1000);
    
    try {
        std::ifstream file = open_file();

        for (std::string line; std::getline(file, line);) {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    ip_pool_int = ip_str_int(ip_pool);
    std::sort(ip_pool_int.begin(), ip_pool_int.end(), std::greater<std::vector<int>>());

    print_ip(ip_pool_int);
    filter_ip(ip_pool_int, 1);
    filter_ip(ip_pool_int, 46, 70);
    filter_ip_any(ip_pool_int, 46);

    return 0;
}
