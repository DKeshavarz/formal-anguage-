#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class DFA {
    friend std::ostream& operator<< (std::ostream& out , const DFA& obj) ;

    public:
        DFA();
        DFA(std::string);

        void readFile   (std::string);
        void addVertex  (std::string);
        void addEdge    (std::string,std::string,std::string);
        bool checkWord  (std::string);
        void setFinals  (std::unordered_set<std::string>);
        void setAlphabet(std::unordered_set<std::string>);
        void setFinals  (std::vector<std::string>);
        void setAlphabet(std::vector<std::string>);
        void setInitialState(std::string);

    private:
        bool traceWord(std::string,int,std::string);
        std::vector<std::string> splitString(std::string,char spliter);

        std::unordered_map<std::string,std::unordered_map<std::string,std::string>> graph;
        std::unordered_set<std::string> finalsStates;
        std::unordered_set<std::string> alphabet;
        std::string initialState ;


};