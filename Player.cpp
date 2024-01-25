/**
 * @file Player.cpp
 * 
 * 
 */

 #include "Player.h"
#include <iostream>

/**
 * @brief 
 * 
 * @param out 
 * @param p 
 * @return std::ostream& 
 */
 std::ostream& operator <<(std::ostream& out, const Player& p){  
        out << p.name;
        return out;
    }