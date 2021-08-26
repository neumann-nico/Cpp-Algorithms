#include <QuickSort/QuickSort.h>

template<typename T>
QuickSort<T>::QuickSort(std::vector<T> &vec) : AbstractSort<T>(vec) {}

template<typename T>
void QuickSort<T>::sort() {
    quickSort(0, this->vec.size() - 1);
}

template<typename T>
void QuickSort<T>::quickSort(int low, int high) {
    if (low >= high) return;
    int pivot = this->partition(low, high);
    this->quickSort(low, pivot - 1);
    this->quickSort(pivot + 1, high);
}

template<typename T>
int QuickSort<T>::partition(int low, int high) {
    T pivot = this->vec[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (this->vec[j] <= pivot) {
            ++i;
            std::swap(this->vec[i], this->vec[j]);
        }
    }
    std::swap(this->vec[i + 1], this->vec[high]);
    return i + 1;
}

template
class QuickSort<int>;

template
class QuickSort<float>;

template
class QuickSort<double>;

template
class QuickSort<char>;