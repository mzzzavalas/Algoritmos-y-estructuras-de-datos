#ifndef BST_h
#define BST_h

#include "TNode.h"
#include <queue>

using namespace std;

template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);
    int children(TNode<T>* aux);
    void preOrder(TNode<T>* aux);
    void inOrder(TNode<T>* aux);
    void postOrder(TNode<T>* aux);
    void levelByLevel(TNode<T>* aux);
public:
    BST();
    void insert(T data);
    bool find(T data);
    bool remove(T data);
    void visit(int order);
    void print();
    int height();
    int calculateHeight(TNode<T>* aux);
    void ancestors(T data);
    bool findAndPrintAncestors(TNode<T>* aux, T data);
    int whatLevelAml(T data);
    int findLevel(TNode<T>* aux, T data, int level);
    bool isEmpty();
    
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
void BST<T>::insert(T data) {
    // Validamos si el bst esta vacío
    if (isEmpty()) {
        // si está vacío
        // asignamos un nuevo nodo con el valor de data a root
        root = new TNode<T>(data);
    } else {
        // No está vacía
        // Creamos una apuntador auxiliar igual a root
        TNode<T>* aux = root;
        // Iteramos el arbol hasta encontrar donde insertar el valor de data (aux != nullptr)
        while (aux != nullptr) {
            // Comparamos si data es menor que aux->data
            if (data < aux->data) {
                // si es menor
                // Comparamos si el apuntador del lado izquierdo de aux es nulo
                if (aux->left == nullptr) {
                    // si es nulo
                    // agregamos un nuevo nodo con el valor de data al auntador del lado izquierdo de aux
                    aux->left = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // no es nulo
                    // asignamos a aux el aunptador del lado izquierdo de aux
                    aux = aux->left;
                }
            } else {
                // no es menor
                // Comparamos si el apuntador del lado derecho de aux es nulo
                if (aux->right == nullptr) {
                    // si es nulo
                    // agregamos un nuevo nodo con el valor de data al auntador del lado derecho de aux
                    aux->right = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // no es nulo
                    // asignamos a aux el aunptador del lado derecho de aux
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>  
bool BST<T>::find(T data) {
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // Recorremos el árbol para buscarlo
    while (aux != nullptr) {
        // Validamos si data es igual a aux-data
        if (data == aux->data) {
            return true;
        } else {
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    // no lo encontramos
    return false;
}

template <class T>
int BST<T>::children(TNode<T>* aux) {
    if (aux->left == nullptr && aux->right == nullptr) {
        return 0;
    }
    if (aux->left != nullptr && aux->right != nullptr) {
        return 2;
    }
    return 1;
}

template <class T>
bool BST<T>::remove(T data) {
    // buscar el nodo a borrar (debemos mantener un apuntador al papa del nodo a borrar)
    // Creamos un apuntador auxiliar padre igual a root
    TNode<T>* auxFather = root;
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // Recorremos el árbol para buscar el nodo
    // hacemos una variable booleana para saber si encontramos el nodo
    bool found = false;
    while (!found) {
        // Validamos si data es igual a aux->data
        if (data == aux->data) {
            // hacemo found igual a true
            found = true;
        } else {
            // Recorremos aux Father
            auxFather = aux;
            // Recorremos aux
            data < aux->data ? aux = aux->left : aux = aux->right;
            if (aux == nullptr) {
                // No se encuentra en el arbol
                return false;
            }
        }
    }
    // Buscamos cuantos hijos tiene el nodo
    int numChildren = children(aux);
    // 0 hijos
    if (numChildren == 0) {
        // Si el nodo a borrar es root
        if (aux == root) {
            // le asignamos nulos a root
            root = nullptr;
        } else { // El nodo no es root (else)
            aux->data < auxFather->data ? auxFather-> left = nullptr : auxFather-> right = nullptr;
            // Si el valor a borrar es menor al valor del padre
                // le asignamos nulos al apuntador del lado izquierdo del padre
            // Si el el valor es mayor o igual al valor del padre
                // le asignamos nulos al apuntador del lado derecho del padre
        }
        // borramos el nodo
        delete aux;
    }
    // 1 hijo
    if (numChildren == 1) {
        // Si el nodo a borrar es root
        if (aux == root) {
            aux->left != nullptr ? root = aux->left : root = aux->right;
            // Si el apuntador del lado izquierdo de root no es nulo (el hijo esta del lado izquierdo)
                // root va a ser igual al apuntador del lado izquierdo de root
            // si el apuntador del lado derecho de root no es nulo (el hijo esta del lado derecho)
                // root va a ser igual al apuntador del lado derecho de root
            // borramos el nodo que estaba en root
        } else { // Si el nodo a borrar no es root (else)
            // Si el valor del nodo a borrar es menor al valor del padre
            if (data < auxFather->data) {
                aux->left != nullptr ? auxFather->left = aux->left : auxFather->left = aux->right;
                // Si el apuntador del lado izquierdo del nodo a borrar no es nulo
                    // El apuntador del lado izquierdo del padre va a ser igual al apuntador del lado izquierdo del nodo a borrar
                // Si el apuntador del lado derecho del nodo a borrar no es nulo (else)
                    // El apuntador del lado izquierdo del padre va a ser igual al apuntador del lado derecho del nodo a borrar
            } else {                    
            // Si el valor del nodo a borrar es mayor o igual al valor del padre (else)
                aux->left != nullptr ? auxFather->right = aux->left : auxFather->right = aux->right;
                // Si el apuntador del lado izquierdo del nodo a borrar no es nulo
                    // El apuntador del lado derecho del padre va a ser igual al apuntador del lado izquierdo del nodo a borrar
                // Si el apuntador del lado derecho del nodo a borrar no es nulo (else)
                    // El apuntador del lado derecho del padre va a ser igual al apuntador del lado derecho del nodo a borrar
            }
        }
        // borramos el nodo
        delete aux;
    }
    // 2 hijos
    if (numChildren == 2) {
        // Si el apuntador del lado derecho del hijo del lado izquierdo del nodo a borrar es nulo (El hijo del lado izquierdo es el mayor)
        if (aux->left->right == nullptr) {
            // El valor del nodo a borrar va a ser igual al valor del hijo del lado izquierdo
            aux->data = aux->left->data;
            // Borramos el hijo del lado izquierdo del nodo a borrar
            TNode<T>* auxRemove = aux->left;
            // El apuntador del lado izquierdo del nodo a borrar va a ser igual al apuntador del lado izquierdo del hijo del lado izquierdo
            aux->left = aux->left->left;
            // Borramos el nodo
            delete auxRemove;
        } else {
        // Si el apuntador del lado derecho del hijo del lado izquierdo del nodo a borrar no es nulo (El hijo del lado izquierdo no es el mayor)
            // Creamos un apuntador auxiliar padre igual al hijo del lado izquierdo del nodo a borrar
            auxFather = aux->left;
            // Creamos un apuntador auxiliar hijo igual al apuntador del lado derecho del nodo auxiliar padre
            TNode<T>* auxChild = auxFather->right;
            // Iteramos mientras el apuntador del lado derecho del apuntador auxiliar hijo es diferente de nulo
            while (auxChild->right != nullptr) {
                // Reccorremos los apuntadores auxiliares
                // El apuntador auxiliar padre va a ser igual al apuntador auxiliar hijo
                auxFather = auxChild;
                // El apuntador auxiliar hijo va a ser igual al apuntador del lado derecho del apuntador auxiliar hijo
                auxChild = auxChild->right;
            }
            // El valor del nodo a borrar va a ser igual al valor del apuntador auxiliar hijo
            aux->data = auxChild->data;
            // El apuntador del lado derecho del auxiliar padre va a ser igual al apuntador del lado izquierdo del apuntador auxiliar hijo
            auxFather->right = auxChild->left;
            // Borramos el apuntador auxiliar hijo
            delete auxChild;
        }
    }
    return true;
}

template <class T>
void BST<T>::preOrder(TNode<T>* aux) {
    // condición de control
    if (aux != nullptr) {
        // Visita el nodo raíz del arbol
        cout << aux->data << " ";
        // Recorre el preorden el subárbol izquierdo del nodo raíz
        preOrder(aux->left);
        // Recorre el preorden el subárbol derecho del nodo raíz
        preOrder(aux->right);
    }
}


template <class T>
void BST<T>::inOrder(TNode<T>* aux) {
    // condición de control
    if (aux != nullptr) {
        // Recorre el en orden el subárbol izquierdo del nodo raíz
        inOrder(aux->left);
        // Visita el nodo raíz del arbol
        cout << aux->data << " ";
        // Recorre el en orden el subárbol derecho del nodo raíz
        inOrder(aux->right);
    }
}

template <class T>
void BST<T>::postOrder(TNode<T>* aux) {
    // condición de control
    if (aux != nullptr) {
        // Recorre el en post orden el subárbol izquierdo del nodo raíz
        postOrder(aux->left);
        // Recorre el en post orden el subárbol derecho del nodo raíz
        postOrder(aux->right);
        // Visita el nodo raíz del arbol
        cout << aux->data << " ";
    }
}

template <class T>
void BST<T>::levelByLevel(TNode<T>* aux) {
    queue< TNode<T>* > q;
    q.push(aux);
    while (!q.empty()) {
        TNode<T>* aux2 = q.front();
        cout << aux2->data << " ";
        q.pop();
        if (aux2->left != nullptr) {
            q.push(aux2->left);
        }
        if (aux2->right != nullptr) {
            q.push(aux2->right);
        }
    }
}

template <class T>
void BST<T>::visit(int order) {
    switch (order) {
    case 1:
        preOrder(root);
        cout << endl;
        break;
    case 2:
        inOrder(root);
        cout << endl;
        break;
    case 3:
        postOrder(root);
        cout << endl;
        break;
    case 4:
        levelByLevel(root);
        cout << endl;
        break;
    
    default:
        break;
    }
}

template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 


template <class T>
int BST<T>::height() {
    return calculateHeight(root);
}

template <class T>
int BST<T>::calculateHeight(TNode<T>* aux) {
    if (aux == nullptr) {
        return 0;
    } else {
        int leftHeight = calculateHeight(aux->left);
        int rightHeight = calculateHeight(aux->right);

        // La altura del BST es el máximo entre la altura del subárbol izquierdo y derecho, más 1 para contar el nodo actual.
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

template <class T>
void BST<T>::ancestors(T data) {
    findAndPrintAncestors(root, data);
}

template <class T>
bool BST<T>::findAndPrintAncestors(TNode<T>* aux, T data) {
    if (aux == nullptr) {
        return false;
    }
    if (aux->data == data) {
        return true;
    }

    // Si el dato no se encuentra en el nodo actual, intentamos encontrarlo en los subárboles izquierdo y derecho.
    if (findAndPrintAncestors(aux->left, data) || findAndPrintAncestors(aux->right, data)) {
        // Si encontramos el dato en alguno de los subárboles, imprimimos el valor del nodo actual como ancestro.
        cout << aux->data << " ";
        return true;
    }

    return false;
}

template <class T>
int BST<T>::whatLevelAml(T data) {
    return findLevel(root, data, 0); // Comenzamos desde el nivel 0
}

template <class T>
int BST<T>::findLevel(TNode<T>* aux, T data, int level) {
    if (aux == nullptr) {
        return -1; // El dato no se encuentra en el árbol, devolvemos -1.
    }
    if (aux->data == data) {
        return level; // Encontramos el dato, devolvemos el nivel actual.
    }

    // Intentamos encontrar el dato en los subárboles izquierdo y derecho.
    int leftLevel = findLevel(aux->left, data, level + 1);
    int rightLevel = findLevel(aux->right, data, level + 1);

    // Si el dato se encuentra en alguno de los subárboles, devolvemos el nivel correspondiente.
    return (leftLevel != -1) ? leftLevel : rightLevel;
}


template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}






#endif 