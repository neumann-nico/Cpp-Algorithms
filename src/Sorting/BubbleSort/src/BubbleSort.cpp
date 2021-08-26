#include <BubbleSort/BubbleSort.h>

template<typename T>
BubbleSort<T>::BubbleSort(std::vector<T> &vec) : AbstractSort<T>(vec) {}

template<typename T>
void BubbleSort<T>::sort() {
    for (int i = 0; i < this->vec.size(); ++i) {
        for (int j = 0; j < this->vec.size() - i - 1; ++j) {
            if (this->vec[j + 1] < this->vec[j]) {
                std::swap(this->vec[j], this->vec[j + 1]);
            }
        }
    }
}

template
class BubbleSort<int>;

template
class BubbleSort<float>;

template
class BubbleSort<double>;

template
class BubbleSort<char>;