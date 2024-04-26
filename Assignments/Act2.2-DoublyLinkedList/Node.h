#pragma once

template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev; // Nuevo puntero previo

    Node(T data);
    Node(T data, Node<T>* next, Node<T>* prev); // Modificado el constructor
};

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr; // Inicializar el puntero previo
}

template<class T>
Node<T>::Node(T data, Node<T>* next, Node<T>* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
