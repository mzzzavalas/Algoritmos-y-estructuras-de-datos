#ifndef Hash_h
#define Hash_h

template <class T>
class Hash {
private:
    vector<T> table;
    int hash(T value);
    vector<bool> status;

public:
    Hash();
    void insert(T value);
    void remove(T value);
    int find(T value);
    void print();
};

template <class T>
Hash<T>::Hash() {
    // Ajusta el tamaño de la tabla según sea necesario
    table.resize(225);
    status.resize(225, false);
}

template <class T>
int Hash<T>::hash(T value) {
    // Implementa la función de hash según tus necesidades
    // Este ejemplo asume que value es un tipo que se puede convertir a entero
    int number = stoi(value);
    return number % 225;
}

template <class T>
void Hash<T>::insert(T value) {
    int index = find(value);

    // Validamos si ya existe el dato en la tabla
    if (index == -1) {
        int index = hash(value);

        // Validamos que el espacio en la tabla en index esté vacío
        if (table[index] == T()) {
            table[index] = value;
            status[index] = false;
        } else {
            int newIndex = (index + 1) % table.size();

            // Recorremos la tabla mientras no le de la vuelta y hasta que encuentre un espacio vacío
            while (newIndex != index && table[newIndex] != T()) {
                newIndex = (newIndex + 1) % table.size();
            }

            // Validamos que si hubo un espacio vacío
            if (newIndex != index) {
                table[newIndex] = value;
                status[index] = false;
            } else {
                throw out_of_range("La tabla está llena");
            }
        }
    } else {
        throw out_of_range("El dato ya existe en la tabla");
    }
}

template <class T>
int Hash<T>::find(T value) {
    int index = hash(value);

    if (table[index] == value) {
        return index;
    } else {
        // Hay que buscarlo en la tabla
        // Recorremos la tabla hasta encontrarlo o encontrar un elemento vacío o le damos la vuelta
        int newIndex = (index + 1) % table.size();

        while (newIndex != index && (table[newIndex] != T() || status[newIndex])) {
            // Validamos si lo encontramos
            if (table[newIndex] == value) {
                return newIndex;
            } else {
                newIndex = (newIndex + 1) % table.size();
            }
        }
        return -1;
    }
}

template <class T>
void Hash<T>::remove(T value) {
    int index = find(value);
    if (index != -1) {
        table[index] = T();
        status[index] = true;
    } else {
        throw invalid_argument("El valor a borrar no se encuentra");
    }
}

template <class T>
void Hash<T>::print() {
    for (int i = 0; i < table.size(); i++) {
        cout << i << "-" << table[i] << " ";
    }
    cout << endl;
}


#endif /* HashStudentId_h */