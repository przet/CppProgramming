/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: philippe
 *
 * Created on 29 April 2017, 1:04 AM
 */

#include <iostream>
#include <algorithm>
#include <vector>


/*
 * 
 */
int main(int argc, char** argv) {

    std::vector <float> v = [1, 2.4];
    std::back_inserter <v> = 1;
    std::cout << v[3] << std::endl;
    
    
    
    
    return 0;
}

