#include <iostream>
#include <string>

#include "DFA.h"

using namespace std;

int main () {
    DFA answer;
    answer.addVertex("q0");
    answer.addVertex("q1");
    answer.addVertex("q2");
    answer.setInitialState("q0");
    answer.addEdge("q0","q1","a");
    answer.addEdge("q0","q2","b");
    answer.addEdge("q2","q2","b");
    answer.addEdge("q2","q1","a");
    answer.addEdge("q1","q2","b");
    answer.addEdge("q1","q1","a");
    answer.setFinals({"q1"});
    cout << answer.checkWord("aababa");
    //cout << answer << '\n';
}