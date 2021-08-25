#include <AbstractSort/AbstractSort.h>

template <typename T>
AbstractSort<T>::AbstractSort(std::vector<T> &vec) : vec(vec) {}

template <typename T>
bool AbstractSort<T>::isSorted() {
    for (int i=0; i < vec.size() - 1; ++i) {
        if (i+1 < vec.size() && vec[i] > vec[i+1]) return false;
    }
    return true;
}

template <typename T>
void AbstractSort<T>::setVector(std::vector<T> &vec) {
    this->vec = vec;
}

template <typename T>
std::vector<T>& AbstractSort<T>::getVector() {
    return this->vec;
}

template <typename T>
void AbstractSort<T>::printVector() {
    std::cout << "[";
    for (int i=0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size()-1){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

template class AbstractSort<int>;
template class AbstractSort<float>;
template class AbstractSort<double>;
template class AbstractSort<char>;