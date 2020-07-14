class Solution {
	public boolean binarySearch(int[] array, int target) {
		int head = 0;
		int tail = array.length - 1;
		int middle = (head + tail) / 2;
		while(head <= tail) {
			middle = (head + tail) / 2;
			if(array[middle] == target) {
				return true;
			}
			else if(array[middle] < target) {
				head = middle + 1;
			}
			else {
				tail = middle - 1;
			}
		}
		return false;
	}
	
	public boolean findNumberIn2DArray(int[][] matrix, int target) {
		int n = matrix.length;
		for(int i = 0; i < n; i ++) {
			int[] array = matrix[i];
			boolean result = binarySearch(array, target);
			if(result == true) {
				return true;
			}
		}
		return false;
	}
}