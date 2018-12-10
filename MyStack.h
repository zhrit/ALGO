#ifndef MYSTACK_H
#define MYSTACK_H

// 栈
template <class T>
class MyStack {
public:
	MyStack(int size);
	~MyStack();
	// 是否为空
	bool stackEmpty();
	// 是否满
	bool stackFull();
	// 清空栈
	void clearStack();
	// 获取元素个数
	int stackLength();
	// 入栈
	bool push(T *e);
	// 出栈
	bool pop(T *e);
	// 返回栈顶元素
	T top();
	// 遍历
	void stackTraversel();
private:
	T *m_pBuffer;
	int m_iSize;
	int m_iTop;
};

#endif