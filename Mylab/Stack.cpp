#include "../Mylab/Vector.cpp"
template <typename T> class Stack : public Vector<T> {
public:
	void push(T const& e) { increase(size(), e); }
	T pop() { return remove(size() - 1); }
	T& top() { return (*this)[size() - 1]; }
};
//����ת���㷨
void convert(Stack<char>& S, __int64 n, int base) {
	static char digit[]
		= { '0', '1', '2', '3','4', '5', '6', '7', '8', '9', 'A','B','C', 'D', 'E', 'F' };
	if (0 < n) {
		S.push(digit[n % base]);
		convert(S, n / base, base);
	}
}
//����ת���㷨(�����棩
void convert(Stack<char>& S, __int64 n, int base) {
	static char digit[]
		= { '0', '1', '2', '3','4', '5', '6', '7', '8', '9', 'A','B','C', 'D', 'E', 'F' };
	while (0 < n) {
		int remainder = (int)(n % base);S.push(digit[remainder]);
		n /= base;
	}
}
//���ȼ����Ķ���
#define N_OPTR 9 // ���������Ŀ

// �����ö�����Ͷ��壺�ӡ������ˡ������˷����׳ˡ������š������š���ʼ��������ֹ��
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator;
// �ӡ������ˡ������˷��������š������š���ʼ��������ֹ��

// ��������ȵȼ���ջ��������뵱ǰ�����֮������ȹ�ϵ
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
//��ֵ�㷨
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
