#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* left_child;
    Node* right_child;

    Node( int val ){
        data = val;
        left_child = nullptr;
        right_child = nullptr;
    }
};

Node* Insert_Value (Node* r, int val);

int main(){
    srand( time(NULL) );
    Node* Root = new Node( 50 );
    
    for ( int i = 0; i < 50; i++ ){
        int v = ( rand()%100 )+1;
        Insert_Value ( Root, v );
    }
    system ("PAUSE");
    return 0;
}


Node* Insert_Value ( Node* r, int val ){
    
    if ( r == nullptr ){
        return new Node ( val );
    }

    if ( r->data == val ){
        return r;
    }
    
    if ( r->data > val ){
        r->right_child = Insert_Value ( r->right_child, val );
    }else{
        r->left_child = Insert_Value ( r->left_child, val );
    }

    return r;

}
