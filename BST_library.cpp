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

class Node {
private:

    int data;
    Node* left;
    Node* right;

public:

    Node (int key){
        data = key;
        left = nullptr;
        right = nullptr;
    }

    int getData(){
        return data;
    }

    Node* getLeft(){
        return left;
    }

    Node* getRight(){
        return right;
    }

    void setData(int key){
        data=key;
    }

    void setLeft(Node* child){
        left=child;
    }

    void setRight(Node* child){
        right=child;
    }

    bool isLeaf (){
        if (left == nullptr && right == nullptr){
            return true;
        }
        return false;
    }

};

class BST {
private:
    Node* root;    
    int numNodi;        

public:
    BST (){
        root = nullptr;
        numNodi = 0;
    }

    bool isEmpty(){
        if (root == nullptr){
            return true;
        }
        return false;
    }

    int count_Nodes ( Node* r ){
        if ( r == nullptr ){
            return 0;
        }
        return 1 + count_Nodes( r->getLeft() ) + count_Nodes( r->getRight());
    }

    int size(){
        return count_Nodes(root);
        
    }

    bool insert(int key){
             
        if (root==nullptr){
            root = new Node (key);
            numNodi++;
            return true;
        }

        Node* corrente = root;
        Node* padre = nullptr;

        while (corrente != nullptr){
            padre = corrente;

            if (key < corrente->getData()){
                corrente = corrente->getLeft();

            }else if (key > corrente->getData()){
                corrente = corrente->getRight();

            }else{
                return false;

            }

        }
        
        if (key < padre->getData()){
            padre->setLeft(new Node (key));
            numNodi++;
            return true;
            
        }else if (key > padre->getData()){
            padre->setRight(new Node (key));
            numNodi++;
            return true;
        }

        return false;

    }

    bool search (int key){
        
        if (root == nullptr){
            return false;
        }

        Node* corrente = root;
        
        while(corrente!=nullptr){

            if (corrente->getData() == key){
                return true;
            }
            
            if(key<corrente->getData()){
                corrente=corrente->getLeft();
                
            }else{
                corrente=corrente->getRight();
            }

        }
        return false;
    }

    void inorder(Node* r){
        if (r==nullptr){
            return ;
        }
        inorder(r->getLeft());
        cout<<r->getData()<<" ";
        inorder(r->getRight());
    }

    void inOrder(){
        inorder(root);
    }

    int height2(Node* root) {
    
        if (root == nullptr){
            return 0;
        }
        int sinistra = 1 + height2(root->getLeft());
        int destra = 1 + height2(root->getRight());
    
        if (sinistra>destra){
            return sinistra;
        
        }else{
            return destra;
        }
    
    }

    int height(){
        return height2(root);
    }
    
    int minimo(){
        
        if (root == nullptr){
            return -1;
        }

        Node* corrente=root;
        Node* padre=nullptr;

        
        while (corrente!=nullptr){
            padre=corrente;
            corrente=corrente->getLeft();
        }
        return padre->getData();
    }

    int massimo(){
        
        if (root == nullptr){
            return -1;
        }

        Node* corrente=root;
        Node* padre=nullptr;

        
        while (corrente!=nullptr){
            padre=corrente;
            corrente=corrente->getRight();
        }
        return padre->getData();
    }

    bool remove (int key){
        
        if (root==nullptr){
            return false;
        }

        Node* corrente = root;
        Node* padre=nullptr;
        
        while(corrente!=nullptr && corrente->getData()!=key){
            padre=corrente;
            
            if(key<corrente->getData()){
                corrente=corrente->getLeft();
                
            }else{
                corrente=corrente->getRight();
            }

        }
        
        if (corrente == nullptr){
            return false;
        }
        
        if (corrente->getLeft()==nullptr && corrente->getRight()==nullptr){
            
            if (padre->getData()>corrente->getData()){
                delete corrente;
                padre->setLeft(nullptr);
                numNodi--;
                return true;
            
            }else{
                delete corrente;
                padre->setRight(nullptr);
                numNodi--;
                return true;

            }
            
        }

        if (corrente->getLeft()!=nullptr || corrente->getRight()!=nullptr){
            
            if (corrente->getLeft()!=nullptr && corrente->getRight()!=nullptr){
                padre=corrente;
                corrente=corrente->getRight();
                Node* pTemp = nullptr;
                while(corrente->getLeft()!=nullptr){
                    pTemp=corrente;
                    corrente=corrente->getLeft();
                }
                int temp = corrente->getData();
                corrente->setData(padre->getData());
                padre->setData(temp);
                pTemp->setLeft(nullptr);
                delete corrente;
                numNodi--;
                return true;
            }else{
                
                if (corrente->getLeft()!=nullptr){
                    
                    if (padre->getData()>corrente->getData()){
                        padre->setLeft(corrente->getLeft());
                        delete corrente;
                        numNodi--;
                        return true;
                        
                    }else{
                        padre->setRight(corrente->getLeft());
                        delete corrente;
                        numNodi--;
                        return true;
                    }

                }else{
                   if (padre->getData()>corrente->getData()){
                        padre->setLeft(corrente->getRight());
                        delete corrente;
                        numNodi--;
                        return true;
                        
                    }else{
                        padre->setRight(corrente->getRight());
                        delete corrente;
                        numNodi--;
                        return true;
                    } 
                }
            }
        }
        return false;
    }

    void svuota2(Node* r){
        if (r==nullptr){
            return ;
        }
        svuota2(r->getLeft());
        svuota2(r->getRight());
        delete r;
    }

    void svuota(){
        svuota2(root);
        numNodi = 0;
        root=nullptr;
    }

    int contaFoglie2(Node* r, int count){
        if (r==nullptr){
            return 0;
            
        }
        
        if (r->isLeaf()==true){
            return 1;
        }
        count = count + contaFoglie2(r->getLeft(), 0);
        count = count + contaFoglie2(r->getRight(), 0); 

        return count;
    }
    
    int contaFoglie(){

        return contaFoglie2(root, 0);

    }

    int contaIntervallo2(Node* root, int low, int high, int count) {
        if (root==nullptr){
            return 0;
        }

        if (low <= root->getData() && high >= root->getData()){
            count++;
        }
    
        if (low < root->getData()){
            count=count+contaIntervallo2(root->getLeft(), low, high, 0);
        }
    
        if (high > root->getData()){
            count=count+contaIntervallo2(root->getRight(), low, high, 0);
        }
        return count;

    }
    
    int contaIntervallo (int low, int high){
        return contaIntervallo2(root, low, high, 0);
    }
};
    
    int contaIntervallo (int low, int high){
        return contaIntervallo2(root, low, high, 0);
    }
};
