#define DEFAULT_SIZE 1000											// 缺省元素个数

// 顺序栈类模板
template<class ElemType>
class SqStack 
{
protected:
// 数据成员:
	ElemType *elems;												// 元素存储空间
	int maxSize;													// 栈最大元素个数
	int count;														// 元素个数

public:
// 抽象数据类型方法声明及重载编译系统默认方法声明:
	SqStack(int size = DEFAULT_SIZE);								// 构造函数模板
	virtual ~SqStack();												// 析构函数模板
	int Length() const;												// 求栈长度			 
	bool Empty() const;												// 判断栈是否为空
	void Clear();													// 将栈清空
	bool Push(const ElemType &e);									// 入栈
	bool Top(ElemType &e) const;									// 返回栈顶元素
	bool Pop(ElemType &e);											// 出栈
	bool Pop();														// 出栈
	SqStack(const SqStack<ElemType> &source);						// 复制构造函数模板
	SqStack<ElemType> &operator =(const SqStack<ElemType> &source);	// 重载赋值运算符
};


// 顺序栈类模板的实现部分

template<class ElemType>
SqStack<ElemType>::SqStack(int size)
// 操作结果：构造一个最大元素个数为size的空栈
{
	maxSize = size;													// 最大元素个数
	elems = new ElemType[maxSize];									// 分配存储空间
	count = 0;														// 空栈元素个数为0
}

template<class ElemType>
SqStack<ElemType>::~SqStack()
// 操作结果：销毁栈
{
	delete []elems;													// 释放存储空间
}

template <class ElemType>
int SqStack<ElemType>::Length() const
// 操作结果：返回栈元素个数
{
	return count;													// count表示栈元素个数
}

template<class ElemType>
bool SqStack<ElemType>::Empty() const
// 操作结果：如栈为空，则返回true，否则返回false
{
	return count == 0;												// count == 0表示栈为空
}

template<class ElemType>
void SqStack<ElemType>::Clear()
// 操作结果：清空栈
{
	count = 0;														// 清空栈后元素个数为0
}

template<class ElemType>
bool SqStack<ElemType>::Push(const ElemType &e)
// 操作结果：将元素e追加到栈顶,如成功则返加true,如栈已满将返回false
{
	if (count == maxSize) 
	{	// 栈已满
		return false;												// 入栈失败
	}
	else
	{	// 操作成功
		elems[count] = e;											// 将元素e追加到栈顶 
		count++;													// 入栈成功后元素个数自加1 
		return true;												// 入栈成功
	}
}

template<class ElemType>
bool SqStack<ElemType>::Top(ElemType &e) const
// 操作结果：如栈非空,用e返回栈顶元素,返回true,否则返回false
{
	if(Empty())
	{	// 栈空
		return false;												// 失败
	}
	else
	{	// 栈非空,操作成功
		e = elems[count - 1];										// 用e返回栈顶元素
		return true;												// 成功
	}
}

template<class ElemType>
bool SqStack<ElemType>::Pop(ElemType &e)
// 操作结果：如栈非空,删除栈顶元素,并用e返回栈顶元素,返回true,否则返回false
{
	if (Empty())
	{	// 栈空
		return false;												// 失败
	}
	else
	{	// 操作成功
		e = elems[count - 1];										// 用e返回栈顶元素
		count--;													// 出栈成功后元素个数自减1
		return true;												// 成功
	}
}

template<class ElemType>
bool SqStack<ElemType>::Pop()
// 操作结果：如栈非空,删除栈顶元素,返回true,否则
//	返回false
{
	if (Empty())
	{	// 栈空
		return false;												// 失败
	}
	else
	{	// 操作成功
		count--;													// 出栈成功后元素个数自减1
		return true;												// 成功
	}
}

template<class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType> &source) 
// 操作结果：由栈source构造新栈——复制构造函数模板
{
	maxSize = source.maxSize;										// 最大元素个数
	elems = new ElemType[maxSize];									// 分配存储空间
	count = source.count;											// 栈元素个数
	for (int temPos = 1; temPos <= Length(); temPos++)
	{	// 从栈底到栈顶对栈source的每个元素进行复制
		elems[temPos - 1] = source.elems[temPos - 1];
	}
}

template<class ElemType>
SqStack<ElemType> &SqStack<ElemType>::operator = (const SqStack<ElemType> &source)
// 操作结果：将栈source赋值给当前栈——重载赋值运算符
{
	if (&source != this)
	{
		maxSize = source.maxSize;									// 最大元素个数
		delete []elems;	// 释放存储空间
		elems = new ElemType[maxSize];								// 分配存储空间
		count = source.count;										// 复制栈元素个数
		for (int temPos = 1; temPos <= Length(); temPos++)
		{	// 从栈底到栈顶对栈source的每个元素进行复制
			elems[temPos - 1] = source.elems[temPos - 1];
		}
	}
	return *this;
}