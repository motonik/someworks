// 结点类模板
template <class ElemType>
struct Node 
{
	// 数据成员:
	ElemType data;				// 数据成分
	Node<ElemType>* next;		// 指针成分

	// 构造函数模板:
	Node() { next = NULL; };						// 无参数的构造函数模板
	Node(const ElemType& e, Node<ElemType>* link = NULL) { data = e;next = link; };	// 已知数据元素值和指针建立结点
};