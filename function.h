#pragma once

#include <iostream>
#include <string>
#include <vector>

using vector_ip_int = std::vector<std::vector<int>>;
using vector_ip_str = std::vector<std::string>;

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
vector_ip_str split(const std::string &str, char d) {
    std::vector<std::string> r;
    r.reserve(1000);

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos) {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

vector_ip_int ip_str_int(std::vector<std::vector<std::string>> &ip_pool_str) {
    vector_ip_int ip_pool_int;
    ip_pool_int.reserve(1000);
    std::vector<int> ip_int;
    ip_int.reserve(1000);

    for (vector_ip_str i : ip_pool_str) {
        ip_int.clear();

        if (i.size() > 4){
            std::cout << i.size() << std::endl;
            throw(i);
        }
        for (std::string j : i) {
            if((std::stoi(j) < 0) || (std::stoi(j) > 255)){
                throw(i);
            }

            ip_int.push_back(std::stoi(j));
        }
        ip_pool_int.push_back(ip_int);
    }
    return ip_pool_int;
}

std::ostream &operator<<(std::ostream &os, std::vector<int> ip) {
    std::string str = "";
    std::vector<int>::const_iterator ip_part = ip.cbegin();
    for (int i : ip) {
        str += std::to_string(i);
        if (ip_part != ip.cend() - 1) {
            str += '.';
        }
        ip_part++;
    }
    return os << str << std::endl;
}

std::ostream &operator<<(std::ostream &os, std::vector<std::string> ip) {
    std::string str = "";
    std::vector<std::string>::const_iterator ip_part = ip.cbegin();
    for (std::string i : ip) {
        str += i;
        if (ip_part != ip.cend() - 1) {
            str += '.';
        }
        ip_part++;
    }
    return os << str;
}

void print_ip(vector_ip_int &ip_pool_int) {
    for (auto ip : ip_pool_int) {
        std::cout << ip;
    }
}

void filter_ip(vector_ip_int &in_ip_pool, int first_byte) {
    for (auto ip : in_ip_pool) {
        if (ip[0] == first_byte) {
            std::cout << ip;
        }
    }
}

void filter_ip(vector_ip_int &in_ip_pool, int first_byte, int second_byte) {
    for (auto ip : in_ip_pool) {
        if ((ip[0] == first_byte) && (ip[1] == second_byte)) {
            std::cout << ip;
        }
    }
}

void filter_ip_any(vector_ip_int &in_ip_pool, int search_byte) {
    for (auto ip : in_ip_pool) {
        if ((ip[0] == search_byte) || (ip[1] == search_byte) ||
            (ip[2] == search_byte) || (ip[3] == search_byte)) {
            std::cout << ip;
        }
    }
}