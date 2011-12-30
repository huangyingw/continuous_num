public class continuous_num {
	static char[] GetSubString(char[] strSource) {
		int iHead = 0, iMax = 0;
		int Index = 0, iLen = 0, nav = 0;
		while (Index < strSource.length) {
			iLen = 1;
			nav = Index;
			while (nav < strSource.length && strSource[nav] >= '0'
					&& strSource[nav] <= '9' && strSource[nav - 1] > '0'
					&& strSource[nav] == strSource[nav - 1] + 1) {
				iLen++; // 连续数字的长度增1
				nav++;
			}
			if (iMax < iLen) {
				iMax = iLen;
				iHead = Index - 1;
			}
			Index++;
		}
		char[] strResult = new char[iMax];
		for (int i = 0; i < iMax; i++) {
			// 将原字符串中最长的连续数字串赋值给结果串
			strResult[i] = strSource[iHead++];
		}
		return strResult; // 返回连续数字的最大长度
	}

	public static void main(String arg[]) {
		char[] strSource = "ads3sl456789DF3456ld345AA".toCharArray();
		char[] result = GetSubString(strSource);
		System.out.println(result);

		char strSource1[] = "ads3sl456789DF23456789".toCharArray();
		result = GetSubString(strSource1);
		System.out.println(result);

	}
}
