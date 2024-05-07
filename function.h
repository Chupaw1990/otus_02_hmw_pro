#include <vector>
#include <string>
#include <iostream>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::vector<std::vector<int>> ip_str_int(std::vector<std::vector<std::string>> &ip_pool_str) {

        using my_str = std::vector<std::string>;

        std::vector<std::vector<int>> ip_pool_int;
        std::vector<int> ip_int;

        for (my_str i: ip_pool_str) {
            ip_int.clear();
            for(std::string j: i) {
                ip_int.push_back(std::stoi(j));
            }
            ip_pool_int.push_back(ip_int);            
        }
    return ip_pool_int;
}

std::ostream& operator << (std::ostream &os, std::vector<int> ip){
    std::string str = "";
    std::vector<int>::const_iterator ip_part = ip.cbegin();
    for (int i : ip){
        str += std::to_string(i);
        if (ip_part != ip.cend() - 1){
            str += '.';
        }
        ip_part++;
    }
    return os << str << std::endl;
}

void print_ip (std::vector<std::vector<int>> &ip_pool_int){
    for (std::vector<int> ip : ip_pool_int){
        std::cout << ip;
    }
}

void filter_ip(std::vector<std::vector<int>> &in_ip_pool, int first_byte) {
    for(std::vector<int> ip : in_ip_pool){
        if(ip[0] == first_byte){
            std::cout << ip;
        }
    }
}

void filter_ip(std::vector<std::vector<int>> &in_ip_pool, int first_byte, int second_byte) {
    for(std::vector<int> ip : in_ip_pool){
        if((ip[0] == first_byte) && (ip[1] == second_byte)){
            std::cout << ip;
        }
    }
}

void filter_ip_any(std::vector<std::vector<int>> &in_ip_pool, int search_byte){
    for(std::vector<int> ip : in_ip_pool){
        if((ip[0] == search_byte) || (ip[1] == search_byte) || 
           (ip[2] == search_byte) || (ip[3] == search_byte)) {
            std::cout << ip;
        }
    }
}