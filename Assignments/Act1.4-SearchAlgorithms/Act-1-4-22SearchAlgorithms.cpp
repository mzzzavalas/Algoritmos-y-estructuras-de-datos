//Mauricio Zavala Sánchez
//A00837332
//ITC
// 9/8/2023
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int busquedaSecuencial(const string& str, char caracter) {
    int comparaciones = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        comparaciones++;
        if (str[i] == caracter) {
            return comparaciones;
        }
    }
    return comparaciones;
}

int busquedaBinaria(const string& str, char caracter) {
    int comparaciones = 0;
    int l = 0, r = str.length() - 1;
    while (l <= r) {
        comparaciones++;
        int mid = l + (r - l) / 2;
        if (str[mid] == caracter) {
            return comparaciones;
        } else if (caracter < str[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return comparaciones;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Ignorar el salto de línea después del número

    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);

        char caracterUnico = '\0';
        bool encontrado = false;
        for (size_t j = 0; j < str.length(); ++j) {
            if (j == 0 || str[j] != str[j - 1]) {
                if (j == str.length() - 1 || str[j] != str[j + 1]) {
                    caracterUnico = str[j];
                    encontrado = true;
                    break;
                }
            }
        }

        if (!encontrado) {
            cout << "No se encontró un carácter único en el string." << endl;
            continue;
        }

        int comparacionesSecuencial = busquedaSecuencial(str, caracterUnico);
        int comparacionesBinaria = busquedaBinaria(str, caracterUnico);

        cout << caracterUnico << " " << comparacionesSecuencial << " ";
        cout << caracterUnico << " " << comparacionesBinaria << endl;
    }

    return 0;
}
