#pragma once

#include <map>
#include <queue>

using namespace std;

// 冒泡排序，O(n2),O(1), 稳定
template <class T>
void BubbleSort(T *elem, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (*(elem + j) > *(elem + j + 1)) {
				swap(*(elem + j), *(elem + j + 1));
			}
		}
	}
}


// 选择排序，O(n2),O(1),不稳定，各种情况的时间性能一样
template <class T>
void SelectionSort(T *elem, int n) {
	for (int i = 0; i < n - 1; i++) {
		int index = i;
		for (int j = i + 1; j < n; j++) {
			if (*(elem + index) > *(elem + j)) {
				index = j;
			}
		}
		swap(*(elem + i), *(elem + index));
	}
}


// 插入排序，O(n2),O(1),稳定
template <class T>
void InsertionSort(T *elem, int n) {
	for (int i = 1; i < n; i++) {
		T currentELem = *(elem + i);
		int preIndex = i - 1;
		while (preIndex >= 0 && *(elem + preIndex) > currentELem) {
			*(elem + preIndex + 1) = *(elem + preIndex);
			preIndex--;
		}
		*(elem + preIndex + 1) = currentELem;
	}
}


// 希尔排序，O(n1.3),O(1),不稳定,分成多个子序列的插入排序
template <class T>
void ShellSort(T *elem, int n) {
	int gap = 1;
	while (gap < n / 3) {
		gap = gap * 3 + 1;
	}
	while (gap > 0) {
		for (int i = gap; i < n; i++) {
			int j;
			T currentElem = *(elem + i);
			for (j = i - gap; j >= 0 && *(elem + j) > currentElem; j -= gap) {
				*(elem + j + gap) = *(elem + j);
			}
			*(elem + j + gap) = currentElem;
		}
		gap = gap / 3;
	}
}


// 归并排序，O(nlog2n),O(n),稳定，各种情况的时间性能一样
//合并子程序
template <class T>
static void merge(T *elem, int n) {
	T *mem = new T[n];

	int i = 0;
	int j = n / 2;
	int t = 0;
	while (i < n / 2 && j < n) {
		if (*(elem + i) <= *(elem + j)) {
			*(mem + t) = *(elem + i);
			i++;
			t++;
		}
		else {
			*(mem + t) = *(elem + j);
			j++;
			t++;
		}
	}
	while (i < n / 2) {
		*(mem + t) = *(elem + i);
		t++;
		i++;
	}
	while (j < n) {
		*(mem + t) = *(elem + j);
		t++;
		j++;
	}
	for (int i = 0; i < n; i++) {
		*(elem + i) = *(mem + i);
	}

	delete[]mem;
	mem = nullptr;
}
template <class T>
void MergeSort(T *elem, int n) {
	if (n < 2) {
		return;
	}
	int mid = n / 2;
	MergeSort(elem, mid);
	MergeSort(elem + mid, n - mid);
	merge(elem, n);
}


// 快速排序，O(nlog2n),O(nlog2n),不稳定，表现较好的排序算法
//分区子函数
template <class T>
static int partition(T *elem, int start, int end) {
	int povit = start;
	int index = start + 1;
	for (int i = index; i <= end; i++) {
		if (*(elem + i) < *(elem + povit)) {
			swap(*(elem + i), *(elem + index));
			index++;
		}
	}
	swap(*(elem + povit), *(elem + index - 1));
	return index - 1;
}
template <class T>
void QuickSort(T *elem, int n) {
	int part;
	if (n > 0) {
		part = partition(elem, 0, n - 1);
		QuickSort(elem, part);
		QuickSort(elem + part + 1, n - part - 1);
	}
}


// 堆排序，O(nlog2n),O(1),不稳定，最大堆，优先队列
//下沉操作子函数
template <class T>
void heapify(T *elem, int n, int index) {
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int maxIndex = index;
	if (left < n && *(elem + left) > *(elem + maxIndex)) {
		maxIndex = left;
	}
	if (right < n && *(elem + right) > *(elem + maxIndex)) {
		maxIndex = right;
	}
	if (maxIndex != index) {
		swap(*(elem + index), *(elem + maxIndex));
		heapify(elem, n, maxIndex);
	}
}
//建立最大堆子函数
template <class T>
void buildMaxHeap(T *elem, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(elem, n, i);
	}
}
template <class T>
void HeapSort(T *elem, int n) {
	buildMaxHeap(elem, n);

	for (int i = n - 1; i > 0; i--) {
		swap(*elem, *(elem + i));
		heapify(elem, i, 0);
	}
}


// 计数排序，O(n+k),O(n+k),稳定
//其排序速度快于任何比较排序算法。当k不是很大并且序列比较集中时，计数排序是一个很有效的排序算法。
void CountingSort(int *elem, int n) {
	int *a = new int[n];
	memset(a, 0, n * sizeof(int));

	int max = 0;
	for (int i = 0; i < n; i++) {
		max = *(elem + i) > max ? *(elem + i) : max;
	}

	int *b = new int[max + 1];
	memset(b, 0, (max + 1) * sizeof(int));

	for (int i = 0; i < n; i++) {
		b[*(elem + i)]++;
	}

	for (int i = 0, j = 0; i <= max; i++) {
		while (b[i] > 0) {
			elem[j++] = i;
			b[i]--;
		}
	}

	delete[] a;
	delete[] b;
	a = nullptr;
	b = nullptr;
}


// 桶排序，O(n+k),O(n+k),稳定
// 基数排序，O(n*k),O(n+k),稳定
void RadixSort(int *elem, int n) {
	//最大数
	int max = 0;
	for (int i = 0; i < n; i++) {
		max = elem[i] > max ? elem[i] : max;
	}

	//最大数的位数
	int digit = 1;
	while (max / 10 > 0) {
		max = max / 10;
		digit++;
	}
	
	//分类桶
	map<int, queue<int>> counter;
	for (int i = 0; i < 10; i++) {
		queue<int> c;
		counter.insert(map<int, queue<int>>::value_type(i, c));
	}

	//从低位到高位分别进行桶排序
	int dev = 10;
	for (int i = 0; i < digit; i++, dev *= 10) {
		for (int j = 0; j < n; j++) {
			int n = (elem[j] - int(elem[j] / dev) * dev) / int(pow(10, i));//获取几个整数某一位的数
			counter[n].push(elem[j]);
		}
		int t = 0;
		for (int j = 0; j < 10; j++) {
			while (!counter[j].empty()) {
				elem[t] = counter[j].front();
				counter[j].pop();
				t++;
			}
		}
	}
}


template <class T>
void swap(T &x, T &y) {
	T temp;
	temp = x;
	x = y;
	y = temp;
}