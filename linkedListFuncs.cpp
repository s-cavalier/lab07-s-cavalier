#include "linkedListFuncs.h"
#include <stddef.h>
#include <iostream>

using namespace std;

/*All functions MUST be implemented recursively
* No credit will be given for non-recursive solutions
*/


//head: ptr to a Node * which is the head of a linked list
//return sum of all values in linked list using a recursive approach
//if head is null return 0
int recursiveSum(Node* head) {
  if (head->next == NULL)
    return head->data;

  return recursiveSum(head->next) + head->data;
}


//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) {
    if (head->next == NULL) return head->data;
    int kick = recursiveLargestValue(head->next);
    if (kick < head->data) return head->data;
    return kick;
}


/*Given the head of a linked list, find and return the kth node of the linked list
 *Assume head is the first node
 *If k is larger than the size of the linked list, return NULL
 *
 * Example: n1 -> n2 -> n3 -> n4 -> n5, k = 3
 * Return &n3
 */
Node* recursiveFindKthNode(Node *head, int k){
    if (k < 1 || head == NULL) return NULL;
    if (k == 1) return head;
    return recursiveFindKthNode(head->next, k - 1);
}


/*Given the head of a linked list, delete the kth node from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n2 and return &n1
* New list should look like this: n1 -> n3 -> n4
*/
Node* recursiveDeleteKthNode(Node *head, int k) {
    if (k == 1) {
        Node* next = head->next;
        delete head;
        return next;
    }

    head->next = recursiveDeleteKthNode(head->next, k - 1);
    return head;
}


/*Given the head of a linked list, delete the first k nodes from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n1, n2 and return &n3
*/
Node* recursiveRemoveKFromFront(Node *head, int k) {
    if (k == 1) {
        Node* next = head->next;
        delete head;
        return next;
    };

    Node* out = recursiveRemoveKFromFront(head->next, k - 1);
    delete head;
    return out;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}


/*Given two linked lists, return a NEW linked-list where each element is the sum of the corresponding elements of the input
 * If a linked list has a longer length than the other, treat the corresponding NULL element as a node with value 0
 * 
 * Example: List 1: 1 -> 2 -> 3 -> 12
 * 	    List 2: 4 -> 5 -> 6
 * Return &head of the linked list 5 -> 7 -> 9 -> 12
 */
Node* recursiveElementwiseSum(Node *head1, Node *head2) {
    if (head1 == NULL && head2 == NULL)
        return NULL;
    Node* kick = new Node();
    if (head1 != NULL && head2 != NULL) {
        kick->data = head1->data + head2->data;
        kick->next = recursiveElementwiseSum(head1->next, head2->next);
    }
    else if (head1 != NULL) {
        kick->data = head1->data;
        kick->next = recursiveElementwiseSum(head1->next, NULL);
    }
    else if (head2 != NULL) {
        kick->data = head2->data;
        kick->next = recursiveElementwiseSum(NULL, head2->next);
    }
    if (kick == NULL) return 0;
    return kick;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}


/*BONUS: Given the heads of two linked lists, splice the second linked list into the first, alternating elements from each list
 * 
 * The first element of the newly arranged linked list will always be head1, unless head1 is NULL (in which case just return head2)
 *
 * You MUST modify the linked lists themselves and DO NOT create another list or any new nodes
 *
 * Example: List 1: 1->2->3, List 2: 4 -> 5 -> 6
 * Return &head of 1 -> 4 -> 2 -> 5 -> 3 -> 6
 */
Node* recursiveSplice(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    if (head1->next == NULL) {
        head1->next = head2;
        return head1;
    }
    Node* kick = recursiveSplice(head1->next, head2->next);
    head1->next = head2;
    head1->next->next = kick;
    return head1;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}
