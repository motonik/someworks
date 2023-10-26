// 简单线性链表类模板
template <class ElemType>
class LinkList 
{
protected:
// 数据成员:
	Node<ElemType> *head;						// 头结点指针

// 辅助函数模板:
	Node<ElemType> *GetElemPtr(int position) const;			// 返回指向第position个结点的指针

public:
// 抽象数据类型方法声明及重载编译系统默认方法声明:
	LinkList();							// 无参数的构造函数模板
	virtual ~LinkList();					// 析构函数模板
	int Length() const;							// 求线性表长度			 
	bool Empty() const;							// 判断线性表是否为空
	void Clear();								// 将线性表清空
	bool GetElem(int position, ElemType &e) const;			// 求指定位置的元素	
	bool SetElem(int position, const ElemType &e);			// 设置指定位置的元素值
	bool Delete(int position, ElemType &e);					// 删除元素		
	bool Delete(int position);								// 删除元素		
	bool Insert(int position, const ElemType &e);			// 插入元素
	LinkList(const LinkList<ElemType> &source);	// 复制构造函数模板
	LinkList<ElemType> &operator =(const LinkList<ElemType> &source); // 重载赋值运算符
};


// 简单线性链表类模板的实现部分
template<class ElemType>
Node<ElemType> *LinkList<ElemType>::GetElemPtr(int position) const
// 操作结果：返回指向第position个结点的指针
{
	Node<ElemType> *temPtr = head;				// 用temPtr遍历线性表以查找第position个结点
	int temPos = 0;								// temPtr所指结点的位置 

	while (temPtr != NULL && temPos < position)
	{	// 顺指针向后查找，直到temPtr指向第position个结点
		temPtr = temPtr->next;
		temPos++;
	}

	if (temPtr != NULL && temPos == position)
	{	// 查找成功
		return temPtr;	
	}
	else
	{	// 查找失败
		return NULL;	
	}
}

template <class ElemType>
LinkList<ElemType>::LinkList()
// 操作结果：构造一个空链表
{
	head = new Node<ElemType>;					// 构造头结点，空链表只有头结点
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
// 操作结果：销毁线性表
{
	Clear();									// 清空线性表
	delete head;								// 释放头结点所点空间
}

template <class ElemType>
int LinkList<ElemType>::Length() const
// 操作结果：返回线性表元素个数
{
	int count = 0;								// 计数器 
	for (Node<ElemType> *temPtr = head->next; temPtr != NULL; temPtr = temPtr->next)
	{	// 用temPtr依次指向每个元素
		count++;								// 对线性表的每个元素进行计数
	}
	return count;								// 返回元素个数
}

template <class ElemType>
bool LinkList<ElemType>::Empty() const
// 操作结果：如线性表为空，则返回true，否则返回false
{
	return head->next == NULL;
}

template <class ElemType>
void LinkList<ElemType>::Clear()
// 操作结果：清空线性表
{
	while (!Empty())
	{	// 表性表非空，则删除第1个元素
		Delete(1);								// 删除第1个元素
	}
}

template <class ElemType>
bool LinkList<ElemType>::GetElem(int position, ElemType &e) const
// 操作结果：当线性表存在第position个元素时，用e返回其值，返回true,
//	否则返回false
{
	if (position < 1 || position > Length())
	{	// position范围错
		return false;							// 元素不存在
	}
	else
	{	// position合法
		Node<ElemType> *temPtr = GetElemPtr(position);			// 取出指向第position个结点的指针	
		e = temPtr->data;						// 用e返回第position个元素的值
		return true;							// 元素存在
	}
}

template <class ElemType>
bool LinkList<ElemType>::SetElem(int position, const ElemType &e)
// 操作结果：将线性表的第position个元素赋值为e,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回true,否则返回false
{
	if (position < 1 || position > Length())
	{	// position范围错
		return false;							// 范围错
	}
	else
	{	// position合法
		Node<ElemType> *temPtr = GetElemPtr(position);			// 取出指向第position个结点的指针
		temPtr->data = e;						// 设置第position个元素的值
		return true;							// 设置元素成功
	}
}

template <class ElemType>
bool LinkList<ElemType>::Delete(int position, ElemType &e)
// 操作结果：删除线性表的第position个元素, 并用e返回其值,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回true,否则返回false
{
	if (position < 1 || position > Length())
	{	// position范围错
		return false;							// 范围错
	}
	else
	{	// position合法
		Node<ElemType> *temPtr = GetElemPtr(position - 1);		// 取出指向第position-1个结点的指针
		Node<ElemType> *nextPtr = temPtr->next;// nextPtr为temPtr的后继
		temPtr->next = nextPtr->next;			// 删除结点
		e = nextPtr->data;						// 用e返回被删结点元素值	
		delete nextPtr;							// 释放被删结点
		return true;							// 删除成功
	}
}

template <class ElemType>
bool LinkList<ElemType>::Delete(int position)
// 操作结果：删除线性表的第position个元素,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回true,否则返回false
{
	if (position < 1 || position > Length())
	{	// position范围错
		return false;							// 范围错
	}
	else
	{	// position合法
		Node<ElemType> *temPtr = GetElemPtr(position - 1);		// 取出指向第position-1个结点的指针
		Node<ElemType> *nextPtr = temPtr->next;// nextPtr为temPtr的后继
		temPtr->next = nextPtr->next;			// 删除结点
		delete nextPtr;							// 释放被删结点
		return true;							// 删除成功
	}
}

template <class ElemType>
bool LinkList<ElemType>::Insert(int position, const ElemType &e)
// 操作结果：在线性表的第position个元素前插入元素e
//	position的取值范围为1≤position≤Length()+1
//	position合法时返回true, 否则返回false
{
	if (position < 1 || position > Length() + 1)
	{	// position范围错
		return false;							// 位置不合法
	}
	else
	{	// position合法
		Node<ElemType> *temPtr = GetElemPtr(position - 1);				// 取出指向第position-1个结点的指针
		Node<ElemType> *newPtr = new Node<ElemType>(e, temPtr->next);	// 生成新结点
		temPtr->next = newPtr;					// 将temPtr插入到链表中
		return true;							// 插入成功
	}
}

template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &source)
// 操作结果：由线性表source构造新线性表——复制构造函数模板
{
	int sourceLength = source.Length();			// source的长度
	ElemType tempElem;							// 临时元素
	head = new Node<ElemType>;					// 初始化空线性表，空链表只有头结点

	for (int temPos = 1; temPos <= sourceLength; temPos++)
	{	// 复制数据元素
		source.GetElem(temPos, tempElem);		// 取出第temPos个元素
		Insert(Length() + 1, tempElem);			// 将tempElem插入到当前线性表
	}
}

template <class ElemType>
LinkList<ElemType> &LinkList<ElemType>::operator =(const LinkList<ElemType> &source)
// 操作结果：将线性表source赋值给当前线性表——重载赋值运算符
{
	if (&source != this)
	{
		int sourceLength = source.Length();		// source的长度
		ElemType tempElem;						// 临时元素
		Clear();								// 清空当前线性表

		for (int temPos = 1; temPos <= sourceLength; temPos++)
		{	// 复制数据元素
			source.GetElem(temPos, tempElem);	// 取出第temPos个元素
			Insert(Length() + 1, tempElem);		// 将tempElem插入到当前线性表
		}
	}
	return *this;
}
