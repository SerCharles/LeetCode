class Solution {
	public String replaceSpace(String s) {
		String result = "";
		for(int i = 0; i < s.length(); i ++) {
			char a = s.charAt(i);
			if(a == ' ') {
				result = result + "%20";
			}
			else {
				result = result + ("" + a);
			}
		}
		return result;
	}
}