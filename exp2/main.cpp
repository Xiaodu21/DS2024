#include <iostream>
#include <string>
#include <cctype>
#include "../Mylab/Stack.h"  // 确保这个路径和文件存在
using namespace std;

// 用来判断运算符的优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 执行简单的加减乘除运算
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// 计算器函数
int evaluate(string expression) {
    Stack<int> values;  // 存储数字
    Stack<char> ops;    // 存储操作符

    for (int i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;

        // 如果是数字，处理整个数值
        if (isdigit(expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--;  // 调整位置
        }
            // 左括号直接压入运算符栈
        else if (expression[i] == '(') {
            ops.push(expression[i]);
        }
            // 右括号处理括号内的表达式
        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.pop();  // 移除左括号
        }
            // 处理操作符
        else {
            // 这里需要检查优先级，确保先计算优先级高的运算符
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }

    // 处理栈中的剩余操作符
    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // 最终结果在 values 栈的顶部
    return values.top();
}
//计算柱状图矩形面积
int largestRectangleArea(Vector<int>& heights) {
    Stack<int> s;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int h = (i == n ? 0 : heights[i]);
        while (!s.empty() && h < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    return maxArea;
}


int main() {
    // 1.测试计算器功能
    string expression = "10 + 6 * (7 - 2)";
    cout << "Result: " << evaluate(expression) << endl;  // 应输出40


    //2.柱状图中最大的矩形面积
    Vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
    return 0;
}
// Created by lenovo on 2024/10/7.
//
