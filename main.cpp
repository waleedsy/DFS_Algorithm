#include <iostream>
#include <stack>
#include <map>

using namespace std;

map<char, map<char, int>> tree;

void DFS(char start) {
    stack<char> s;
    map<char, bool> visited;
    int cost = 0;

    for (auto &i : tree) {
        visited[i.first] = false;
    }

    s.push(start);

    while (!s.empty()) {
        char current = s.top();
        s.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;
            cost++;

            for (auto &i : tree[current]) {
                if (!visited[i.first]) {
                    s.push(i.first);
                }
            }
        }
    }

    cout << endl << "Total cost: " << cost << endl;
}

int main() {
    tree['s']['g'] = 12;
    tree['s']['a'] = 1;
    tree['a']['c'] = 1;
    tree['a']['b'] = 3;
    tree['b']['d'] = 3;
    tree['c']['g'] = 2;

    cout << "DFS starting from node 's': ";
    DFS('s');

    cout << "DFS starting from node 'a': ";
    DFS('a');

    cout << "DFS starting from node 'b': ";
    DFS('b');

    cout << "DFS starting from node 'c': ";
    DFS('c');

    cout << "DFS starting from node 'd': ";
    DFS('d');

    return 0;
}
