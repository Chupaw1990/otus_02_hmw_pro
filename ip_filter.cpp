#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "function.h"

#define FILE_NAME   "ip_filter.tsv"

std::ifstream open_file(){

    std::ifstream file(FILE_NAME);
    try{
        file.is_open();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    
    return file;
}

int main(int, char **)
{
    try
    {
        std::ifstream file = open_file();
        
        std::vector<std::vector<std::string>> ip_pool;
        std::vector<std::vector<int>> ip_pool_int;

        for(std::string line; std::getline(file, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        ip_pool_int = ip_str_int(ip_pool);
        std::sort(ip_pool_int.begin(),ip_pool_int.end(), std::greater<std::vector<int>>());

        print_ip(ip_pool_int);
        filter_ip(ip_pool_int,1);
        filter_ip(ip_pool_int, 46, 70);
        filter_ip_any(ip_pool_int,46);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
