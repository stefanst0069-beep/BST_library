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
Node* findMax (Node* r);


int main (){
    srand( time(NULL) );
    Node* Root = new Node( 50 );
    
    for ( int i = 0; i < 50; i++ ){
        int v = ( rand()%100 )+1;
        Insert_Value ( Root, v );
    }

    Node* Max_ptr = findMax( Root );
    cout<<"Maximum value of the tree:"<<endl<<"Address: "<<Max_ptr<<endl<<"Number pointer: "<<Max_ptr->data<<endl<<endl;

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

Node* findMax (Node* r){

    if ( r->right_child == nullptr ){

        return r;

    }else{

        return findMax( r->right_child );

    }

}
