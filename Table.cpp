#include "Table.h"
#include <iostream>

using namespace std;




// Default constructor


Table::Table()
{
    // This is going to build a classic DFA, even # of b's from wikipedia
    // Note these 2 int arrays are rows that point to a list of their associated column values


    // Set up alphabet

    vector<char> temp_alphabet = vector<char>(); 
    temp_alphabet.push_back('a');
    temp_alphabet.push_back('b');

    this->alphabet = temp_alphabet;
    

    // Set up states

    vector<string> temp_states = vector<string>();
    temp_states.push_back("q1");
    temp_states.push_back("q2");

    this->states = temp_states;


    // Set up hash converters (convert various data into indexes on a table)
    charToColumn['a'] = 0;
    charToColumn['b'] = 1;

    stateToRow["q1"] = 0;
    stateToRow["q2"] = 1;

    // Set up main table. Remember this table returns states (string)
    
    this->table = vector<vector<string>>();

    for (string q: states)                          // set up rows
    {
        this->table.push_back( vector<string>() );  
    }

    // This is not how a user would enter a table, because they would not be interacting with the source code
    //  But since this is a demo, we are hardwiring in a text file (notice that in the real world this isnt all on one line.)

    vector<string> file = {"q2", "q1", "q1", "q2"};
    vector<string> *row;

    for (int i =  0; i < states.size(); i++)        // For every row
    {
        row = &(table[i]);
        for (int j  = 0; j < alphabet.size(); j++)  // For every value j in the row
        {
            row->push_back(file[(2*i) + j]);
        }
    }


}







std::string Table::toString()
{
    string output = "";
    output += "\t|";


    // Lable the columns
    for (char c: this->alphabet)
    {
        output += c;
        output += "\t|";
    }

    output += "\n";

    // print divider
    for (int i = 0; i < this->alphabet.size() + 1; i++)
    {
        output += "---\t";
    }

    output += "\n";


    int row;
    int column;

    // Print the table
    for (string q: this->states)        // For every row
    {
        output += q;
        output += "\t|";
        row = stateToRow[q];

        for (char c: this->alphabet)    // For every letter c in the row
        {
            column = charToColumn[c];
            output += table[row][column];
            output += "\t|";
        }

        output += "\n";
    }

    return output;
}








