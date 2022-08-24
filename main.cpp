#include "bits/stdc++.h"
#include <iostream>
using namespace std;

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */
class GraphNode{
public:
    GraphNode(int i) : value(i) {}
    static void link(std::shared_ptr<GraphNode> n1, std::shared_ptr<GraphNode> n2){
        n1->connections.push_back(n2.get());
        n2->connections.push_back(n1.get());
    };

    std::vector<GraphNode *> connections;
    bool visited = false;
    int value;
};

class Graph {
public:
    void createNode(int v) {
        nodes[v - 1] = std::shared_ptr<GraphNode>(new GraphNode(v));
    }

    void initCapacity(int size) {
        nodes.resize(size);
    }

    void link(int v1, int v2) {
        GraphNode::link(nodes[v1 - 1], nodes[v2 - 1]);
    }

    std::vector<std::shared_ptr<GraphNode>> nodes;
};
#define EDGE_UNIT 6

void searchThisLevel(std::vector<int> & values, std::queue<GraphNode *> & area, int distance) {
    size_t elementthisround = area.size();
    for (int i = 0; i < elementthisround; i++) {
        GraphNode *node = area.front();
        area.pop();
        if (!node->visited) {
            node->visited = true;
            values[node->value - 1] = std::min(distance, values[node->value - 1]);
            for (auto nit : node->connections) {
                area.push(nit);
            }
        }
    }
}

std::vector<int> bfs(int n, int m, std::vector<std::vector<int>> edges, int s) {
    Graph g;
    g.initCapacity(n);
    for (int i = 0; i < n; i++) {
        g.createNode(i + 1);
    }
    for (auto conn : edges) {
        g.link(conn[0], conn[1]);
    }

    GraphNode *start = g.nodes[s - 1].get();
    std::vector<int> ret;
    ret.resize(n, 10*n);
    std::queue<GraphNode *> area;
    area.push(start);
    int distance = 0;
    while (!area.empty()) {
        searchThisLevel(ret, area, distance);
        distance += EDGE_UNIT;
    }
    for (int i = 0; i < n; i++) {
        if (ret[i] == 10*n) {
            ret[i] = -1;
        }
    }
    ret.erase(ret.begin() + s - 1);
    return ret;
}

#define fout std::cout

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
