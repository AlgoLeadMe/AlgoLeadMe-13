#include <iostream>
using namespace std;
pair<char,char> node[26];
int N;

//전위순회
void preorder(char current){
    if(current == '.')
    return;
    
    cout << current;
    preorder(node[current-'A'].first);
    preorder(node[current-'A'].second);
}

//중위순회
void inorder(char current){
    if(current == '.')
    return;

    inorder(node[current-'A'].first);
    cout << current;
    inorder(node[current-'A'].second);
}

//후위순회
void postorder(char current){
    if(current == '.')
    return;

    postorder(node[current-'A'].first);
    postorder(node[current-'A'].second);
    cout << current;
}

int main(){
  cin >> N;
    for(int i = 0; i < N; i++){
      char parent, left, right;
      cin >> parent >> left >> right;
      node[parent-'A'].first = left;
      node[parent-'A'].second = right;
    }
  
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}