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

// Esercitazione (90 minuti): refactoring di un BST, da struct a classi - classe 4C
// Nome/Codice: ______________________
//
// Trasforma la libreria del Binary Search Tree: la struct Node diventa una classe con
// attributi privati e le funzioni libere diventano metodi di una nuova classe BST.
// I nomi dei metodi sono quelli scritti qui sotto e usati da main.cpp: decidi tu
// parametri e tipo restituito, guardando anche come li usa main.cpp.
// NON modificare main.cpp. Consegna SOLO questo file (bst.cpp).
// Se un metodo non riesci a scriverlo, lascia almeno una versione vuota
// (che restituisce un valore qualsiasi) per far compilare il programma.

#include <iostream>
using namespace std;

// =====================================================================
// PARTE A - la classe Node (circa 15 minuti)
// =====================================================================

class Node {
private:
    // TODO 1 - gli attributi: la chiave (int) e i puntatori ai due figli.
    //          Usa gli stessi nomi della struct originale: data, left, right.
    int data;
    Node* left;
    Node* right;

public:
    // TODO 1 - costruttore Node
    //          Riceve la chiave. All'inizio il nodo non ha figli (entrambi i puntatori valgono nullptr).
    //          Dai al parametro un nome diverso da quello dell'attributo.
    Node (int key){
        data = key;
        left = nullptr;
        right = nullptr;
    }

    // TODO 2 - getData, getLeft, getRight
    //          Restituiscono la chiave, il figlio sinistro e il figlio destro.
    int getData(){
        return data;
    }

    Node* getLeft(){
        return left;
    }

    Node* getRight(){
        return right;
    }

    // TODO 3 - setData, setLeft, setRight
    //          Modificano la chiave e collegano il figlio sinistro e il figlio destro.
    //          setLeft e setRight ricevono l'indirizzo di un nodo (o nullptr per scollegare).
    void setData(int key){
        data=key;
    }

    void setLeft(Node* child){
        left=child;
    }

    void setRight(Node* child){
        right=child;
    }

    // TODO 4 - isLeaf
    //          Dice se il nodo e' una foglia, cioe' se non ha nessun figlio.
    bool isLeaf (){
        if (left == nullptr && right == nullptr){
            return true;
        }
        return false;
    }

};

// =====================================================================
// PARTE B - la classe BST: struttura, inserimento, ricerca, visita (circa 30 minuti)
// L'albero conosce solo la radice e il numero di nodi: da fuori non si vede nessun Node.
// =====================================================================

class BST {
private:
    Node* root;         // radice dell'albero, nullptr se l'albero e' vuoto
    int numNodi;        // numero di chiavi presenti

    // Qui puoi aggiungere funzioni di appoggio private (per esempio quelle ricorsive,
    // che hanno bisogno di ricevere un nodo come argomento).

public:
    // TODO 5 - costruttore BST, isEmpty, size
    //          Il costruttore crea un albero vuoto. isEmpty dice se l'albero e' vuoto,
    //          size restituisce quante chiavi contiene.
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
        numNodi = count_Nodes(root);
        return numNodi;
        
    }


    // TODO 6 - insert
    //          Riceve una chiave e la inserisce al posto giusto creando un nuovo Node con new.
    //          Niente duplicati: se la chiave e' gia' presente non fa nulla.
    //          Dice se la chiave e' stata inserita.
    bool insert(int key){
        Node* newNode = new Node (key);
             
        if (root==nullptr){
            root = new Node (key);
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
                delete newNode;
                return false;

            }

        }
        
        if (key < padre->getData()){
            padre->setLeft(newNode);
            return true;
            
        }else if (key > padre->getData()){
            padre->setRight(newNode);
            return true;
        }

        return false;

    }

    // TODO 7 - search
    //          Dice se una chiave e' presente nell'albero (non modifica l'albero).
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

    // TODO 8 - inOrder
    //          Stampa su cout tutte le chiavi in ordine crescente (visita inorder),
    //          ciascuna seguita da uno spazio. Se l'albero e' vuoto non stampa nulla.
    //          Non va a capo: ci pensa il main.
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

    // TODO 9 - height
    //          Restituisce l'altezza dell'albero, cioe' il numero di nodi del cammino piu' lungo
    //          dalla radice a una foglia. Albero vuoto: 0.
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

    // TODO 10 - minimo, massimo
    //          Restituiscono la chiave piu' piccola e quella piu' grande.
    //          Per un albero vuoto restituiscono -1 (nell'esercizio le chiavi sono sempre positive).
    
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

    // =================================================================
    // PARTE C - cancellazione e memoria (circa 30 minuti)
    // =================================================================

    // TODO 11 - remove
    //          Elimina una chiave dall'albero e dice se esisteva. Gestisci i tre casi:
    //          nodo senza figli, con un figlio, con due figli (si sostituisce la chiave con
    //          quella del successore). Ogni nodo tolto va liberato con delete.
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
                return true;
            
            }else{
                delete corrente;
                padre->setRight(nullptr);
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
                return true;
            }else{
                
                if (corrente->getLeft()!=nullptr){
                    
                    if (padre->getData()>corrente->getData()){
                        padre->setLeft(corrente->getLeft());
                        delete corrente;
                        return true;
                        
                    }else{
                        padre->setRight(corrente->getLeft());
                        delete corrente;
                        return true;
                    }

                }else{
                   if (padre->getData()>corrente->getData()){
                        padre->setLeft(corrente->getRight());
                        delete corrente;
                        return true;
                        
                    }else{
                        padre->setRight(corrente->getRight());
                        delete corrente;
                        return true;
                    } 
                }
            }
        }
        return false;
    }

    // TODO 12 - svuota
    //          Libera con delete tutti i nodi e riporta l'albero allo stato vuoto.
    //          Deve poter essere chiamata anche due volte di fila senza danni.
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
        root=nullptr;
    }

    // TODO 13 - contaFoglie
    //          Restituisce quante foglie ha l'albero (usa isLeaf). Albero vuoto: 0.
    int contaFoglie2(Node* r){
        if (r==nullptr){
            return 0;
        }
        contaFoglie2(r->getLeft());
        contaFoglie2(r->getRight());
        return (r->isLeaf()? 1 : 0);
    }
    
    int contaFoglie(){

        return contaFoglie2(root);

    }

    // BONUS TODO 14 - contaIntervallo
    //          Riceve due chiavi low e high e restituisce quante chiavi dell'albero sono comprese
    //          tra low e high (estremi inclusi). Sfrutta la proprieta' del BST: non serve
    //          visitare i sottoalberi che non possono contenere chiavi dell'intervallo.
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
