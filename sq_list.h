
#define DEFAULT_SIZE 1000		// 缺省元素个数

// 顺序表类模板
template <class ElemType>
class SqList
{
protected:
	// 数据成员:
	ElemType* elems;					// 元素存储空间
	int maxSize;						// 顺序表最大元素个数
	int count;							// 元素个数

public:
	// 抽象数据类型方法声明及重载编译系统默认方法声明:
	SqList(int size = DEFAULT_SIZE);							// 构造函数模板
	virtual ~SqList();					// 析构函数模板
	int Length() const;					// 求线性表长度			 
	bool Empty() const;					// 判断线性表是否为空
	void Clear();						// 将线性表清空
	bool GetElem(int position, ElemType& e) const;				// 求指定位置的元素	
	bool SetElem(int position, const ElemType& e);				// 设置指定位置的元素值
	bool Delete(int position, ElemType& e);						// 删除元素		
	bool Delete(int position);			// 删除元素		
	bool Insert(int position, const ElemType& e);				// 插入元素
	SqList(const SqList<ElemType>& source);						// 复制构造函数模板
	SqList<ElemType>& operator =(const SqList<ElemType>& source); // 重载赋值运算符
};


// 顺序表类模板的实现部分

template <class ElemType>
SqList<ElemType>::SqList(int size)
// 操作结果：构造一个最大元素个数为size的空顺序表
{
	maxSize = size;						// 最大元素个数
	elems = new ElemType[maxSize];		// 分配存储空间
	count = 0;							// 空线性表元素个数为0
}

template <class ElemType>
SqList<ElemType>::~SqList()
// 操作结果：销毁线性表
{
	delete[]elems;						// 释放存储空间
}

template <class ElemType>
int SqList<ElemType>::Length() const
// 操作结果：返回线性表元素个数
{
	return count;						// 返回元素个数
}

template <class ElemType>
bool SqList<ElemType>::Empty() const
// 操作结果：如线性表为空，则返回true，否则返回false
{
	return count == 0;					// count == 0表示线性表为空
}

template <class ElemType>
void SqList<ElemType>::Clear()
// 操作结果：清空线性表
{
	count = 0;							// 空线性表元素个数为0
}


template <class ElemType>
bool SqList<ElemType>::GetElem(int position, ElemType& e) const
// 操作结果：当线性表存在第position个元素时，用e返回其值，返回true, 否则返回false
{
	if (position < 1 || position > Length())
	{	// position范围错
		return false;					// 元素不存在
	}
	else
	{	// position合法
		e = elems[position - 1];
		return true;					// 元素存在
	}
}

template <class ElemType>
bool SqList<ElemType>::SetElem(int position, const ElemType& e)
// 操作结果：将线性表的第position个元素赋值为e,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回true,否则返回false
{
	if (position < 1 || position > Length())
	{	// position范围错
		return false;					// 范围错
	}
	else
	{	// position合法
		elems[position - 1] = e;
		return true;					// 成功
	}
}

template <class ElemType>
bool SqList<ElemType>::Delete(int position, ElemType& e)
// 操作结果：删除线性表的第position个元素, 并前用e返回其值,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回true,否则返回false
{
	if (position < 1 || position > Length())
	{	// position范围错
		return false;					// 范围错
	}
	else
	{	// position合法
		e = elems[position - 1];		// 用e返回被删除元素的值
		for (int temPos = position + 1; temPos <= Length(); temPos++)
		{	// 被删除元素之后的元素依次左移
			elems[temPos - 2] = elems[temPos - 1];
		}
		count--;						// 删除后元素个数将自减1
		return true;					// 删除成功
	}
}

template <class ElemType>
bool SqList<ElemType>::Delete(int position)
// 操作结果：删除线性表的第position个元素,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回true,否则返回false
{
	if (position < 1 || position > Length())
	{	// position范围错
		return false;					// 范围错
	}
	else
	{	// position合法
		for (int temPos = position + 1; temPos <= Length(); temPos++)
		{	// 被删除元素之后的元素依次左移
			elems[temPos - 2] = elems[temPos - 1];
		}
		count--;						// 删除后元素个数将自减1
		return true;					// 删除成功
	}
}

template <class ElemType>
bool SqList<ElemType>::Insert(int position, const ElemType& e)
// 操作结果：在线性表的第position个元素前插入元素e,
//	position的的取值范围为1≤position≤Length()+1
//	如线性表已满,则返回false,
//	如position合法, 则返回true, 否则返回false
{
	if (count == maxSize)
	{	// 线性表已满返回false
		return false;
	}
	else if (position < 1 || position > Length() + 1)
	{	// position范围错
		return false;					// 范围错
	}
	else
	{	// 成功
		for (int temPos = Length(); temPos >= position; temPos--)
		{	// 插入位置之后的元素右移
			elems[temPos] = elems[temPos - 1];
		}
		count++;						// 插入后元素个数将自增1
		elems[position - 1] = e;		// 将e赋值到position位置处	
		return true;					// 插入成功
	}
}

template <class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType>& source)
// 操作结果：由线性表source构造新线性表——复制构造函数模板
{
	maxSize = source.maxSize;			// 最大元素个数
	count = source.count;				// 线性表元素个数
	elems = new ElemType[maxSize];		// 分配存储空间
	for (int temPos = 1; temPos <= source.Length(); temPos++)
	{	// 复制数据元素
		elems[temPos - 1] = source.elems[temPos - 1];	// 复制元素值
	}
}

template <class ElemType>
SqList<ElemType>& SqList<ElemType>::operator =(const SqList<ElemType>& source)
// 操作结果：将线性表source赋值给当前线性表——重载赋值运算符
{
	if (&source != this)
	{
		maxSize = source.maxSize;		// 最大元素个数
		count = source.count;			// 线性表元素个数
		delete[]elems;					// 释放存储空间
		elems = new ElemType[maxSize];	// 分配存储空间
		for (int temPos = 1; temPos <= source.Length(); temPos++)
		{	// 复制数据元素
			elems[temPos - 1] = source.elems[temPos - 1];	// 复制元素值
		}
	}
	return *this;
}
