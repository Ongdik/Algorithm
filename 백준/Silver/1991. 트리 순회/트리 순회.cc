#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char>> tree;

void preOrder(char node) {
	cout << node;
	if (tree[node].first != '.') preOrder(tree[node].first);
	if (tree[node].second != '.') preOrder(tree[node].second);

}

void inOrder(char node) {
	if (tree[node].first != '.') inOrder(tree[node].first);
	cout << node;
	if (tree[node].second != '.') inOrder(tree[node].second);
}

void postOrder(char node) {
	if (tree[node].first != '.') postOrder(tree[node].first);
	if (tree[node].second != '.') postOrder(tree[node].second);
	cout << node;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	char node, left, right;
	cin >> n;
	while (n--) {
		cin >> node >> left >> right;
		tree[node] = { left, right };
	}
	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');
}