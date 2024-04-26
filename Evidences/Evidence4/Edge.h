#pragma once

template <class T>
struct Edge {
    T source;
    T target;
    int TimeT;
    int DistanceT;
    int TimeC;
    int DistanceC;
    Edge();
    Edge(T source, T target);
    Edge(T source, T target, int TimeT, int DistanceT, int TimeC, int DistanceC);
};

template <class T>
Edge<T>::Edge() {
    TimeT = 0;
    DistanceT = 0;
    TimeC = 0;
    DistanceC = 0;
}

template <class T>
Edge<T>::Edge(T source, T target) {
    this->source = source;
    this->target = target;
    this->TimeT = 0;
    this->DistanceT = 0;
    this->TimeC = 0;
    this->DistanceC = 0;
}

template <class T>
Edge<T>::Edge(T source, T target, int TimeT, int DistanceT, int TimeC, int DistanceC) {
    this->source = source;
    this->target = target;
    this->TimeT = TimeT;
    this->DistanceT = DistanceT;
    this->TimeC = TimeC;
    this->DistanceC = DistanceC;
    
}