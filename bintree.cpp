#include <iostream>
using namespace std;
#include <stdio.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<vector>
#include<sstream>

struct binaryTree{
    int n;
    vector <int> a;
    binaryTree (int c){
        n = c;
        int num = pow(2,n+1)-1;
        for (int i=0;i < num; i++){
            a.push_back(-1);
        }
    }
};

string numberToString (int number) {
     stringstream ss;
     ss << number;
     return ss.str();
}

void printTree(binaryTree *bst){
    int size = pow(2,bst ->n+1)-1;
    for(int i =0; i< size; i++){
        cout << numberToString(bst->a[i]);
        if(i != size-1){
            cout << ",";
        }else{
            cout<< ".";
        }
    }
    cout<< "\n";
}

void preOrderRepn(binaryTree *bst, int i){
    /*if(bst->a[n]==0 || n > bst->a.size()-1){
        return;
    }
    if(n==bst->a.size()-1){
        cout << numberToString(bst->a[n]) << ".";
    }else{
        cout << numberToString(bst->a[n]) << ",";
    }

    preOrderRepn(bst, n*2+1);

    preOrderRepn(bst, n*2+2);*/
    binaryTree* bst2 ;
    /*for(int j=0; j < bst->a.size();j++){
        bst2->a[j] = bst->a[j];
    }*/

    if(i < bst->a.size()){
        
        if(bst->a[i]!=0){
            if(i==bst->a.size()-1){
                cout << numberToString(bst->a[i])<< ".\n";
            }else{
                cout << numberToString(bst->a[i])<< ",";
            }
        }else{
            return;
        }
        
        preOrderRepn(bst2, i*2+1);
        preOrderRepn(bst2, i*2+2);
    }else{
        return;
    }
   

}

int main(){
    binaryTree *bst; 
    int node;
    cout << "Enter number of levels:\n";
    cin >> bst -> n; // Enter number of levels

    cout << "Enter the node from which you will start the traversal: \n";
    cin >> node;

    int size = pow(2,bst ->n+1)-1;
    cout << "Max number of possible elements is: " << size << endl;

    for (int i=0; i < size; i++){
        int val;
        cin >> val;
        bst -> a[i]=val;
    }
    
    printTree(bst);

    preOrderRepn(bst, node);

    return 0;
}