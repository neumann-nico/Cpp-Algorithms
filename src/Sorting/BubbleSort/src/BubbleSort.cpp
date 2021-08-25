#include <BubbleSort/BubbleSort.h>

template <typename T>
BubbleSort<T>::BubbleSort(std::vector<T> &vec) : AbstractSort<T>(vec) {}

template <typename T>
void BubbleSort<T>::sort() {
    for (int i=0; i < this->vec.size(); ++i) {
        for (int j=i+1; j < this->vec.size(); ++j) {
            if (this->vec[j] < this->vec[i]) {
                T temp = this->vec[i];
                this->vec[i] = this->vec[j];
                this->vec[j] = temp;
            }
        }
    }
}

template class BubbleSort<int>;
template class BubbleSort<float>;
template class BubbleSort<double>;
template class BubbleSort<char>;