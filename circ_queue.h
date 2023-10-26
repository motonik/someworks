#define DEFAULT_SIZE 1000											// 缺省元素个数

// 循环队列类模板
template<class ElemType>
class CircQueue 
{
protected:
// 数据成员:
	ElemType *elems;												// 元素存储空间
	int maxSize;													// 队列最大元素个数
	int front, rear;												// 队头队尾
	int count;														// 元素个数

public:
// 抽象数据类型方法声明及重载编译系统默认方法声明:
	CircQueue(int size = DEFAULT_SIZE);								// 构造函数模板
	virtual ~CircQueue();											// 析构函数模板
	int Length() const;												// 求队列长度			 
	bool Empty() const;												// 判断队列是否为空
	void Clear();													// 将队列清空
	bool OutQueue(ElemType &e);										// 出队操作
	bool OutQueue();												// 出队操作
	bool GetHead(ElemType &e) const;								// 取队头操作
	bool InQueue(const ElemType &e);								// 入队操作
	CircQueue(const CircQueue<ElemType> &source);						// 复制构造函数模板
	CircQueue<ElemType> &operator =(const CircQueue<ElemType> &source);	// 重载赋值运算符
};

// 循环队列类模板的实现部分

template<class ElemType>
CircQueue<ElemType>::CircQueue(int size)
// 操作结果：构造一个最大元素个数为size的空循环队列
{
	maxSize = size;													// 最大元素个数
	elems = new ElemType[maxSize];									// 分配存储空间
	rear = front = 0;												// 初始化队头与队尾
	count = 0;														// 初始化元素个数
}

template <class ElemType>
CircQueue<ElemType>::~CircQueue()
// 操作结果：销毁队列
{
	delete []elems;													// 释放存储空间
}

template<class ElemType>
int CircQueue<ElemType>::Length() const
// 操作结果：返回队列长度			 
{
	return count;													// 返回元素个数
}

template<class ElemType>
bool CircQueue<ElemType>::Empty() const
// 操作结果：如队列为空，则返回true，否则返回false
{
	return count == 0;												// count == 0表示队列为空
}

template<class ElemType>
void CircQueue<ElemType>::Clear() 
// 操作结果：清空队列
{
	rear = front = 0;												// 空队列rear与front相等
	count = 0;														// 空队列元素个数为0
}


template<class ElemType>
bool CircQueue<ElemType>::OutQueue(ElemType &e)
// 操作结果：如果队列非空，那么删除队头元素，并用e返回其值，返回true,
//	否则返回false
{
	if (!Empty()) 
	{	// 队列非空
		e = elems[front];											// 用e返回队头元素
		front = (front + 1) % maxSize;								// front指向下一元素
		count--;													// 出队成功后元素个数自减1
		return true;												// 成功
	}
	else
	{	// 队列为空
		return false;												// 失败
	}
}

template<class ElemType>
bool CircQueue<ElemType>::OutQueue()
// 操作结果：如果队列非空，那么删除队头元素，返回true,
//	否则返回false
{
	if (!Empty()) 
	{	// 队列非空
		front = (front + 1) % maxSize;								// front指向下一元素
		count--;													// 出队成功后元素个数自减1
		return true;												// 成功
	}
	else
	{	// 队列为空
		return false;												// 失败
	}
}

template<class ElemType>
bool CircQueue<ElemType>::GetHead(ElemType &e) const
// 操作结果：如果队列非空，那么用e返回队头元素，返回true,
//	否则返回false
{
	if (!Empty()) 
	{	// 队列非空
		e = elems[front];											// 用e返回队头元素
		return true;												// 成功
	}
	else
	{	// 队列为空
		return false;												// 失败
	}
}

template<class ElemType>
bool CircQueue<ElemType>::InQueue(const ElemType &e)
// 操作结果：如果队列已满，返回false,
//	否则插入元素e为新的队尾，返回true
{
	if (count == maxSize)
	{	// 队列已满
		return false;												// 失败
	}
	else
	{	// 队列未满，入队成功
		elems[rear] = e;											// 插入e为新队尾
		rear = (rear + 1) % maxSize;								// rear指向新队尾
		count++;													// 入队成功后元素个数加1 
		return true;												// 成功
	}
}

template<class ElemType>
CircQueue<ElemType>::CircQueue(const CircQueue<ElemType> &source)
// 操作结果：由队列source构造新队列——复制构造函数模板
{
	maxSize = source.maxSize;										// 最大元素个数
	elems = new ElemType[maxSize];									// 分配存储空间
	front = source.front;											// 复制队头位置	
	rear = source.rear;												// 复制队尾位置
	count = source.count;											// 复制元素个数
	for (int temPos = front; temPos != rear; temPos = (temPos + 1) % maxSize)
	{	// 复制循环队列的元素
		elems[temPos] = source.elems[temPos];
	}
}

template<class ElemType>
CircQueue<ElemType> &CircQueue<ElemType>::operator =(const CircQueue<ElemType> &source)
// 操作结果：将队列source赋值给当前队列——重载赋值运算符
{
	if (&source != this)
	{
		maxSize = source.maxSize;									// 最大元素个数
		delete []elems;												// 释放存储空间
		elems = new ElemType[maxSize];								// 分配存储空间
		front = source.front;										// 复制队头位置	
		rear = source.rear;											// 复制队尾位置
		count = source.count;										// 复制元素个数
		for (int temPos = front; temPos != rear; temPos = (temPos + 1) % maxSize)
		{	// 复制循环队列的元素
			elems[temPos] = source.elems[temPos];
		}
	}
	return *this;
}

