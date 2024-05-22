#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>

#include "function.h"

TEST(Function, split_test) {
    std::vector<std::string> output_vec;
    output_vec.clear();

    std::string input_str = "";
    char splitter = '.';
    output_vec = split(input_str, splitter);

    ASSERT_EQ(output_vec.size(), 1);

    output_vec.clear();
    input_str = "11";
    splitter = '.';
    output_vec = split(input_str, splitter);
    ASSERT_EQ(output_vec.size(), 1);
    ASSERT_EQ(output_vec[0], "11");

    output_vec.clear();
    input_str = "..";
    splitter = '.';
    output_vec = split(input_str, splitter);
    ASSERT_EQ(output_vec.size(), 3);
}

TEST(Function, ip_str_int) {
    std::vector<std::vector<std::string>> str_ip_pool = {   {"255", "255", "255", "0"},
                                                            {"192", "168", "0", "1"},
                                                            {"1", "2", "3", "4"}};

    std::vector<std::vector<int>> int_ip_pool =         {   {255, 255, 255, 0},
                                                            {192, 168, 0, 1},
                                                            {1, 2, 3, 4}};
    std::vector<std::vector<int>> result;

    result = ip_str_int(str_ip_pool);
    ASSERT_EQ(result, int_ip_pool);
}