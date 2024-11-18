#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b;

void topology_sort(vector<int>& inDegree, vector<int>& result,
    vector<vector<int>>& graph) {
    queue<int> q;

    // 진입 차수가 0인 정점들을 큐에 삽입
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    for (int i = 0; i < n; i++) {
        // n번 반복 전에 큐가 비었다면 사이클 존재
        if (q.empty()) return;

        // 현재 방문한 노드 번호
        int curNode = q.front();
        // 방문 결과 저장
        result[i] = curNode;
        q.pop();

        for (int j = 0; j < graph[curNode].size(); j++) {
            int nextNode = graph[curNode][j];
            if (--inDegree[nextNode] == 0) q.push(nextNode);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<int> inDegree(n + 1);
    vector<int> result(n + 1);
    vector<vector<int>> graph(n + 1, vector<int>(0, 0));

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    topology_sort(inDegree, result, graph);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}