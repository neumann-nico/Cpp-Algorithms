#include <MergeSort/MergeSort.h>

template<typename T>
MergeSort<T>::MergeSort(std::vector<T> &vec) : AbstractSort<T>(vec) {}

template<typename T>
void MergeSort<T>::sort() {
    this->mergeSort(0, this->vec.size() - 1);
}

template<typename T>
void MergeSort<T>::mergeSort(int low, int high) {
    if (low >= high) return;
    int middle = low + (high - low) / 2;
    mergeSort(low, middle);
    mergeSort(middle + 1, high);

    merge(low, middle, high);
}

template<typename T>
void MergeSort<T>::merge(int low, int middle, int high) {
    int start = low;
    int start2 = middle + 1;

    if (this->vec[middle] <= this->vec[start2]) return;

    while (start <= middle && start2 <= high) {
        if (this->vec[start] <= this->vec[start2]) {
            ++start;
        } else {
            T value = this->vec[start2];
            int index = start2;
            while (index != start) {
                this->vec[index] = this->vec[index - 1];
                --index;
            }
            this->vec[start] = value;
            ++start;
            ++middle;
            ++start2;
        }
    }
}

template
class MergeSort<int>;

template
class MergeSort<float>;

template
class MergeSort<double>;

template
class MergeSort<char>;