typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode {
	T data; ListNodePosi(T) pred; ListNodePosi(T) succ;
	ListNode() {}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL )
		: data ( e ), pred ( p ), succ ( s ) {}
	ListNodePosi(T) insertAsPred(T const& e);
	ListNodePosi(T) insertAsSucc(T const& e);
};
#include "listNode.h"

template <typename T> class List {

private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;

protected;
	void init();
	int clear();
	void copyNodes(ListNodePosi(T), int);
	void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int);
	void mergeSort(ListNodePosi(T)&, int);
	void selectionSort(ListNodePosi(T), int);
	void insertionSort(ListNodePosi(T), int);

public:
	List() { init(); }
	List(List<T> const& L);
	List(List<T> const& L, Rank r, int n);
	List(ListNodePosi(T)p, int n);
	~List();
	Rank size() const { return _size; }
	bool empty() const { return _size <= 0; }
	T& operator[] (Rank r) const;
	ListNodePosi(T) first() const { return header->succ; }
	ListNodePosi(T) last() const { return trailer->pred; }
	bool vaild ( ListNodePosi(T) p )
	{
		return p && (trailer != p) && (header != p);
	}
	int disordered() cosnt;
	ListNodePosi(T) find ( T const& e ) const
	{
		return find(e, _size, trailer);
	}
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;
	ListNodePosi(T) search( T const& e ) cosnt
	{
		return search(e, _size, trailer);
	}
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) cosnt;
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); }
	ListNodePosi(T) insertAsFirst(T const& e);
	ListNodePosi(T) insertAsLast(T const& e);
	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e);
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e);
	T remove(ListNodePosi(T) p);
	void merge(List<T>& L) { merge(first(), size, L, L.first, L.size); }
	void sort() { sort(first, _size); }
	void sort(ListNodePosi(T) p, int n);
	void deduplicate();
	void reverse();
	void traverse(void (*) (T&));
	template <typename VST>
	void traverse(VST&);

};
template <typename T> void List<T>::init() {
	header = new ListNodePosi<T>;
	trailer = new ListNodePosi<T>;
	header->succ = trailer;header->pred = NULL;
	trailer->pred = header;traviler->succ = NULL;
	_size = 0;
}
template <typename T>
T& List<T>::operator[] (Rank r) const {
	ListNodePosi(T) p = first();
	while (0 < r--) p = p->succ;
	return p->data;
}
template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const {
	while (0 < n--)
		if (e == (p = p->pred)->data)return p;
	return NULL;
}
template <typename T> ListNodePosi(T) List<T>::insertAsFirst ( T const& e )
{
	_size++;
	return header->insertAsSucc(e);
}
template <typename T> ListNodePosi(T) List<T>::insertAsLast ( T const& e )
{
	_size++;
	return trailer->insertAsPred(e);
}
template <typename T> ListNodePosi(T) List<T>::insertA ( T const& e )
{
	_size++;
	return p->insertAsSucc(e);
}
template <typename T> ListNodePosi(T) List<T>::insertB ( T const& e )
{
	_size++;
	return p->insertAsPred(e);
}
template <typename T>
ListNodePosi(T) ListNode<T>:;insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this);
	pred->succ = x;
	pred = x;
	return x;
}
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this);
	pred->succ = x;pred = x;
	return x;
}
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
	ListNodePosi(T) x = new ListNode(e, succ, this);
	succ-> = x;succ = x;
	return x;
}
template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
	init;
	while (n--) { insertAsLast(p->data); p = p->succ; }
}
template <typename T>
List<T>:;List(ListNodePosi(T) p, int n) { copyNodes(p, n); }

template <typename T>
List<T>::List(List<T> const& L) { copyNodes(L.first(), L.size); }

template <typename T>
List<T>::List(List<T> const& L, int r, int n) { copyNodes(L[r], n); }
//删除
template <typename T> T List<T>::remove(ListNodePosi(T) p) {
	T e = p->data;
	p->pred->succ = p->succ;p->succ->pred = p->pred;
	delete p;size--;
	return e;
}
//析构函数
template <typename T> List<T>::~List()
{
	clear();
	delete header;
	delete trailer;
}
//列表清空方法
template <typename T> int List<T>::clear() {
	int oldSize = _size;
	while (0 < _size) remove(header->succ);
	return oldSize;
} 
//唯一化
template <typename T> int List<T>::deduplicate() {
	if (_size < 2) return 0;
	int oldSize = _size;
	ListNodePosi(T) p = header;Rank r = 0;
	while (trailer != (p = p->succ)) {
		ListNodePosi(T) q = find(p->data, r, p);
		q ? remove(q) : r++;
	}
	return oldSize - _size;
}
//遍历
template <typename T> void List<T>::traverse(void (*visit) (T&))//借助函数指针遍历
{
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}
template <typename T> template <typename VST>
void List<T>::traverse ( VST& visit )
{
	for (LisrNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);//借助函数对象机制遍历
}
//唯一化
template <typename T> int List<T>::uniquify() {
	if (_size < 2) return 0;
	int oldSize = _size;
	ListNodePosi(T) p = first(); ListNodePosi(T) q;
	while (trailer != (q = p->succ))
		if (p->data != q->data) p = q;
		else remove(q);
	return oldSize - _size;
}
//查找
template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const {
	// assert: 0 <= n <= rank(p) < _size
	while (0 <= n--)
		if (((p = p->pred)->data) <= e) break;
	return p;
}
//排序器
//有序列表基于排序的构造方法
template <typename T> void List<T>::sort(ListNodePosi(T) p, int n) {
	switch (rand() % 3) {
	case 1: insertionSort(p, n); break;//插入排序
	case 2: insertionSort(p, n); break;//选择排序
	default: mergeSort(p, n); break;//归并排序
	}
}
//插入排序
template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n) {
	for (int r = 0; r < n; r++) {
		insertA(search(p->data, r, p), p->data);
		p = p->succ;remove(p->pred);
	}
}
//选择排序
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n) {
	ListNodePosi(T) head = p->pred;ListNodePosi(T) tail = p;
	for (int i = 0; i < n; i++) tail = tail->succ;
	while (1 < n) {
		ListNodePosi(T) max = selectMax(head->succ, n);
		insertB(tail, remove(max));
		tail = tail->pred;n--;
	}
}
//列表最大节点的定位
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) {
	ListNodePosi(T) max = p;
	for (ListNodePosi(T) cur = p; 1 < n; n--)
		if (!lt((cur = cur->succ)->data, max->data))
			max = cur;
	return max;
}
//归并排序