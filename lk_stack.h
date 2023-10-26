/////////////////////////////////////////////////////////
//// �����ģ��
//template <class ElemType>
//struct Node 
//{
//// ���ݳ�Ա:
//	ElemType data;				// ���ݳɷ�
//	Node<ElemType> *next;		// ָ��ɷ�
//
//// ���캯��ģ��:
//	Node();						// �޲����Ĺ��캯��ģ��
//	Node(const ElemType &e, Node<ElemType> *link = NULL);	// ��֪����Ԫ��ֵ��ָ�뽨�����
//};
//
//// �����ģ���ʵ�ֲ���
//template<class ElemType>
//Node<ElemType>::Node()
//// �������������ָ��ɷ�Ϊ�յĽ��
//{
//	next = NULL;
//}
//
//template<class ElemType>
//Node<ElemType>::Node(const ElemType &e, Node<ElemType> *link)
//// �������������һ�����ݳɷ�Ϊe��ָ��ɷ�Ϊlink�Ľ��
//{
//	data = e;
//	next = link;
//}
/////////////////////////////////////////////////////////

// ��ջ��ģ��
template<class ElemType>
class LinkStack 
{
protected:
// ���ݳ�Ա:
	Node<ElemType> *top;												// ջ��ָ��
	int count;															// Ԫ�ظ���

public:
// �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	LinkStack();														// �޲����Ĺ��캯��ģ��
	virtual ~LinkStack();												// ��������ģ��
	int Length() const;													// ��ջ����			 
	bool Empty() const;													// �ж�ջ�Ƿ�Ϊ��
	void Clear();														// ��ջ���
	bool Push(const ElemType &e);										// ��ջ
	bool Top(ElemType &e) const;										// ����ջ��Ԫ��
	bool Pop(ElemType &e);												// ��ջ
	bool Pop();															// ��ջ
	LinkStack(const LinkStack<ElemType> &source);						// ���ƹ��캯��ģ��
	LinkStack<ElemType> &operator =(const LinkStack<ElemType> &source);	// ���ظ�ֵ�����
};


// ��ջ��ģ���ʵ�ֲ���

template<class ElemType>
LinkStack<ElemType>::LinkStack()
// �������������һ����ջ��
{
	top = NULL;															// ����ջ��ָ��
	count = 0;															// ��ʼ��Ԫ�ظ���
}

template<class ElemType>
LinkStack<ElemType>::~LinkStack()
// �������������ջ
{
	Clear();															// ���ջ
}

template <class ElemType>
int LinkStack<ElemType>::Length() const
// �������������ջԪ�ظ���
{
	return count;														// count��ʾջԪ�ظ���
}

template<class ElemType>
bool LinkStack<ElemType>::Empty() const
// �����������ջΪ�գ��򷵻�true�����򷵻�false
{
	return count == 0;													// count == 0��ʾջΪ��
}

template<class ElemType>
void LinkStack<ElemType>::Clear()
// ������������ջ
{
	while (!Empty())
	{	// ��ջ�ǿգ����ջ
		Pop();															// ��ջ
	}
}

template<class ElemType>
bool LinkStack<ElemType>::Push(const ElemType &e)
// �����������Ԫ��e׷�ӵ�ջ��,��ɹ��򷵼�true,�����綯̬�ڴ��Ѻľ�
//	������false
{
	Node<ElemType> *newTop = new Node<ElemType>(e, top);
	if (newTop == NULL) 
	{	// ��̬�ڴ�ľ�
		return false;													// ʧ��
	}
	else
	{	// �����ɹ�
		top = newTop;
		count++;														// ��ջ�ɹ���Ԫ�ظ�����1 
		return true;													// �ɹ�
	}
}

template<class ElemType>
bool LinkStack<ElemType>::Top(ElemType &e) const
// �����������ջ�ǿ�,��e����ջ��Ԫ��,����true,���򷵻�false
{
	if(Empty())
	{	// ջ��
		return false;													// ʧ��
	}
	else
	{	// ջ�ǿ�,�����ɹ�
		e = top->data;													// ��e����ջ��Ԫ��
		return true;													// �ɹ�
	}
}

template<class ElemType>
bool LinkStack<ElemType>::Pop(ElemType &e)
// �����������ջ�ǿ�,ɾ��ջ��Ԫ��,����e����ջ��Ԫ��,����true,����
//	����false
{
	if (Empty())
	{	// ջ��
		return false;													// ʧ��
	}
	else
	{	// �����ɹ�
		Node<ElemType> *oldTop = top;									// ��ջ��
		e = oldTop->data;												// ��e����ջ��Ԫ��
		top = oldTop->next;												// topָ����ջ��
		delete oldTop;													// ɾ����ջ��
		count--;														// ��ջ�ɹ���Ԫ�ظ����Լ�1
		return true;													// ����
	}
}

template<class ElemType>
bool LinkStack<ElemType>::Pop()
// �����������ջ�ǿ�,ɾ��ջ��Ԫ��,����true,���򷵻�false
{
	if (Empty())
	{	// ջ��
		return false;													// ʧ��
	}
	else
	{	// �����ɹ�
		Node<ElemType> *oldTop = top;									// ��ջ��
		top = oldTop->next;												// topָ����ջ��
		delete oldTop;													// ɾ����ջ��
		count--;														// ��ջ�ɹ���Ԫ�ظ����Լ�1
		return true;													// ����
	}
}

template<class ElemType>
LinkStack<ElemType>::LinkStack(const LinkStack<ElemType> &source) 
// �����������ջsource������ջ�������ƹ��캯��ģ��
{
	if (source.Empty())
	{	// sourceΪ��
		top = NULL;														// ����ջ��ָ��
		count = 0;														// ��ʼ��Ԫ�ظ���
	}
	else 
	{	// source�ǿ�,����ջ
		top = new Node<ElemType>(source.top->data);						// ���ɵ�ǰջ��
		count = source.count;											// ջԪ�ظ���
		Node<ElemType> *buttomPtr = top;								// ��ǰջ��ָ��
		for (Node<ElemType> *temPtr = source.top->next; temPtr != NULL; temPtr = temPtr->next)
		{	// ��temPtr����ָ������Ԫ��
			buttomPtr->next = new Node<ElemType>(temPtr->data);			// ��ջ��׷��Ԫ��	
			buttomPtr = buttomPtr->next;								// buttomPtrָ����ջ��
		}
	}
}


template<class ElemType>
LinkStack<ElemType> &LinkStack<ElemType>::operator = (const LinkStack<ElemType> &source)
// �����������ջsource��ֵ����ǰջ�������ظ�ֵ�����
{
	if (&source != this)
	{
		if (source.Empty())
		{	// sourceΪ��
			top = NULL;													// ����ջ��ָ��
			count = 0;													// ��ʼ��Ԫ�ظ���
		}
		else 
		{	// source�ǿ�,����ջ
			Clear();													// ��յ�ǰջ
			top = new Node<ElemType>(source.top->data);					// ���ɵ�ǰջ��
			count = source.count;										// ջԪ�ظ���
			Node<ElemType> *buttomPtr = top;							// ��ǰջ��ָ��
			for (Node<ElemType> *temPtr = source.top->next; temPtr != NULL; temPtr = temPtr->next)
			{	// ��temPtr����ָ������Ԫ��
				buttomPtr->next = new Node<ElemType>(temPtr->data);		// ��ջ��׷��Ԫ��	
				buttomPtr = buttomPtr->next;							// buttomPtrָ����ջ��
			}
		}
	}
	return *this;
}