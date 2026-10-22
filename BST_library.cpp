#include <iostream>

Node* Insert_Value_recoursive ( Node* r, int val ){
    
    if ( r == nullptr ){
        return new Node ( val );
    }

    if ( r->data == val ){
        return r;
    }
    
    if ( r->data < val ){
        r->right_child = Insert_Value_recoursive ( r->right_child, val );
    }else{
        r->left_child = Insert_Value_recoursive ( r->left_child, val );
    }

    return r;

}

Node* Insert_Value_iterative (Node* r, int val){
    
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

}

Node* Search_Value_recoursive (Node* &r, int val){

    if ( r == nullptr ){
        cout<<"Unfound value"<<endl;
        return nullptr;
    }

    if ( r->data == val ){
        cout<<"Founded value"<<endl;
        return r;
    }
    
    if ( r->data < val ){
        return Search_Value_recoursive ( r->right_child, val );
    }else{
        return Search_Value_recoursive ( r->left_child, val ); 
    }

}

Node* find_Minimum (Node* r){

    if ( r->left_child == nullptr ){

        return r;

    }else{

        return find_Minimum( r->left_child );

    }

}

Node* find_Maximum (Node* r){

    if ( r->right_child == nullptr ){

        return r;

    }else{

        return find_Maximum( r->right_child );

    }

}
