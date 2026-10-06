Comparison Between  CUSTOM and  STL

========================================
       BASIC USAGE OF CUSTOM DS
========================================

Vector: 10 20 30 
LinkedList front: Tanmay
Stack top: 30
Queue front: 100

========================================
       CUSTOM vs STL PERFORMANCE
========================================

===== VECTOR COMPARISON =====
Custom Vector push_back : 3.4894 ms
STL Vector push_back    : 4.61478 ms

===== LINKED LIST COMPARISON =====
Custom LinkedList push_back : 27.6669 ms
STL List push_back          : 28.4852 ms

===== STACK COMPARISON =====
Custom Stack push : 3.76064 ms
STL Stack push    : 2.86744 ms

===== QUEUE COMPARISON =====
Custom Queue push : 28.0072 ms
STL Queue push    : 3.15986 ms

========================================
          TIME COMPLEXITY
========================================

Vector:
  push_back : O(1) amortized
  pop_back  : O(1)
  access    : O(1)

LinkedList:
  push_front : O(1)
  push_back  : O(1)
  pop_front  : O(1)
  search     : O(n)

Stack:
  push : O(1) amortized
  pop  : O(1) amortized
  top  : O(1)

Queue:
  push  : O(1)
  pop   : O(1)
  front : O(1)
