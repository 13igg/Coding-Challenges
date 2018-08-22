//https://leetcode.com/problems/add-two-numbers/description/
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let l3 = new ListNode(0);
    let node = l3;
    let carry = 0;
    while(l1 || l2){
        let l1Val = l1?l1.val:0;
        let l2Val = l2?l2.val:0;
        let sum = l1Val+l2Val+carry;
        
        carry = Math.floor(sum/10)
        sum = sum % 10;
        
        node.next = new ListNode(sum);
        node = node.next;
        
        if(l1) l1 = l1.next;
        if(l2) l2 = l2.next;
    }
    if (carry > 0) node.next = new ListNode(carry);
    return l3.next;
};