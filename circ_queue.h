#define DEFAULT_SIZE 1000											// ȱʡԪ�ظ���

// ѭ��������ģ��
template<class ElemType>
class CircQueue 
{
protected:
// ���ݳ�Ա:
	ElemType *elems;												// Ԫ�ش洢�ռ�
	int maxSize;													// �������Ԫ�ظ���
	int front, rear;												// ��ͷ��β
	int count;														// Ԫ�ظ���

public:
// �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	CircQueue(int size = DEFAULT_SIZE);								// ���캯��ģ��
	virtual ~CircQueue();											// ��������ģ��
	int Length() const;												// ����г���			 
	bool Empty() const;												// �ж϶����Ƿ�Ϊ��
	void Clear();													// ���������
	bool OutQueue(ElemType &e);										// ���Ӳ���
	bool OutQueue();												// ���Ӳ���
	bool GetHead(ElemType &e) const;								// ȡ��ͷ����
	bool InQueue(const ElemType &e);								// ��Ӳ���
	CircQueue(const CircQueue<ElemType> &source);						// ���ƹ��캯��ģ��
	CircQueue<ElemType> &operator =(const CircQueue<ElemType> &source);	// ���ظ�ֵ�����
};

// ѭ��������ģ���ʵ�ֲ���

template<class ElemType>
CircQueue<ElemType>::CircQueue(int size)
// �������������һ�����Ԫ�ظ���Ϊsize�Ŀ�ѭ������
{
	maxSize = size;													// ���Ԫ�ظ���
	elems = new ElemType[maxSize];									// ����洢�ռ�
	rear = front = 0;												// ��ʼ����ͷ���β
	count = 0;														// ��ʼ��Ԫ�ظ���
}

template <class ElemType>
CircQueue<ElemType>::~CircQueue()
// ������������ٶ���
{
	delete []elems;													// �ͷŴ洢�ռ�
}

template<class ElemType>
int CircQueue<ElemType>::Length() const
// ������������ض��г���			 
{
	return count;													// ����Ԫ�ظ���
}

template<class ElemType>
bool CircQueue<ElemType>::Empty() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
	return count == 0;												// count == 0��ʾ����Ϊ��
}

template<class ElemType>
void CircQueue<ElemType>::Clear() 
// �����������ն���
{
	rear = front = 0;												// �ն���rear��front���
	count = 0;														// �ն���Ԫ�ظ���Ϊ0
}


template<class ElemType>
bool CircQueue<ElemType>::OutQueue(ElemType &e)
// ���������������зǿգ���ôɾ����ͷԪ�أ�����e������ֵ������true,
//	���򷵻�false
{
	if (!Empty()) 
	{	// ���зǿ�
		e = elems[front];											// ��e���ض�ͷԪ��
		front = (front + 1) % maxSize;								// frontָ����һԪ��
		count--;													// ���ӳɹ���Ԫ�ظ����Լ�1
		return true;												// �ɹ�
	}
	else
	{	// ����Ϊ��
		return false;												// ʧ��
	}
}

template<class ElemType>
bool CircQueue<ElemType>::OutQueue()
// ���������������зǿգ���ôɾ����ͷԪ�أ�����true,
//	���򷵻�false
{
	if (!Empty()) 
	{	// ���зǿ�
		front = (front + 1) % maxSize;								// frontָ����һԪ��
		count--;													// ���ӳɹ���Ԫ�ظ����Լ�1
		return true;												// �ɹ�
	}
	else
	{	// ����Ϊ��
		return false;												// ʧ��
	}
}

template<class ElemType>
bool CircQueue<ElemType>::GetHead(ElemType &e) const
// ���������������зǿգ���ô��e���ض�ͷԪ�أ�����true,
//	���򷵻�false
{
	if (!Empty()) 
	{	// ���зǿ�
		e = elems[front];											// ��e���ض�ͷԪ��
		return true;												// �ɹ�
	}
	else
	{	// ����Ϊ��
		return false;												// ʧ��
	}
}

template<class ElemType>
bool CircQueue<ElemType>::InQueue(const ElemType &e)
// ��������������������������false,
//	�������Ԫ��eΪ�µĶ�β������true
{
	if (count == maxSize)
	{	// ��������
		return false;												// ʧ��
	}
	else
	{	// ����δ������ӳɹ�
		elems[rear] = e;											// ����eΪ�¶�β
		rear = (rear + 1) % maxSize;								// rearָ���¶�β
		count++;													// ��ӳɹ���Ԫ�ظ�����1 
		return true;												// �ɹ�
	}
}

template<class ElemType>
CircQueue<ElemType>::CircQueue(const CircQueue<ElemType> &source)
// ����������ɶ���source�����¶��С������ƹ��캯��ģ��
{
	maxSize = source.maxSize;										// ���Ԫ�ظ���
	elems = new ElemType[maxSize];									// ����洢�ռ�
	front = source.front;											// ���ƶ�ͷλ��	
	rear = source.rear;												// ���ƶ�βλ��
	count = source.count;											// ����Ԫ�ظ���
	for (int temPos = front; temPos != rear; temPos = (temPos + 1) % maxSize)
	{	// ����ѭ�����е�Ԫ��
		elems[temPos] = source.elems[temPos];
	}
}

template<class ElemType>
CircQueue<ElemType> &CircQueue<ElemType>::operator =(const CircQueue<ElemType> &source)
// ���������������source��ֵ����ǰ���С������ظ�ֵ�����
{
	if (&source != this)
	{
		maxSize = source.maxSize;									// ���Ԫ�ظ���
		delete []elems;												// �ͷŴ洢�ռ�
		elems = new ElemType[maxSize];								// ����洢�ռ�
		front = source.front;										// ���ƶ�ͷλ��	
		rear = source.rear;											// ���ƶ�βλ��
		count = source.count;										// ����Ԫ�ظ���
		for (int temPos = front; temPos != rear; temPos = (temPos + 1) % maxSize)
		{	// ����ѭ�����е�Ԫ��
			elems[temPos] = source.elems[temPos];
		}
	}
	return *this;
}

