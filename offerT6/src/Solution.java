/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {
	public int[] reversePrint(ListNode head) {
		int[] stack;
		int length = 0;
		stack = new int[10000];
		while(head != null) {
			int num = head.val;
			stack[length] = num;
			length ++;
			head = head.next;
		}
		int[] result = new int[length];
		for(int i = 0; i < length; i ++) {
			result[i] = stack[length - i - 1];
		}
		return result;
	}
}