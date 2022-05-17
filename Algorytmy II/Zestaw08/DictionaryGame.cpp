#include "Graph.hpp"
#include <map>
#include <fstream>
#include <vector>

using namespace std;

Graph<string>* BuildGraph(){
    ifstream WordsFile("slowa.txt");
    map<string, vector<string>> Words;

    string Word;
    string Template;

    while (WordsFile >> Word){
        if (Word.size() == 4){
            for (int i = 0; i < (int)Word.size(); i++){
                Template = Word;
                Template[i] = '?';
                Words[Template].push_back(Word);
            }
        }
    }

    WordsFile.close();

    Graph<string>* g = new Graph<string>();

    for (pair<string, vector<string>> node : Words){
        for (string& word : node.second){
            g->addVertex(word);
            for (string& word2 : node.second){
                if (word != word2){
                    g->addVertex(word2);
                    g->addEdge(word, word2);
                }
            }
        }
    }

    return g;
}

void SearchGraphPath (Graph<string>* g, string start, string end){
    vector <string> visited;
    vector<pair<string, vector<string>>> queue;

    visited.push_back(start);
    queue.push_back(make_pair(start, vector<string>()));

    pair<string, vector<string>> node;

    while (!queue.empty()){
        node = queue.front();

        if (node.first == end){
            cout << "Found shortest path in " << node.second.size() << " steps" << endl;
            for (string& s : node.second){
                cout << s << " -> ";
            } 
            cout << node.first << endl;
            return;
        }
        queue.erase(queue.begin());

        for (string& s : g->neighbours(node.first)){
            for (vector<string>::iterator it = visited.begin(); it != visited.end();){
                if ((*it) == s){
                    break;
                }
                it++;
                if (it == visited.end()){
                    visited.push_back(s);
                    vector<string> tmp = node.second;
                    tmp.push_back(node.first);
                    queue.push_back(make_pair (s, tmp));
                    break;
                }
            }
        }
    } 
    cout << "Did not find any path between these words" << endl;
}

int main(){
    Graph<string>* g = BuildGraph();
    string start;
    string end;
    string cont;
    while (true){
        cout << "Enter start word: ";
        cin >> start;
        while (start.size() != 4){
            cout << "Word must contain exactly 4 characters!" << endl;
            cout << "Enter start word: ";
            cin >> start;
        }

        cout << "Enter end word: ";
        cin >> end;
        while (end.size() != 4){
            cout << "Word must contain exactly 4 characters!" << endl;
            cout << "Enter end word: ";
            cin >> end;
        }

        cout << endl;
        SearchGraphPath(g, start, end);
        cout << endl;
        cout << "Do you want to continue [yes/no]? ";
        cin >> cont;
        for (unsigned long int i = 0; i < cont.size(); i++){
            cont[i] = tolower(cont[i]);
        }
        if (cont == "no"){
            return 0;
        }
    }
}