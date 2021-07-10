class Solution {
public:
	bool sumGame(string num) {
		int leftSum = 0, rightSum = 0, leftQuestions = 0, rightQuestions = 0;
		int n = num.size();
		for (int i = 0; i < n / 2; i++) {
			if (num[i] != '?') leftSum += (num[i] - '0');
			leftQuestions += num[i] == '?';
		}
		for (int i = n - 1; i >= n / 2; i--) {
			if (num[i] != '?') rightSum += (num[i] - '0');
			rightQuestions += num[i] == '?';
		}
		int maxQuestions =  max(leftQuestions, rightQuestions);
		int minQuestions =  min(leftQuestions, rightQuestions);
		int questionsLeft = maxQuestions - minQuestions;
		int difference;
		int canMake;
		if (questionsLeft) {
			canMake = 9 * (questionsLeft / 2);
			if (leftSum < rightSum && maxQuestions == leftQuestions) {
				difference = rightSum - leftSum;
			} else if (leftSum > rightSum && maxQuestions == rightQuestions) {
				difference = -rightSum + leftSum;
			} else {
				return true;
			}
			return !(difference == canMake && questionsLeft % 2 == 0);
		}
		return leftSum != rightSum;
	}
};