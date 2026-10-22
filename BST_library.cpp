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
