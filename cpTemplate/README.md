# data structure
(1)Array\
(2)String\
(3)linked list\
(4)stack\
(5)Queue\
(6)Bst
- no duplicates
- inorder-> sorted elements

(7)Heap
- complete binary tree\
Min heap->\
make an empty array insert element at end then heapify . In heapify process elements from the bottom of the tree(element at the end of array here) are replaced with the parent if it less than parent element.For deletion copy  the top element of the tree(front element of array ) to a variable.Move the bottom right most element of the tree to the top of the tree.Then heapify the tree downwards.During heapify check if element is greater than child element then swap them else don't.

(8)Hashing
  - chaining(array of linked list)
  - prime number and array
  - double hashing.
  
(9)Segment tree
  - 2*n-1 elements but for ease of implementation take 2*n elements.later n elements are array elements and first n elements are a[i<<1]+a[i<<1|1].
  - for update given an index ind make it ind+n then update element and update all successive parent elements.
  - to return answer to query update l to l+n and r to r+n and if l is odd then add to sum and increment l, if r is odd then decrement r and add element to sum. progressively make l and r as the parent(l>>=1 and r>>=1).

(10)Trie

(11)Fenwick Tree(Binary indexed tree)

(12)Graph

(13)Suffix Array and suffix tree

(14)Self balancing BST

(15)K dimensional tree

(16)Disjoint set

(17)N-ary tree and LCA


