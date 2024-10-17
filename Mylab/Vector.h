#include <iostream>
#include <algorithm>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T>
class Vector {
protected:
    Rank _size;          // 元素的个数
    int _capacity;       // 向量的容量
    T* _elem;            // 数据指针

    // 内部函数：从A中复制元素，范围为[lo, hi)
    void copyFrom(T const* A, Rank lo, Rank hi);
    // 扩展容量
    void expand();
    // 缩减容量
    void shrink();
    // 冒泡排序的核心部分
    bool bubble(Rank lo, Rank hi);
    // 冒泡排序
    void bubbleSort(Rank lo, Rank hi);
    // 选择排序
    void selectionSort(Rank lo, Rank hi);
    // 归并排序
    void mergeSort(Rank lo, Rank hi);
    // 归并过程
    void merge(Rank lo, Rank mi, Rank hi);
    // 快速排序
    void quickSort(Rank lo, Rank hi);
    // 堆排序
    void heapSort(Rank lo, Rank hi);

public:
    // 构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v);
    }

    // 拷贝构造函数
    Vector(T const* A, Rank n) { copyFrom(A, 0, n); }
    Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
    Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }
    Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }

    // 析构函数
    ~Vector() { delete[] _elem; }

    // 返回向量大小
    Rank size() const { return _size; }
    // 判断向量是否为空
    bool empty() const { return !_size; }

    // 查找元素
    Rank find(T const& e) const { return find(e, 0, _size); }
    Rank find(T const& e, Rank lo, Rank hi) const;

    // 重载下标运算符
    T& operator[](Rank r) const;
    Vector<T>& operator=(Vector<T> const&);

    // 插入元素
    Rank insert(Rank r, T const& e);
    Rank insert(T const& e) { return insert(_size, e); }

    // 删除元素
    T remove(Rank r);
    int remove(Rank lo, Rank hi);

    // 遍历向量
    void traverse(void (*func)(T&));
    template <typename VST> void traverse(VST&);

    // 扩展push_back函数，用于在末尾插入元素
    void push_back(const T& e);
    // 扩展pop_back函数，用于从末尾删除元素
    void pop_back();
};

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi)
        _elem[_size++] = A[lo++];
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V) {
    if (_elem) delete[] _elem;
    copyFrom(V._elem, 0, V.size());
    return *this;
}

template <typename T>
void Vector<T>::expand() {
    if (_size < _capacity) return;
    if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T* oldElem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete[] oldElem;
}

template <typename T>
void Vector<T>::shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1) return;
    if (_size << 2 > _capacity) return;
    T* oldElem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++) _elem[i] = oldElem[i];
    delete[] oldElem;
}

template <typename T>
T& Vector<T>::operator[](Rank r) const {
    return _elem[r];
}

template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
    while ((lo < hi--) && (e != _elem[hi]));
    return hi;
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
    expand();
    for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++;
    return r;
}

template <typename T>
T Vector<T>::remove(Rank r) {
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
    if (lo == hi) return 0;
    while (hi < _size) _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo;
}

template <typename T>
void Vector<T>::push_back(const T& e) {
    expand();
    _elem[_size++] = e;
}

template <typename T>
void Vector<T>::pop_back() {
    if (_size > 0) {
        _size--;
    }
    shrink();
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T&)) {
    for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST& visit) {
    for (int i = 0; i < _size; i++) visit(_elem[i]);
}
