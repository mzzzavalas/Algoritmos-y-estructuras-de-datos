#ifndef HashStudentId_h
#define HashStudentId_h

class HashStudentId {
private:
    vector<string> table;
    int hash(string studentId);
    vector<bool> status;
public:
    HashStudentId();
    void insert(string studentId);
    void remove(string studentId);
    int findStudentId(string studentId);
    void print();
};

HashStudentId::HashStudentId() {
    table.resize(11);
    status.resize(11, false);
}

int HashStudentId::hash(string studentId) {
    // Función para definir la función de Hashing
    // convertir string a numero sin considerar el primer caracter ejemplo A00189239 = 00189239

    // int number = 0;
    // for (int i = 1; i < studentId.length(); i++) {
    //     number = number * 10 + (studentId[i] - '0');
    // }
    // return number % 11;
    int number = stoi(studentId);
    return number % 11;
    
}

void HashStudentId::insert(string studentId) {
    int index = findStudentId(studentId);
    // Validamos si ya existe el dato en la tabla
    if (index == -1) {
        int index = hash(studentId);
        // Validamos que el espacio en la tabla en index este vacio
        if (table[index].empty()) {
            table[index] = studentId;
            status[index] = false;
        } else {
            int newIndex = (index+1)%table.size();
            // Recorro la tabla mientras no le de la vuelta y hasta que ecuentre un espacio vacio
            while (newIndex != index && !table[newIndex].empty()) {
                newIndex = (newIndex+1)%table.size();
            }
            // Validamos que si hubo un espacio vacío
            if (newIndex != index) {
                table[newIndex] = studentId;
                status[index] = false;
            } else {
                throw out_of_range("La tabla esta llena");
            }
        }
    } else {
        throw out_of_range("El dato ya existe en la tabla");
    }
}

int HashStudentId::findStudentId(string studentId) {
    int index = hash(studentId);
    if (table[index] == studentId) {
        return index;
    } else {
        // Hay que buscarlo en la tabla
        // Recorremos la tabla hasta encontrarlo o encontrar un elemento vacío o le damos la vuelta
        int newIndex = (index+1)%table.size();
        while (newIndex != index && (!table[newIndex].empty() || status[newIndex])) {
            // Validamos si lo encontramos
            if (table[newIndex] == studentId) {
                return newIndex;
            } else {
                newIndex = (newIndex+1)%table.size();
            }
        }
        return -1;
    }
}

void HashStudentId::remove(string studentId) {
    int index = findStudentId(studentId);
    if (index != -1) {
        table[index] = "";
        status[index] = true;
    } else {
        throw invalid_argument("El valor a borrar no se encuentra");
    }
}

void HashStudentId::print() {
    for (int i=0; i<table.size(); i++) {
        cout << i << "-" << table[i] << " ";
    }
    cout << endl;
}


#endif /* HashStudentId_h */