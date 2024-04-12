#include <iostream>
#include <string>

#include "DFA.h"

using namespace std;

int main () {
    DFA answer("ansewer2_1_24.txt");

    cout << answer.checkWord("baababa") << "\n\n";
    cout << answer.checkWord("aababa" ) << "\n\n";
    cout << answer.checkWord("abbbbba") << "\n\n";

    return 0;
}