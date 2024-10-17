typedef int Rank;
include <cstddef>
#define ListNodePosi(T) ListNode<T>*
template <typename T> struct ListNode {
	T data; ListNode(T) pred; ListNodePosi(T) succ;
	//构造函数
	ListNode() {}
	ListNode( T e, ListNode(T) p = NULL, ListNode(T) s = NULL )
	   : data ( e ), pred ( p ), succ ( s ) {}
	//操作接口
	ListNode(T) insertAsPred ( T const& e );
	ListNode(T) insertAsSucc ( T const& e );
};

#ifndef DS2024A_LISTNODE_H
#define DS2024A_LISTNODE_H

#endif //DS2024A_LISTNODE_H
//xiaodu