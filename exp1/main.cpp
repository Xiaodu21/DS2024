#include <iostream>
#include "Complex.h"
#include "../Mylab/Vector.h"
#include <ctime>
#include <cstdlib>

//打印复数向量
void printComplexVector(const Vector<Complex>& v) {
	for(int i=0;i<v.size();i++) {
		std::cout << '(' << v[i].real <<', '<< v[i].imaginary << ')';
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
	std::cout << '原始向量:';
	printComplexVector(complexvector);

	//置乱后的向量
	complexvector.unsort();
	std::cout << '置乱后的向量:';
	printComplexVector(complexvector);

	//查找函数
	Complex search_complex(3, 4);//待查找的元素
	int index = complexvector.find(search_complex);
	if (index != -1) {
		std::cout << '查找成功' << ' 元素在第' << index << '个位置' << std::endl;
	}
	else {
		std::cout << '查找失败' << std::endl;
	}

	//插入操作
	complexvector.insert(0, Complex(1, 2));
	std::cout << '插入后的向量:';
	printComplexVector(complexvector);

	//删除操作
	complexvector.remove(2);
	std::cout << "After deletion: ";
	printComplexVector(complexvector);

	//
	return 0;




}