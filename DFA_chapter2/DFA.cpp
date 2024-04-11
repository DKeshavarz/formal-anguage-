#include <iostream>

#include "DFA.h"

using namespace std;

DFA::DFA() {
    //cout << "hello\n";
}

ostream& operator<< (ostream& out , const DFA& obj) {
        for(const auto&[node,keyMap] : obj.graph) {
            out << node << "\n";
            for(const auto& [key,end] : keyMap) {
                cout << key << " -> " << end << '\n'; 
            }
        }
        return out;
}

void DFA::addVertex(string vertex) {
    // validation for reapited

    this->graph[vertex];
    
}
void DFA::addEdge(string src,string end,string key){
    //ckeck vecttex exist
    //check key is valid

    graph[src][key] = end;

}
bool DFA::checkWord(string word) {
    return traceWord(word,0,initialState);

}
bool DFA::traceWord(string word,int step , string state) {
    if(step == word.size()) return this->finalsStates.count(state);
    
    string key (1,word.at(step));
    return traceWord(word,step+1,graph[state][key]);
}
void DFA::setFinals(unordered_set<string> set) {
    this->finalsStates = set;
}
void DFA::setAlphabet(unordered_set<std::string> set) {
    this->alphabet = set;
}
void DFA::setInitialState(string nodeName) {
    //check exist
    this->initialState = nodeName;
}