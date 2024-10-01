#include "../Mylab/Vector.cpp"
template <typename T> class Stack : public Vector<T> {
public:
	void push(T const& e) { increase(size(), e); }
	T pop() { return remove(size() - 1); }
	T& top() { return (*this)[size() - 1]; }
};
//进制转化算法
void convert(Stack<char>& S, __int64 n, int base) {
	static char digit[]
		= { '0', '1', '2', '3','4', '5', '6', '7', '8', '9', 'A','B','C', 'D', 'E', 'F' };
	if (0 < n) {
		S.push(digit[n % base]);
		convert(S, n / base, base);
	}
}
//进制转化算法(迭代版）
void convert(Stack<char>& S, __int64 n, int base) {
	static char digit[]
		= { '0', '1', '2', '3','4', '5', '6', '7', '8', '9', 'A','B','C', 'D', 'E', 'F' };
	while (0 < n) {
		int remainder = (int)(n % base);S.push(digit[remainder]);
		n /= base;
	}
}
//优先级表格的定义
#define N_OPTR 9 // 运算符的数目

// 运算符枚举类型定义：加、减、乘、除、乘方、阶乘、左括号、右括号、起始符号与终止符
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator;
// 加、减、乘、除、乘方、左括号、右括号、起始符号与终止符

// 运算符优先等级表：栈顶运算符与当前运算符之间的优先关系
const char pri[N_OPTR][N_OPTR] = {
	/*          +    -    *    /    ^    !    (    )    \0 */
	/* + */  '>', '>', '<', '<', '<', '<', '<', '>', '>',
	/* - */  '>', '>', '<', '<', '<', '<', '<', '>', '>',
	/* * */  '>', '>', '>', '>', '<', '<', '<', '>', '>',
	/* / */  '>', '>', '>', '>', '<', '<', '<', '>', '>',
	/* ^ */  '>', '>', '>', '>', '>', '<', '<', '>', '>',
	/* ! */  '>', '>', '>', '>', '>', '>', ' ', '>', '>',
	/* ( */  '<', '<', '<', '<', '<', '<', '<', '=', ' ',
	/* ) */  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	/* \0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '='
};
//求值算法
float evalute(char* S, char*& RPN) {
	Stack<float> opnd; Stack<char> optr;
	optr.push('\0');
	while (!optr.empty()) {
		if (isdigit(*S)) {
			readNumber(S, opnd); append(RPN, opnd.top());
		}else
			switch (orderBetween(optr.top(), *S)) {
			case '<':
				optr.push(*S);S++;
				break;
			case '=':
				optr.pop();S++;
				break;
			case '>': {
				char op = optr.pop(); append(RPN, op);
				if ('!' == op) {
					float pOpnd = opnd.pop();
					opnd.push(calcu(op, pOpnd));
				}
				else {
					float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop;
					opnd.push(calcu(pOpnd1, op, pOpnd2));
				}
				break;
			}
			default: exit(-1);
			}
	}
	return opnd.pop;
}
