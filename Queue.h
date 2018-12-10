#ifndef QUEUE_H
#define QUEUE_H

// 队列
template <class T>
class Queue {
public:
	Queue(int size);
	~Queue();
	// 清空队列
	void ClearQueue();
	// 是否为空
	bool QueueEmpty() const;
	// 是否为满
	bool QueueFull() const;
	// 长度
	int QueueLength() const;
	// 入队
	bool EnQueue(T *e);
	//出对
	bool DeQueue(T *e);
	// 遍历
	void QueueTraverse();

private:
	T *m_pQueue;
	int m_iSize;
	int m_iLength;
	int m_iHead;
	int m_iTail;
};

#endif
