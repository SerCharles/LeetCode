class Solution {
	boolean[] hashTable;
	public int findRepeatNumber(int[] nums) {
		int n = nums.length;
		hashTable = new boolean[n];
		for(int i = 0; i < n; i ++) {
			hashTable[i] = false;
		}
		for(int i = 0; i < n; i ++) {
			int num = nums[i];
			if(hashTable[num] == true) {
				return num;
			}
			hashTable[num] = true;
		}
		return -1;
	}
	
	
}