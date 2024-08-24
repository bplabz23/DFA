
#include "Snapshot.h"
#include "Table.h"

using namespace std;


// We return a snapshot in order two return multiple pieces of data rather than 1

Snapshot read_word(string word, string current_state, Table transition_table)
{
    // Base Case 1: Entire word consumed (word.size = 0) - return current snapshot
    if ( word.empty() )
    {
        return Snapshot(word, current_state);
    }

    // Base Case 2: Transition undefined (2D matrix returns null) - return current snapshot.
    if ()
    {

    }

    // Otherwise, general case: transition to next state read substring of word


}