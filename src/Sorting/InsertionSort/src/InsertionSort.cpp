#include <InsertionSort/InsertionSort.h>

template <typename T>
InsertionSort<T>::InsertionSort(std::vector<T> &vec) : AbstractSort<T>(vec) {}

template <typename T>
void InsertionSort<T>::sort() {
    for (int i=0; i < this->vec.size(); ++i) {
        for (int j=i+1; j < this->vec.size(); ++j) {
            if (this->vec[j] < this->vec[i]) {
                std::swap(this->vec[i], this->vec[j]);
            }
        }
    }
}

template class InsertionSort<int>;
template class InsertionSort<float>;
template class InsertionSort<double>;
template class InsertionSort<char>;