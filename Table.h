#include <string>
#include <vector>
#include <unordered_map>



// This design is very inefficient. I would later like an array-based solution



struct Table
{
    std::vector< std::vector<std::string>> table;                 // Main data
    std::vector<char> alphabet;
    std::vector<std::string> states;

    std::unordered_map<char, int> charToColumn;                   // Hashing
    std::unordered_map<std::string, int> stateToRow;


    // Methods

    Table();                                                     // This is a sort of demo constructor that builds a default table
    std::string getNextState(std::string state, char letter);       
    std::string toString();       

};