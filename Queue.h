#ifndef QUEUE_H
#define QUEUE_H

// ����
template <class T>
class Queue {
public:
	Queue(int size);
	~Queue();
	// ��ն���
	void ClearQueue();
	// �Ƿ�Ϊ��
	bool QueueEmpty() const;
	// �Ƿ�Ϊ��
	bool QueueFull() const;
	// ����
	int QueueLength() const;
	// ���
	bool EnQueue(T *e);
	//����
	bool DeQueue(T *e);
	// ����
	void QueueTraverse();

private:
	T *m_pQueue;
	int m_iSize;
	int m_iLength;
	int m_iHead;
	int m_iTail;
};

#endif
