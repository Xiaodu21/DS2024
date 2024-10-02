#include <iostream>
#include "Complex.h"
#include "../Mylab/Vector.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

//打印复数向量
void printComplexVector(const Vector<Complex>& v) {
	for(int i=0;i<v.size();i++) {
		std::cout << "(" << v[i].real << "+"<< v[i].imaginary << "i)";
	}
	std::cout << std::endl;
}

//比较复数模的函数
bool compare(const Complex& a, const Complex& b) {
	if(a.modulus() == b.modulus()) {
		return a.real < b.real;
	}
	return a.modulus() < b.modulus();
}
//起泡排序
void bubbleSort(Vector<Complex>& v) {
	for(int i=0;i<v.size()-1;i++) {
		for(int j=0;j<v.size()-1-i;j++) {
			if(compare(v[j], v[j+1])) {
				Complex temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
}
//归并排序 使用递归
void merge(Vector<Complex>& v, Vector<Complex>& left, Vector<Complex>& right) {
	int i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size()) {
		if (compare(left[i], right[j])) {
			v[k++] = left[i++];
		} else {
			v[k++] = right[j++];
		}
	}
	while (i < left.size()) {
		v[k++] = left[i++];
	}
	while (j < right.size()) {
		v[k++] = right[j++];
	}
}

void mergeSort(Vector<Complex>& v) {
	if (v.size() <= 1) {
		return;
	}
	Vector<Complex> left, right;
	for (int i = 0; i < v.size() / 2; i++) {
		left.insert(i, v[i]);
	}
	for (int i = v.size() / 2; i < v.size(); i++) {
		right.insert(i - v.size() / 2, v[i]);
	}
	mergeSort(left);
	mergeSort(right);
	merge(v, left, right);
}
//区间查找算法
Vector<Complex> intervalSearch(double m1, double m2, Vector<Complex>& v ) {
	Vector<Complex> result;
	for ( int i = 0; i < v.size(); i++ ) {
		double modulus = v[i].modulus();
		if ( modulus >= m1 && modulus <= m2) {
			result.insert(i, v[i]);
		}
	}
	return result;
}



//复数的查找函数

int main() {
	//定义一个人复数向量类
	Vector<Complex> complexvector;
	//初始化随机数种子
	srand(time(NULL));
	//随机生成复数向量
	for(int i=0; i < 10; i++) {
		complexvector.insert(i, Complex(rand() % 100, rand() % 100 ));
	}
	std::cout << "origin Vector: ";
	printComplexVector(complexvector);

	//置乱后的向量
	complexvector.unsort();
	std::cout << "After unsort: ";
	printComplexVector(complexvector);

	//查找函数
	Complex search_complex(3, 4);//待查找的元素
	int index = complexvector.find(search_complex);
	if (index != -1) {
		std::cout << "find success" << "in the " << index << " position " << std::endl;
	}
	else {
		std::cout << "find fail" << std::endl;
	}

	//插入操作
	complexvector.insert(0, Complex(1, 2));
	std::cout << "After insert:  ";
	printComplexVector(complexvector);

	//删除操作
	complexvector.remove(2);
	std::cout << "After deletion: ";
	printComplexVector(complexvector);

	//唯一化
	//先插入一个相同的元素
	complexvector.insert(0, Complex(1,2));
	printComplexVector(complexvector);
	complexvector.uniquify();
	std::cout << "After uniquify: ";
	printComplexVector(complexvector);
	//使用clock函数计时
	clock_t start, end;
	//顺序的向量的比较
	Vector<Complex> v1;
	for ( int i = 0; i < 10; i++ ) {
		v1.insert(i, Complex(i + 1, i + 1) );
	}
	std::cout << "Sorted Vector:";
	printComplexVector(v1);
	start = clock ();
	//使用起泡排序计时
	bubbleSort(v1);
	end = clock();
	std::cout << "Bubble Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
	//使用归并排序计时
	//直接对v1进行归并排序
	start = clock();
	//归并排序函数
	mergeSort(v1);
	end = clock();
	std::cout << "Merge Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;

	//逆序的向量的比较
	Vector<Complex> v2;
	for ( int i = 0; i < 10; i++ ) {
		v2.insert(i, Complex(10 - i, 10 - i) );
	}
	std::cout << "Reversed Vector:";
	printComplexVector(v2);

	//使用起泡排序计时
	start = clock ();
	bubbleSort(v2);
	end = clock();
	std::cout << "Bubble Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
	mergeSort(v2);
	end = clock();
	std::cout << "Merge Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;

	//随机的向量的比较
	Vector<Complex> v3;
	for ( int i = 0; i < 10; i++ ) {
		v3.insert(i, Complex(rand() % 100, rand() % 100) );
	}
	std::cout << "Random Vector:";
	printComplexVector(v3);
	start = clock ();
	bubbleSort(v3);
	end = clock();
	std::cout << "Bubble Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
	mergeSort(v3);
	end = clock();
	std::cout << "Merge Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;

	//定义一个顺序向量
	Vector<Complex> v4;
	for ( int i = 0; i < 10; i++ ) {
		v4.insert(i, Complex(i + 1, i + 1) );
	}
	std::cout << "Sorted Vector:";
	printComplexVector(v4);
	start = clock ();
	//随便假设一个区间
	Vector<Complex> result1 = intervalSearch(0, 6, v4);
	end = clock();
	std::cout << "Interval Search Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "Result: ";
	printComplexVector(result1);






	return 0;




}