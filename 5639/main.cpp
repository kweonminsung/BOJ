#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int value;
  Node *left;
  Node *right;

  Node(int value) { this->value = value; }
};

Node *insert(Node *cur, int n) {
  if (cur == NULL) {
    cur = new Node(n);
    return cur;
  }

  if (n < cur->value)
    cur->left = insert(cur->left, n);
  else
    cur->right = insert(cur->right, n);

  return cur;
}

void postTravel(Node *cur) {
  if (cur->left != NULL)
    postTravel(cur->left);
  if (cur->right != NULL)
    postTravel(cur->right);
  cout << cur->value << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;
  Node *root = new Node(n);

  while (true) {
    cin >> n;
    if (cin.eof())
      break;

    insert(root, n);
  }

  postTravel(root);
}
