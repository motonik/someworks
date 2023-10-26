/////////////////////////////////////////
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
////////////////////////////////////////////

// ��������ģ��
template<class ElemType>
class LinkQueue 
{
protected:
// ���ݳ�Ա:
	Node<ElemType> *front, *rear;										// ��ͷ��βָ��
	int count;															// Ԫ�ظ���

public:
// �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	LinkQueue();														// �޲����Ĺ��캯��ģ��
	virtual ~LinkQueue();												// ��������ģ��
	int Length() const;													// ����г���
	bool Empty() const;													// �ж϶����Ƿ�Ϊ��
	void Clear();														// ���������
	bool OutQueue(ElemType &e);											// ���Ӳ���
	bool OutQueue();													// ���Ӳ���
	bool GetHead(ElemType &e) const;									// ȡ��ͷ����
	bool InQueue(const ElemType &e);									// ��Ӳ���
	LinkQueue(const LinkQueue<ElemType> &source);						// ���ƹ��캯��ģ��
	LinkQueue<ElemType> &operator =(const LinkQueue<ElemType> &source);	// ���ظ�ֵ�����
};

// ��������ģ���ʵ�ֲ���

template<class ElemType>
LinkQueue<ElemType>::LinkQueue()
// �������������һ���ն���
{
	rear = front = new Node<ElemType>;									// ����ͷ���
	count = 0;															// ��ʼ��Ԫ�ظ���
}

template<class ElemType>
LinkQueue<ElemType>::~LinkQueue()
// ������������ٶ���
{
	Clear();															// ��ն���
	delete front;														// �ͷ�ͷ�����ռ�ռ�
}

template<class ElemType>
int LinkQueue<ElemType>::Length() const
// ������������ض��г���			 
{
	return count;														// count��ʾ����Ԫ�ظ���
}

template<class ElemType>
bool LinkQueue<ElemType>::Empty() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
	return count == 0;													// count == 0��ʾ����Ϊ��
}

template<class ElemType>
void LinkQueue<ElemType>::Clear() 
// �����������ն���
{
	while (!Empty())
	{	// ���зǿգ������
		OutQueue();														// ����
	}
}


template<class ElemType>
bool LinkQueue<ElemType>::OutQueue(ElemType &e)
// ���������������зǿգ���ôɾ����ͷԪ�أ�����e������ֵ������true,
//	���򷵻�false
{
	if (!Empty()) 
	{	// ���зǿ�
		Node<ElemType> *temPtr = front->next;							// ָ�����ͷ��
		e = temPtr->data;												// ��e���ض�ͷԪ��
		front->next = temPtr->next;									// front->nextָ����һԪ��
		if (rear == temPtr)
		{	// ��ʾ����ǰ������ֻ��һ��Ԫ�أ����Ӻ�Ϊ�ն���
			rear = front;
		}
		delete temPtr;													// �ͷų��ӵĽ��
		count--;														// ���ӳɹ���Ԫ�ظ����Լ�1
		return true;													// �ɹ�
	}
	else
	{	// ����Ϊ��
		return false;													// ʧ��
	}
}

template<class ElemType>
bool LinkQueue<ElemType>::OutQueue()
// ���������������зǿգ���ôɾ����ͷԪ�أ�����true,
//	���򷵻�false
{
	if (!Empty()) 
	{	// ���зǿ�
		Node<ElemType> *temPtr = front->next;							// ָ�����ͷ��
		front->next = temPtr->next;									// front->nextָ����һԪ��
		if (rear == temPtr)
		{	// ��ʾ����ǰ������ֻ��һ��Ԫ�أ����Ӻ�Ϊ�ն���
			rear = front;
		}
		delete temPtr;													// �ͷų��ӵĽ��
		count--;														// ���ӳɹ���Ԫ�ظ����Լ�1
		return true;													// �ɹ�
	}
	else
	{	// ����Ϊ��
		return false;													// ʧ��
	}
}

template<class ElemType>
bool LinkQueue<ElemType>::GetHead(ElemType &e) const
// ���������������зǿգ���ô��e���ض�ͷԪ�أ�����true,
//	���򷵻�false
{
	if (!Empty()) 
	{	// ���зǿ�
		Node<ElemType> *temPtr = front->next;							// ָ�����ͷ��
		e = temPtr->data;												// ��e���ض�ͷԪ��
		return true;													// �ɹ�
	}
	else
	{	// ����Ϊ��
		return false;													// ʧ��
	}
}

template<class ElemType>
bool LinkQueue<ElemType>::InQueue(const ElemType &e)
// �������������Ԫ��eΪ�µĶ�β������ɹ�true�����򷵻�false
{
	Node<ElemType> *temPtr = new Node<ElemType>(e);					// �����½��
	if (temPtr == NULL)
	{	// ��̬�ڴ�ľ�
		return false;													// ʧ��
	}
	else
	{	// �����ɹ�
		rear->next = temPtr;											// �½��׷���ڶ�β
		rear = temPtr;													// rearָ���¶�β
		count++;														// ��ӳɹ���Ԫ�ظ�����1 
		return true;													// �ɹ�
	}
}

template<class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType> &source)
// ����������ɶ���source�����¶��С������ƹ��캯��ģ��
{
	rear = front = new Node<ElemType>;	// ����ͷ���
	count = 0;															// ��ʼ��Ԫ�ظ���
	for (Node<ElemType> *temPtr = source.front->next; temPtr != NULL; temPtr = temPtr->next)
	{	// ��source���е�ÿ��Ԫ�ضԵ�ǰ����������в���
		InQueue(temPtr->data);
	}
}

template<class ElemType>
LinkQueue<ElemType> &LinkQueue<ElemType>::operator =(const LinkQueue<ElemType> &source)
// ���������������source��ֵ����ǰ���С������ظ�ֵ�����
{
	if (&source != this)
	{
		Clear();														// ��յ�ǰ���� 
		for (Node<ElemType> *temPtr = source.front->next; temPtr != NULL; temPtr = temPtr->next)
		{	// ��source���е�ÿ��Ԫ�ضԵ�ǰ����������в���
			InQueue(temPtr->data);
		}
	}
	return *this;
}
