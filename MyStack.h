#ifndef MYSTACK_H
#define MYSTACK_H

// ջ
template <class T>
class MyStack {
public:
	MyStack(int size);
	~MyStack();
	// �Ƿ�Ϊ��
	bool stackEmpty();
	// �Ƿ���
	bool stackFull();
	// ���ջ
	void clearStack();
	// ��ȡԪ�ظ���
	int stackLength();
	// ��ջ
	bool push(T *e);
	// ��ջ
	bool pop(T *e);
	// ����ջ��Ԫ��
	T top();
	// ����
	void stackTraversel();
private:
	T *m_pBuffer;
	int m_iSize;
	int m_iTop;
};

#endif