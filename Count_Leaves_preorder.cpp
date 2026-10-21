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
int countLeaves (Node* r, int n);

int main (){
    srand( time(NULL) );
    Node* Root = new Node( 50 );
    
    for ( int i = 0; i < 50; i++ ){
        int v = ( rand()%100 )+1;
        Insert_Value ( Root, v );
    }
    
    cout<<"Number of leaves: "<<countLeaves ( Root , 0 )<<endl;

    system ("PAUSE");
    return 0;
}

/*Node* Insert_Value (Node* r, int val){
    
    if ( r == nullptr ){

        return new Node ( val );

    }

    Node* dad = nullptr;
    Node* current = r;

    while (current != nullptr ){
        dad = current;

        if ( current->data < val ){
            
            current = current->right_child;

        }else if ( current->data > val ){

            current = current->left_child;

        }else{

            return r;

        }

    }

    if ( dad->data < val ){

        dad->right_child = new Node (val);

    }else{

        dad->left_child = new Node (val);

    }

    return r;

}*/

int countLeaves (Node* r, int n){

    if ( r->left_child != nullptr ){

        n = n + countLeaves( r->left_child, 0 );

    }

    if ( r->right_child != nullptr ){

        n = n + countLeaves( r->right_child, 0 );

    }
    
    if ( r->left_child == nullptr && r->right_child == nullptr ){

        n++;

    }

    return n;

}
