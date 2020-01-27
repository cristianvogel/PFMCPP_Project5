#pragma once

#include <sstream> // for string stream

/*
some handy console formatting functions
*/

//a little reusable ANSI console text colouring method
//https://en.wikipedia.org/wiki/ANSI_escape_code
std::string colour( int colour, std::string text ) 
{       
    std::string colourANSI = std::to_string( 30 + colour) ; //default red
    std::string openANSI = "\x1B[" + colourANSI + "m";
    std::string closeANSI = "\033[0m";
    openANSI += text + closeANSI;
    return ( (colour > 0) && (colour < 16) ) ? openANSI : "";
}

// Line break separator
void br()
{
    std::cout <<  '\n' << colour(1, "~~~~~~~~~~~~~~~~~~~~~~~~~~") << '\n'; 
}

