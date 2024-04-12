#include <iostream>
#include <fstream>
#include <sstream>

#include "DFA.h"

using namespace std;

DFA::DFA() {
    //empty braces
}
DFA::DFA(string fileName) {
    readFile(fileName);
}

ostream& operator<< (ostream& out , const DFA& obj) {
    cout << "initialState -> " << obj.initialState << '\n';
    cout << "alphabet is  -> " ;
    for(const auto& x : obj.alphabet) cout << x << ' ';
    cout << '\n';
    
    for(const auto&[node,keyMap] : obj.graph) {
        out << node << "\n";
        for(const auto& [key,end] : keyMap) {
            cout << key << " -> " << end << '\n'; 
        }
    }
    cout << "finals States is ->";
    for(const auto& x :obj.finalsStates) cout << x << ' ';
    return out;
}
void DFA::readFile(string fileName) {
    ifstream input(fileName);

    if(!input.is_open())
        cerr << "fuckkkk\n";

    string str;
    getline(input,str);

    vector<string> states    = splitString(str,' ');
    for(const auto& x : states)
        addVertex(x);

    getline(input,str);
    vector<string> alphabets = splitString(str,' ');
    setAlphabet(alphabets);
    

    //for(const auto& x : alphabets) cout << x << " . " ;

    for(size_t i {states.size()*alphabets.size()} ; i-- && getline(input,str) ;) {
        vector<string> sigma = splitString(str,' ');
        addEdge(sigma.at(0),sigma.at(2),sigma.at(1));
    }
    
    getline(input,str);
    setInitialState(str);

    getline(input,str);
    setFinals(splitString(str,' '));
    input.close();
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
    if(step == (int)word.size()) return this->finalsStates.count(state);
    
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
vector<string> DFA::splitString(string line,char spliter) {
    //cout << "in function " << line  << '\n';
    
    vector<string> parts ;

    stringstream strStream(line);
    string tmp;

    while(getline(strStream,tmp,spliter)) {
        parts.push_back(tmp);
    }

    //cout << "out function " << line  << '\n';
    return parts;
}
void DFA::setFinals(vector<string> input){
    unordered_set<string>tmp (input.begin(),input.end());
    setFinals(tmp);

}
void DFA::setAlphabet(vector<string> input){
    unordered_set<string>tmp (input.begin(),input.end());
    setAlphabet(tmp);

}