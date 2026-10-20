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

Node* InsertVal (Node* r, int val);
Node* Search_Value (Node* &r, int val);

int main(){
    srand( time(NULL) );
    Node* Root = new Node( 50 );
    
    for ( int i = 0; i < 50; i++ ){
        int v = ( rand()%100 )+1;
        InsertVal ( Root, v );
    }
    int val = 0;
    cin>>val;
    Node* Searched_number_ptr = ( 0 );
    Searched_number_ptr = Search_Value ( Root, val );
    if ( Searched_number_ptr != nullptr ){
        cout<<"Address: "<<Searched_number_ptr<<endl<<"Number pointer: "<<Searched_number_ptr->data<<endl;
    }

    system ("PAUSE");
    return 0;
}

/*Node* InsertVal ( Node* r, int val ){
    
    if ( r == nullptr ){
        return new Node ( val );
    }

    if ( r->data == val ){
        return r;
    }
    
    if ( r->data < val ){
        r->right_child = InsertVal ( r->right_child, val );
    }else{
        r->left_child = InsertVal ( r->left_child, val );
    }

    return r;

}*/

Node* Search_Value (Node* &r, int val){

    if ( r == nullptr ){
        cout<<"Unfound value"<<endl;
        return nullptr;
    }

    if ( r->data == val ){
        cout<<"Founded value"<<endl;
        return r;
    }
    
    if ( r->data < val ){
        return Search_Value ( r->right_child, val );
    }else{
        return Search_Value ( r->left_child, val ); 
    }

}
